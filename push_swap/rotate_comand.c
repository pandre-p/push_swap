/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_comand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:49:49 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/02 15:54:49 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_data	**target, int i)
{
	t_data	*first;
	t_data	*last;
	t_data	*second_last;

	first = *target;
	last = first->prev;
	second_last = last->prev;
	*target = last;
	(*target)->next = first;
	first->prev = *target;
	last->prev = second_last;
	second_last->next = *target;
	if (i == 1)
		write(1, "rra\n", 4);
	if (i == 2)
		write(1, "rrb\n", 4);
}

void	rotate(t_data	**target, int i)
{
	t_data	*head;
	t_data	*last;

	head = *target;
	last = head->prev;
	*target = head->next;
	head->next = *target;
	(*target)->prev = head;
	last->next = head;
	head->prev = last;
	if (i == 1)
		write(1, "ra\n", 3);
	if (i == 2)
		write(1, "rb\n", 3);
}

void	rrr(t_data	**tgone, t_data	**tgtwo)
{
	rrotate(tgone, 3);
	rrotate(tgtwo, 3);
	write(1, "rrr\n", 4);
}

void	rr(t_data	**tgone, t_data	**tgtwo)
{
	rotate(tgone, 3);
	rotate(tgtwo, 3);
	write(1, "rr\n", 3);
}
