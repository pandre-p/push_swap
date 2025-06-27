/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:33:45 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/04 13:41:54 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker1(char	**av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!(error_checker(av[i])))
			return (1);
		i++;
	}
	if (i < 2 || (!(equal_numbers(av, 1))))
		return (write(2, "Error\n", 6), 1);
	return (0);
}

int	checker2(int ac, char	**av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!(error_checker(av[i])))
		{
			free_words(av);
			return (1);
		}
		i++;
	}
	if (i < 1 || (!(equal_numbers(av, 0))))
	{
		if (ac == 2)
			free_words(av);
		return (write(2, "Error\n", 6), 1);
	}
	return (0);
}
