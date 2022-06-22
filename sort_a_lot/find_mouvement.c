/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mouvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:33 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:28:58 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_mouvement(struct s_mNode *head)
{
	ft_stepn_a(head);
	ft_stepn_b(head);
}

void	find_minimum_move(struct s_mNode *head)
{
	struct s_stack	*a_decoy;
	struct s_stack	*b_decoy;

	head->mouvement = -1;
	a_decoy = head->a;
	b_decoy = head->b;
	while (head->b)
	{
		head->mouvement = ft_aquire_place(head);
		head->a = a_decoy;
		if (head->mouvement == 0)
			break ;
		head->b = head->b->next;
	}
	head->b = b_decoy;
}

void	ft_help_aquire_place(struct s_mNode *head)
{
	while (head->a)
	{
		head->buffer = head->a->data;
		if (head->b->data > head->a->data)
		{
			head->action++;
			if (head->b->data < head->a->next->data)
				break ;
			head->a = head->a->next;
		}
		else
			break ;
	}
	if (is_there_next_min(head))
	{
		while (head->a)
		{
			if (head->a->data < head->buffer && head->a->data > head->b->data)
				break ;
			head->action++;
			head->a = head->a->next;
		}
	}
}

static int	add_mouvement(struct s_mNode *head)
{
	head->move_a = head->a->rotate;
	head->move_b = head->b->rotate;
	head->count_a = head->action;
	head->count_b = head->b->move;
	return (head->action + head->b->move);
}

int	ft_aquire_place(struct s_mNode *head)
{
	head->action = 0;
	head->buffer = 0;
	ft_help_aquire_place(head);
	if (head->a->rotate == -1)
		head->action = head->len_a - head->action;
	if (head->mouvement == -1
		|| (head->action + head->b->move) < head->mouvement)
		return (add_mouvement(head));
	return (head->mouvement);
}
