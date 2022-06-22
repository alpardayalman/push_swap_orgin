/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:24 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 18:01:55 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
// Sorts the s_stack immediatly.

void	insert_at_bottom(struct s_stack **top_ref, int *item)
{
	int	*temp;

	if (is_empty(*top_ref))
		push(top_ref, item[0], item[1], item[2]);
	else
	{
		temp = pop(top_ref);
		insert_at_bottom(top_ref, item);
		push(top_ref, temp[0], temp[1], temp[2]);
		free(temp);
	}
}

void	free_list(struct s_stack *head)
{
	struct s_stack	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		tmp->next = NULL;
		free(tmp);
	}
}
