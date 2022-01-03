/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:13:13 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/31 14:55:54 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_val(t_stock *ptr)
{
	int	ret;

	ret = ptr->val;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->val > ret)
			ret = ptr->val;
	}
	return (ret);
}

void	small_small_sort(t_stock **ptr)
{
	t_stock	*tmp;

	tmp = *ptr;
	if (tmp->val > tmp->next->val && tmp->val > tmp->next->next->val
		&& tmp->next->val < tmp->next->next->val)
		rotate(ptr, "ra\n");
	else if (tmp->val > tmp->next->val && tmp->val < tmp->next->next->val)
		swap(ptr, "sa\n");
	else if (tmp->val < tmp->next->val && tmp->next->val > tmp->next->next->val
		&& (tmp->val > tmp->next->next->val))
		reverse_rotate(ptr, "rra\n");
	else if (tmp->val > tmp->next->val
		&& tmp->next->val > tmp->next->next->val)
	{
		swap(ptr, "sa\n");
		reverse_rotate(ptr, "rra\n");
	}
	else if (tmp->val < tmp->next->val && tmp->val < tmp->next->next->val
		&& tmp->next->val > tmp->next->next->val)
	{
		swap(ptr, "sa\n");
		rotate(ptr, "ra\n");
	}
}

int	get_index(t_stock *b, t_stock *a)
{
	int	count;

	count = 0;
	while (b->val > a->val)
	{
		count++;
		a = a->next;
	}
	return (count);
}

void	place_right(t_stock **b, t_stock **a)
{
	int		count;

	count = get_index(*b, *a);
	if (count == 1)
	{
		push(b, a, "pa\n");
		swap(a, "sa\n");
	}
	else if (count == 2)
	{
		rotate(a, "ra\n");
		push(b, a, "pa\n");
		swap(a, "sa\n");
		reverse_rotate(a, "rra\n");
	}
	else if (count == 3)
	{
		reverse_rotate(a, "rra\n");
		push(b, a, "pa\n");
		rotate(a, "ra\n");
		rotate(a, "ra\n");
	}
}

void	small_sort(t_stock **a, t_stock **b, int n)
{
	while (n-- - 3)
		push(a, b, "pb\n");
	small_small_sort(a);
	while (*b)
	{
		if (get_max_val(*a) < (*b)->val)
		{
			push(b, a, "pa\n");
			rotate(a, "ra\n");
		}
		else if ((*b)->val < (*a)->val)
			push(b, a, "pa\n");
		else
			place_right(b, a);
	}
}
