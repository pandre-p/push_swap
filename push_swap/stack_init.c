/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:20:45 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/02 15:36:56 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(char **av, t_data **a)
{
	int	i;

	i = 0;
	while (av[i])
	{
		ft_push(a, create_node(ft_atol(av[i])));
		rotate(a, 3);
		i++;
	}
}

void	free_list(t_data **target)
{
	t_data	*next;
	t_data	*current;

	if (!target || !(*target))
		return ;
	current = *target;
	while (current->next != *target)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
	*target = NULL;
}

t_data	*create_node(int data)
{
	t_data	*new_node;

	new_node = (t_data *)malloc(sizeof(t_data) * 1);
	if (!new_node)
		return (NULL);
	new_node->number = data;
	return (new_node);
}
