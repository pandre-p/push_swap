/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:51:06 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/02 19:20:34 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void print_stack(t_data *a, int ac)
{
	t_data *temp = a;
	int i = 0;
	while (i < ac)
	{
		printf("%ld\n", temp->number);
		temp = temp->next;
		i++;
	}
}*/
int	main(int ac, char	**av)
{
	t_data	*a;
	t_data	*b;
	int		c;

	c = 0;
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1]);
		c = checker2(ac, av);
		if (c == 1)
			return (1);
	}
	else
	{
		c = checker1(av);
		if (c == 1)
			return (1);
		av++;
	}
	list(ac, av, &a, &b);
}
