/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:34:48 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 18:07:42 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	is_no(char *a)
{
	int	i;

	i = 0;
	if (a[0] == '-')
		i++;
	while (a[i])
	{
		if (!(a[i] >= '0' && a[i] <= '9'))
			ft_exit_fail();
		i++;
	}
}

void	is_min_max(char *a)
{
	long int	b;

	b = ft_latoi(a);
	if (b > 2147483647 || b < -2147483648)
		ft_exit_fail();
}

void	o_n_checker(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		is_min_max(av[i]);
		is_no(av[i]);
		i++;
	}
}

void	ft_exit_fail(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_kill(struct s_mNode *head)
{
	free_list(head->a);
	free_list(head->b);
	deallocate(head->tree);
	free(head);
	exit(EXIT_SUCCESS);
}
