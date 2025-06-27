/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:11:09 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/04 13:33:25 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(int c)
{
	return (c >= '0' && c <= '9');
}

int	error_checker(char	*n)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atol(n);
	if (n[i] == '-' || n[i] == '+')
		i++;
	if (n[i] == '\0')
		return (write(2, "Error\n", 6), 0);
	while (n[i])
	{
		if (!ft_isnumber(n[i]))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	if (num < -2147483648 || num > 2147483647)
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	equal_numbers(char	**av, int i)
{
	int	j;

	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[j]) == ft_atol(av[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
