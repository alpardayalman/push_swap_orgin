/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:50 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 16:59:33 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static struct s_mNode	*m_node_init(void)
{
	struct s_mNode	*head;

	head = (struct s_mNode *)malloc(sizeof(struct s_mNode));
	if (head == NULL)
		exit(1);
	head->a = NULL;
	head->b = NULL;
	head->tree = NULL;
	head->len_a = 0;
	head->len_b = 0;
	head->max = 0;
	head->min = 0;
	head->med = 0;
	head->count_a = 0;
	head->count_b = 0;
	head->move_a = 0;
	head->move_b = 0;
	head->action = 0;
	head->mouvement = -1;
	head->buffer = 0;
	return (head);
}

void	prime_create(struct s_mNode *head, int ac, char **av)
{
	int	i;
	int	a;

	head->len_a = ac - 1;
	i = head->len_a;
	while (i > 0)
	{
		a = ft_atoi(av[i]);
		head->tree = insert(head, head->tree, a);
		push(&head->a, a, 0, 0);
		i--;
	}
	head->min = find_min_value(head->tree);
	head->max = find_max_value(head->tree);
	head->med = find_median(head->tree);
}

static struct s_mNode	*sort_major(struct s_mNode *head)
{
	if (head->len_a < 4)
		return (sort3(head));
	else if (head->len_a < 6)
		return (sort5(head));
	else
		return (general_sort_baby(head));
}

int	main(int ac, char **av)
{
	struct s_mNode	*head;

	head = m_node_init();
	if (ac < 2)
		exit(EXIT_FAILURE);
	o_n_checker(ac, av);
	prime_create(head, ac, av);
	if (checker(head->a))
		ft_kill(head);
	head = sort_major(head);
	ft_kill(head);
	return (1);
}
