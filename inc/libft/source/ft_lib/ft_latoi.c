/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:06:28 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 15:59:18 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"

static int	ft_isspace(char chr)
{
	if ((chr >= 9 && chr <= 13) || chr == ' ')
		return (1);
	return (0);
}

static int	ft_isaret(char c, int *index)
{
	int	isaret;

	isaret = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			isaret *= -1;
		*index += 1;
	}
	return (isaret);
}

long int	ft_latoi(const char *nptr)
{
	unsigned long	ret_val;
	int				index;
	int				isaret;

	index = 0;
	ret_val = 0;
	if (*nptr == '\0')
		return (0);
	while (ft_isspace(nptr[index]))
		index++;
	isaret = ft_isaret(nptr[index], &index);
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		ret_val = (ret_val * 10) + (nptr[index] - '0');
		index++;
	}
	if (ret_val > LONG_MAX)
	{
		if (isaret == -1)
			return (0);
		return (-1);
	}
	return (ret_val * isaret);
}
