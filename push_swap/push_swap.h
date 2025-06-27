/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:46:44 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/04 13:12:23 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "stdbool.h"

typedef struct s_data
{
	long			number;
	long			index;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

char			**ft_split(char *str);
int				checker1(char **av);
void			index_one(int len, t_data *a_node, t_data **a, t_data **b);
void			push_or_rotate(t_data **a, t_data **b, int i);
void			process_list(t_data **a, t_data **b, int i);
int				checker2(int ac, char **av);
int				error_checker(char *n);
void			list(int ac, char	**av, t_data **a, t_data **b);
void			free_words(char **words);
void			stack_init(char **av, t_data **a);
void			free_list(t_data **target);
long			ft_atol(const char *str);
void			ft_push(t_data **head, t_data *new_node);
t_data			*create_node(int data);
t_data			*ft_pop(t_data **head);
void			swap(t_data **target, int i);
void			rrotate(t_data **target, int i);
void			rotate(t_data **target, int i);
void			push(t_data **dest, t_data **src, int i);
void			two_swaps(t_data **tgone, t_data **tgtwo);
void			rrr(t_data **tgone, t_data **tgtwo);
void			rr(t_data **tgone, t_data **tgtwo);
int				stack_len(t_data **target);
int				stack_sorter(t_data **target);
int				equal_numbers(char **av, int i);
void			create_index(t_data **target);
void			radix_short(t_data **a, t_data **b);
void			tiny_sort(t_data **a);
void			medium_sort(t_data **a, t_data **b);
void			index_zero(t_data *a_node, t_data **a, t_data **b);
void			index_one(int len, t_data *a_node, t_data **a, t_data **b);
t_data			*find_highest(t_data *stack);
int				bit_find(long n, char a, int i);
char			*ltobit(long n);
//TEST
//void			print_stack(t_data *a, int ac);
#endif