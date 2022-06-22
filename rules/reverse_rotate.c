/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:09 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:28:07 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate_a(struct s_mNode *head)
{
	struct s_stack	*decoy;
	struct s_stack	*prev;

	prev = NULL;
	decoy = head->a;
	while (decoy->next)
	{
		prev = decoy;
		decoy = decoy->next;
	}
	decoy->next = head->a;
	head->a = decoy;
	prev->next = NULL;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(struct s_mNode *head)
{
	struct s_stack	*decoy;
	struct s_stack	*prev;

	decoy = head->b;
	prev = NULL;
	while (decoy->next)
	{
		prev = decoy;
		decoy = decoy->next;
	}
	decoy->next = head->b;
	head->b = decoy;
	prev->next = NULL;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_all(struct s_stack **a)
{
	struct s_stack	*decoy;
	struct s_stack	*prev;

	decoy = *a;
	prev = NULL;
	while (decoy->next)
	{
		prev = decoy;
		decoy = decoy->next;
	}
	decoy->next = *a;
	*a = decoy;
	prev->next = NULL;
}

void	reverse_rotate_rrr(struct s_mNode *head)
{
	reverse_rotate_all(&head->a);
	reverse_rotate_all(&head->b);
	write(1, "rrr\n", 4);
}
