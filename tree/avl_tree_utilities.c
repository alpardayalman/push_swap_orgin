/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:54 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:25:56 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	max_num(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

struct s_duplicate	*min_value(struct s_duplicate *node)
{
	struct s_duplicate	*current;

	current = node;
	while (current->left)
		current = current->left;
	return (current);
}

int	find_min_value(struct s_duplicate *node)
{
	struct s_duplicate	*current;

	current = node;
	while (current->left)
		current = current->left;
	return (current->key);
}

int	find_max_value(struct s_duplicate *node)
{
	struct s_duplicate	*current;

	current = node;
	while (current->right)
		current = current->right;
	return (current->key);
}
