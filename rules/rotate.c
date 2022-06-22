/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:16 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 18:11:12 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_a(struct s_mNode *head)
{
	int	*temp;

	if (!is_empty(head->a))
	{
		temp = pop(&head->a);
		insert_at_bottom(&head->a, temp);
		free(temp);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(struct s_mNode *head)
{
	int	*temp;

	if (!is_empty(head->b))
	{
		temp = pop(&head->b);
		insert_at_bottom(&head->b, temp);
		free(temp);
	}
	write(1, "rb\n", 3);
}

void	rotate_all(struct s_stack **a)
{
	int	*temp;

	if (!is_empty(*a))
	{
		temp = pop(a);
		insert_at_bottom(a, temp);
		free(temp);
	}
}

void	rotate_rr(struct s_mNode *head)
{
	rotate_all(&head->a);
	rotate_all(&head->b);
	write(1, "rr\n", 3);
}
