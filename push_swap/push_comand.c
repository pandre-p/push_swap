/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_comand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:49:39 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/02 15:59:36 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_data	**dest, t_data	**src, int i)
{
	t_data	*value;

	value = ft_pop(src);
	ft_push(dest, value);
	if (i == 1)
		write(1, "pa\n", 3);
	if (i == 2)
		write(1, "pb\n", 3);
}
