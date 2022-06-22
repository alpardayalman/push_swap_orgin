/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:28 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 18:03:56 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(struct s_mNode *main)
{
	int	*key;
	int	ret;

	if (is_empty(main->b))
		return (EXIT_FAILURE);
	key = pop(&main->b);
	main->len_b--;
	main->len_a++;
	push(&main->a, key[0], key[1], key[2]);
	ret = key[0];
	free(key);
	write(1, "pa\n", 3);
	return (ret);
}

int	push_b(struct s_mNode *main)
{
	int	*key;
	int	ret;

	if (is_empty(main->a))
		return (EXIT_FAILURE);
	key = pop(&main->a);
	main->len_a--;
	main->len_b++;
	push(&main->b, key[0], key[1], key[2]);
	ret = key[0];
	free(key);
	write(1, "pb\n", 3);
	return (ret);
}

int	swap_a(struct s_mNode *main)
{
	int	*key;
	int	*key_2;

	if (is_empty(main->a))
		return (0);
	key = pop(&main->a);
	if (is_empty(main->a))
	{
		push(&main->a, key[0], key[1], key[2]);
		return (1);
	}
	key_2 = pop(&main->a);
	push(&main->a, key[0], key[1], key[2]);
	push(&main->a, key_2[0], key_2[1], key_2[2]);
	free(key);
	free(key_2);
	write(1, "sa\n", 3);
	return (EXIT_SUCCESS);
}

int	swap_b(struct s_mNode *main)
{
	int	*key;
	int	*key_2;

	if (is_empty(main->b))
		return (0);
	key = pop(&main->b);
	if (is_empty(main->b))
	{
		push(&main->b, key[0], key[1], key[2]);
		return (1);
	}
	key_2 = pop(&main->b);
	push(&main->b, key[0], key[1], key[2]);
	push(&main->b, key_2[0], key_2[1], key_2[2]);
	free(key);
	free(key_2);
	write(1, "sb\n", 3);
	return (EXIT_SUCCESS);
}

int	swap_ss(struct s_mNode *main)
{
	swap_a(main);
	swap_b(main);
	write(1, "ss\n", 3);
	return (1);
}
