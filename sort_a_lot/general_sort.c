/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:39 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:24:38 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
/*
-- A'da min ve max kalana kadar B'ye atiyoruz.
-- B'ye atilan median'dan buyukse asagi gonderiliyor.
-- Kucukse yukarda kaliyor.
-- A'da sadece min ve max kaldiginda b'nin en ustundeki a'ya gonderiliyor.
*/
struct s_mNode	*general_sort_baby(struct s_mNode *head)
{
	while (head->len_a > 2)
		ft_prepere_stacks(head);
	if (head->a->data < head->a->next->data)
		swap_a(head);
	push_a(head);
	ft_commence(head);
	return (head);
}

void	ft_prepere_stacks(struct s_mNode *head)
{
	if (head->a->data != head->min && head->a->data != head->max)
	{
		push_b(head);
		if (head->b->data > head->med && head->count_b != 1)
			rotate_b(head);
	}
	else
		rotate_a(head);
}

static void	reset_head(struct s_mNode *head)
{
	head->count_a = -1;
	head->count_b = -1;
	head->move_a = 0;
	head->move_b = 0;
}

/*
-- Minimum sona daha yakinsa rra, basa daha yakinsa ra yapiliyor.
*/
static void	ft_retouche(struct s_mNode *head)
{
	if (count_min_index(head) > head->len_a / 2)
	{
		while (head->a->data != head->min)
			reverse_rotate_a(head);
	}
	else
		while (head->a->data != head->min)
			rotate_a(head);
}

/*
-- Genel loop'umuz rekursif bir sekilde b bosalana kadar calisiyor.
*/
void	ft_commence(struct s_mNode *head)
{
	if (head->len_b != 0)
	{
		reset_head(head);
		ft_mouvement(head);
		find_minimum_move(head);
		do_instruct(head);
		push_a(head);
		ft_commence(head);
	}
	else
	{
		ft_retouche(head);
		return ;
	}
}
