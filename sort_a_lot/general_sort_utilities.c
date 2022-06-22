/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort_utilities.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:36 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:28:00 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_stepn_b(struct s_mNode *head)
{
	int				i;
	int				avg;
	struct s_stack	*decoy;

	i = -1;
	avg = head->len_b / 2;
	decoy = head->b;
	while (++i <= avg)
	{
		decoy->move = i;
		decoy->rotate = 1;
		decoy = decoy->next;
	}
	if (head->len_b % 2 == 0)
		i--;
	while (--i > 0)
	{
		decoy->move = i;
		decoy->rotate = -1;
		decoy = decoy->next;
	}
}

void	ft_stepn_a(struct s_mNode *head)
{
	int				i;
	int				avg;
	struct s_stack	*decoy;

	i = -1;
	avg = head->len_a / 2;
	decoy = head->a;
	while (++i <= avg)
	{
		decoy->move = i;
		decoy->rotate = 1;
		decoy = decoy->next;
	}
	if (head->len_a % 2 == 0)
		i--;
	while (--i > 0)
	{
		decoy->move = i;
		decoy->rotate = -1;
		decoy = decoy->next;
	}
}

bool	is_there_next_min(struct s_mNode *head)
{
	struct s_stack	*decoy;

	decoy = head->a;
	while (decoy)
	{
		if (decoy->data < head->buffer && decoy->data > head->b->data)
			return (true);
		decoy = decoy->next;
	}
	return (false);
}

int	count_min_index(struct s_mNode *head)
{
	struct s_stack	*decoy;
	int				index;

	decoy = head->a;
	index = 0;
	while (decoy)
	{
		if (decoy->data == head->min)
			break ;
		decoy = decoy->next;
		index++;
	}
	return (index);
}
