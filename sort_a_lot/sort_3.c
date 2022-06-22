/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:46 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:27:52 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	lastpeek(struct s_stack **node)
{
	struct s_stack	*new;
	int				b;

	new = *node;
	while (new->next)
		new = new->next;
	b = new->data;
	return (b);
}

bool	checker(struct s_stack *node)
{
	if (is_empty(node))
		exit(EXIT_FAILURE);
	if (node->next == NULL)
		return (true);
	if (node->data > node->next->data)
		return (false);
	else
		return (checker(node->next));
}

struct s_mNode	*sort3(struct s_mNode *node)
{
	if (checker(node->a))
		return (node);
	if (node->a->data < node->a->next->data
		&& node->a->data > lastpeek(&node->a))
		reverse_rotate_a(node);
	else if (node->a->data > lastpeek(&node->a)
		&& node->a->next->data < lastpeek(&node->a))
		rotate_a(node);
	else
		swap_a(node);
	return (sort3(node));
}

struct s_mNode	*sort5(struct s_mNode *node)
{
	while (node->len_b < 2)
	{
		if (node->a->data == node->min || node->a->data == node->max)
			push_b(node);
		else
			rotate_a(node);
	}
	sort3(node);
	push_a(node);
	push_a(node);
	if (node->a->data == node->max)
		rotate_a(node);
	else
	{
		swap_a(node);
		rotate_a(node);
	}
	return (node);
}
