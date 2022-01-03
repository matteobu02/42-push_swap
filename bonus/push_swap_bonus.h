/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 13:46:54 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/02 02:10:02 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_stock
{
	int				val;
	int				index;
	struct s_stock	*next;
}	t_stock;

void	free_error(t_stock *a, t_stock *b);
void	get_stack(t_stock *a, int ac, char **args);
void	get_stdin(t_stock **a, t_stock **b);
void	check_stack(t_stock *ptr);
int		check_sorted(t_stock *ptr);
void	clear_list(t_stock *ptr);
void	close_program(t_stock *a, t_stock *b, char *s);
void	free_and_close(char **tab, t_stock *ptr);
int		ft_atoi(char *str, t_stock *ptr, char **tab);
void	push(t_stock **a, t_stock **b, char *msg);
void	swap(t_stock **ptr, char *msg);
void	rotate(t_stock **ptr, char *msg);
void	reverse_rotate(t_stock **ptr, char *msg);

#endif
