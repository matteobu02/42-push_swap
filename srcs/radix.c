/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:46:55 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/03 00:56:06 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stock *ptr)
{
	t_stock	*temp1;
	t_stock	*temp2;
	int		i;

	temp1 = ptr;
	while (temp1)
	{
		temp2 = ptr;
		i = 0;
		while (temp2)
		{
			if (temp1->val > temp2->val)
				i++;
			temp2 = temp2->next;
		}
		temp1->index = i;
		temp1 = temp1->next;
	}
}

int	get_max_index(t_stock *ptr)
{
	int	ret;

	ret = ptr->index;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->index > ret)
			ret = ptr->index;
	}
	return (ret);
}

void	decide_push_a(t_stock **a, t_stock **b, int shift, int *n)
{
	int	i;

	i = -1;
	while (++i < *n)
	{
		if (((*a)->index >> shift & 1) == 1)
			rotate(a, "ra\n");
		else if (((*a)->index >> shift & 1) == 0)
		{
			*n -= 1;
			i -= 1;
			push(a, b, "pb\n");
		}
	}
}

void	decide_push_b(t_stock **b, t_stock **a, int shift, int *n)
{
	int	i;

	i = -1;
	while (++i < *n)
	{
		if (((*b)->index >> (shift + 1) & 1) == 1)
		{
			i -= 1;
			*n -= 1;
			push(b, a, "pa\n");
		}
		else if (((*b)->index >> (shift + 1) & 1) == 0)
			rotate(b, "rb\n");
	}
}

void	radix(t_stock **a, t_stock **b, int *na)
{
	int		max;
	int		i;
	int		nb;

	index_stack(*a);
	max = get_max_index(*a);
	max = get_eq_bin(max);
	i = -1;
	while (++i < max)
	{
		decide_push_a(a, b, i, na);
		nb = ft_count_links(*b);
		decide_push_b(b, a, i, &nb);
		*na = ft_count_links(*a);
	}
	while (*b)
		push(b, a, "pa\n");
}
