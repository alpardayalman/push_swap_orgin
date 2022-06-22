/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:21 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:28:21 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	peek(struct s_stack *top)
{
	return (top->data);
}

bool	is_empty(struct s_stack *top)
{
	if (top == NULL)
		return (true);
	return (false);
}

void	push(struct s_stack **top_ref, int new_data, int move, int rotate)
{
	struct s_stack	*new_node;

	new_node = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (new_node == NULL)
		exit(0);
	new_node->data = new_data;
	new_node->rotate = rotate;
	new_node->move = move;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

int	*pop(struct s_stack **top_ref)
{
	struct s_stack	*top;
	int				*res;

	res = malloc(sizeof(int) * 3);
	if (!res)
		exit(1);
	if (*top_ref == NULL)
		exit(0);
	else
	{
		top = *top_ref;
		res[0] = top->data;
		res[1] = top->move;
		res[2] = top->rotate;
		*top_ref = top->next;
		free(top);
		return (res);
	}
}
