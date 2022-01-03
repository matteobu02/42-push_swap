/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:36:43 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/03 00:56:15 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stock
{
	int				val;
	int				index;
	struct s_stock	*next;
}	t_stock;

int		ft_count_links(t_stock *ptr);
int		get_eq_bin(int n);
void	clear_list(t_stock *ptr);
void	free_error(t_stock *a, t_stock *b);
void	free_and_close(char **tab, t_stock *ptr);
void	close_program(t_stock *a, t_stock *b);
void	get_stack(t_stock *a, int ac, char **args);
int		ft_atoi(char *str, t_stock *ptr, char **tab);
int		check_sorted(t_stock *ptr);
int		get_max_val(t_stock *ptr);
void	check_stack(t_stock *a);
void	index_stack(t_stock *ptr);
void	radix(t_stock **a, t_stock **b, int *n);
void	small_small_sort(t_stock **ptr);
void	small_sort(t_stock **a, t_stock **b, int n);
void	push(t_stock **src, t_stock **dst, char *msg);
void	swap(t_stock **ptr, char *msg);
void	rotate(t_stock **ptr, char *msg);
void	reverse_rotate(t_stock **ptr, char *msg);

#endif
