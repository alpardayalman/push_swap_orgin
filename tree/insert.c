/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:38:03 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 18:08:33 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

struct s_duplicate	*new_tree_node(int key)
{
	struct s_duplicate	*node;

	node = (struct s_duplicate *)malloc(sizeof(struct s_duplicate));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	deallocate(struct s_duplicate *node)
{
	if (node == NULL)
		return ;
	deallocate(node->left);
	deallocate(node->right);
	free(node);
}

struct s_duplicate	*insert(struct s_mNode *head,
								struct s_duplicate *node, int key)
{
	if (node == NULL)
		return (new_tree_node(key));
	if (key < node->key)
		node->left = insert(head, node->left, key);
	else if (key > node->key)
		node->right = insert(head, node->right, key);
	else
	{
		ft_printf("Error\n");
		ft_kill(head);
	}
	return (node);
}

// void inorder(struct s_duplicate *root)
// {
// 	if (root != NULL)
// 	{
// 		inorder(root->left);
// 		printf("%d ", root->key);
// 		inorder(root->right);
// 	}
// }

// void preorder(struct s_duplicate *root)
// {
// 	if (root != NULL)
// 	{
// 		printf("%d ", root->key);
// 		preorder(root->left);
// 		preorder(root->right);
// 	}
// }

// void postorder(struct s_duplicate *root)
// {
// 	if (root != NULL)
// 	{
// 		postorder(root->left);
// 		postorder(root->right);
// 		printf("%d ", root->key);
// 	}
// }
