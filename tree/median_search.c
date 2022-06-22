/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:38:07 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:25:41 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	counter(struct s_duplicate *root)
{
	if (root != NULL)
		return (counter(root->left) + counter(root->right) + 1);
	return (0);
}

void	get_elements(struct s_duplicate *root, int *auxiliary, int *index)
{
	if (root != NULL)
	{
		get_elements(root->left, auxiliary, index);
		auxiliary[*index] += root->key;
		(*index)++;
		get_elements(root->right, auxiliary, index);
	}
}

int	find_median(struct s_duplicate *root)
{
	int	size;
	int	*auxiliary;
	int	index;
	int	result;

	if (root == NULL)
		return (0);
	size = counter(root);
	auxiliary = (int *)calloc(size, sizeof(int));
	index = 0;
	get_elements(root, auxiliary, &index);
	result = 0;
	if (size % 2 != 0)
	{
		index = (size) / 2;
		result = auxiliary[index];
	}
	else
		result = (auxiliary[(size - 1) / 2]);
	free(auxiliary);
	auxiliary = NULL;
	return (result);
}
