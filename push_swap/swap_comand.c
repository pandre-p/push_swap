/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_comand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:08:35 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/02 15:28:26 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_data **target, int i)
{
	t_data	*first;
	t_data	*second;

	first = *target;
	second = (*target)->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	second->prev->next = second;
	*target = second;
	if (i == 1)
		write(1, "sa\n", 3);
	else if (i == 2)
		write(1, "sb\n", 3);
}

void	two_swaps(t_data **tgone, t_data **tgtwo)
{
	swap(tgone, 0);
	swap(tgtwo, 0);
	write(1, "ss\n", 3);
}
