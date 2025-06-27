/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:59:15 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/07 11:04:20 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_short(t_data **a, t_data **b)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(a);
	create_index(a);
	while (!stack_sorter(a))
	{
		process_list(a, b, i);
		while (stack_len(a) != len)
			push(a, b, 1);
		i++;
	}
}

void	tiny_sort(t_data	**a)
{
	t_data	*h_node;

	h_node = find_highest(*a);
	if (*a == h_node)
		rotate(a, 1);
	else if ((*a)->next == h_node)
		rrotate(a, 1);
	if ((*a)->number > (*a)->next->number)
		swap(a, 1);
}

void	medium_sort(t_data	**a, t_data	**b)
{
	t_data	*a_node;
	int		len;

	len = stack_len(a);
	a_node = *a;
	create_index(a);
	index_zero(a_node, a, b);
	a_node = *a;
	index_one(len, a_node, a, b);
	tiny_sort(a);
	while (stack_len(a) != len)
		push(a, b, 1);
}

int	bit_find(long n, char a, int i)
{
	char	*b;
	int		s;

	s = 0;
	b = ltobit(n);
	while (b[s])
		s++;
	if (s < i)
		return (free(b), 0);
	if (b[i] == a)
		return (free(b), 1);
	return (free(b), 0);
}

char	*ltobit(long n)
{
	int		num_bits;
	int		i;
	char	*bit_str;

	num_bits = 32;
	i = 0;
	bit_str = (char *)malloc(num_bits + 1);
	if (!bit_str)
		return (NULL);
	bit_str[num_bits] = '\0';
	while (n > 0 && i < num_bits)
	{
		if (n & 1)
			bit_str[i] = '1';
		else
			bit_str[i] = '0';
		n >>= 1;
		i++;
	}
	while (i < num_bits)
		bit_str[i++] = '0';
	return (bit_str);
}
