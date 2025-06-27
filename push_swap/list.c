/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:56:38 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/04 14:55:41 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list(int ac, char	**av, t_data **a, t_data **b)
{
	stack_init(av, a);
	if (ac == 2)
		free_words(av);
	if (!stack_sorter(a))
	{
		if (stack_len(a) == 2)
			swap(a, 1);
		else if (stack_len(a) == 3)
			tiny_sort(a);
		else if (stack_len(a) == 4 || stack_len(a) == 5)
			medium_sort(a, b);
		else
			radix_short(a, b);
	}
	free_list(a);
}

void	index_zero(t_data *a_node, t_data **a, t_data **b)
{
	if (a_node->prev->index == 0)
	{
		rrotate(a, 1);
		push(b, a, 2);
		a_node = *a;
	}
	else if (a_node->prev->prev->index == 0)
	{
		rrotate(a, 1);
		rrotate(a, 1);
		push(b, a, 2);
		a_node = *a;
	}
	else
	{
		while (a_node->index != 0)
		{
			rotate(a, 1);
			a_node = *a;
		}
		push(b, a, 2);
	}
}

void	index_one(int len, t_data *a_node, t_data **a, t_data **b)
{
	if (len == 5)
	{
		if (a_node->prev->index == 1)
		{
			rrotate(a, 1);
			push(b, a, 2);
		}
		else
		{
			while (a_node ->index != 1)
			{
				rotate(a, 1);
				a_node = *a;
			}
			push(b, a, 2);
		}
	}
}

void	push_or_rotate(t_data **a, t_data **b, int i)
{
	long	node;

	node = (*a)->index;
	if (bit_find(node, '0', i))
		push(b, a, 2);
	else
		rotate(a, 1);
}

void	process_list(t_data **a, t_data **b, int i)
{
	t_data	*a_node;
	t_data	*last;

	a_node = *a;
	last = (*a)->prev;
	while (a_node != last)
	{
		push_or_rotate(a, b, i);
		a_node = *a;
	}
	push_or_rotate(a, b, i);
}
