/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:44:16 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/03 13:18:40 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_line(char *s, t_stock **a, t_stock **b)
{
	if (!ft_strcmp(s, "sa\n"))
		swap(a, NULL);
	else if (!ft_strcmp(s, "sb\n"))
		swap(b, NULL);
	else if (!ft_strcmp(s, "ss\n"))
	{
		swap(a, NULL);
		swap(b, NULL);
	}
	else if (!ft_strcmp(s, "pa\n"))
		push(b, a, NULL);
	else if (!ft_strcmp(s, "pb\n"))
		push(a, b, NULL);
	else if (!ft_strcmp(s, "ra\n"))
		rotate(a, NULL);
	else if (!ft_strcmp(s, "rb\n"))
		rotate(b, NULL);
	else
		return (0);
	return (1);
}

void	check_line_1(char *s, t_stock **a, t_stock **b)
{
	if (!ft_strcmp(s, "rr\n"))
	{
		rotate(a, NULL);
		rotate(b, NULL);
	}
	else if (!ft_strcmp(s, "rra\n"))
		reverse_rotate(a, NULL);
	else if (!ft_strcmp(s, "rrb\n"))
		reverse_rotate(b, NULL);
	else if (!ft_strcmp(s, "rrr\n"))
	{
		reverse_rotate(a, NULL);
		reverse_rotate(b, NULL);
	}
	else
	{
		free(s);
		s = NULL;
		free_error(*a, *b);
	}
}

void	get_stdin(t_stock **a, t_stock **b)
{
	char	*line;
	int		flag;

	line = get_next_line(0);
	while (line)
	{
		flag = check_line(line, a, b);
		if (!flag)
			check_line_1(line, a, b);
		if (!line)
			free_error(*a, *b);
		free(line);
		line = get_next_line(0);
	}
}
