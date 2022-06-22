/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_do.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:43 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:24:46 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	do_a(struct s_mNode *head)
{
	while (head->count_a > 0)
	{
		if (head->move_a == 1)
			rotate_a(head);
		else
			reverse_rotate_a(head);
		head->count_a--;
	}
}

static void	do_b(struct s_mNode *head)
{
	while (head->count_b > 0)
	{
		if (head->move_b == 1)
			rotate_b(head);
		else
			reverse_rotate_b(head);
		head->count_b--;
	}
}

static void	do_opt_rr(struct s_mNode *head)
{
	while (head->count_a > 0 || head->count_b > 0)
	{
		if (head->count_a > 0 && head->count_b > 0)
		{
			rotate_rr(head);
			head->count_a--;
			head->count_b--;
		}
		else if (head->count_a > 0)
		{
			rotate_a(head);
			head->count_a--;
		}
		else if (head->count_b > 0)
		{
			rotate_b(head);
			head->count_b--;
		}
	}
}

static void	do_opt_rrr(struct s_mNode *head)
{
	while (head->count_a > 0 || head->count_b > 0)
	{
		if (head->count_a > 0 && head->count_b > 0)
		{
			reverse_rotate_rrr(head);
			head->count_a--;
			head->count_b--;
		}
		else if (head->count_a > 0)
		{
			reverse_rotate_a(head);
			head->count_a--;
		}
		else if (head->count_b > 0)
		{
			reverse_rotate_b(head);
			head->count_b--;
		}
	}
}

// bitene kadar bu instruction'lari yapiyor.
void	do_instruct(struct s_mNode *head)
{
	if (head->move_b == head->move_a && head->count_a > 0 && head->count_b > 0)
	{
		if (head->move_a == 1)
			do_opt_rr(head);
		else
			do_opt_rrr(head);
	}
	else
	{
		do_a(head);
		do_b(head);
	}
}
