/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:54:02 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/02 16:04:40 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	count_smaller(t_data	*list, t_data	*current)
{
	long	count;
	t_data	*temp;

	count = 0;
	temp = list;
	while (1)
	{
		if (temp->number < current->number)
			count++;
		temp = temp->next;
		if (temp == list)
			break ;
	}
	return (count);
}

void	create_index(t_data	**target)
{
	t_data	*temp;

	temp = *target;
	while (temp)
	{
		temp->index = count_smaller(*target, temp);
		temp = temp->next;
		if (temp == *target)
			break ;
	}
}
