/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:03:01 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/07 11:03:30 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_pop(t_data	**head)
{
	t_data		*first;
	t_data		*last;

	if (*head == NULL)
		return (NULL);
	first = *head;
	if (first->next == first)
		*head = NULL;
	else
	{
		last = first->prev;
		*head = first->next;
		(*head)->prev = last;
		last->next = *head;
	}
	return (first);
}

void	ft_push(t_data	**head, t_data	*new_node)
{
	t_data	*last;

	if (*head == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
	}
	else
	{
		last = (*head)->prev;
		last->next = new_node;
		new_node->next = *head;
		new_node->prev = last;
		(*head)->prev = new_node;
		(*head) = new_node;
	}
}

int	stack_len(t_data	**target)
{
	t_data	*first;
	int		i;
	t_data	*corrent;

	if (*target == NULL)
		return (0);
	first = *target;
	corrent = first;
	i = 1;
	while (corrent->next != first)
	{
		corrent = corrent->next;
		i++;
	}
	return (i);
}

int	stack_sorter(t_data	**target)
{
	t_data	*current;
	t_data	*start;

	current = *target;
	start = current;
	if (current->next == current)
		return (1);
	while (current->next != start)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

t_data	*find_highest(t_data	*stack)
{
	long	highest;
	t_data	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest = stack->number;
	highest_node = stack;
	stack = stack->next;
	while (stack->number != highest)
	{
		if (stack->number > highest)
		{
			highest = stack->number;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}
