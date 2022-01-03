/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:19:41 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/03 00:57:22 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_links(t_stock *ptr)
{
	int	count;

	count = 0;
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}

int	get_eq_bin(int n)
{
	int	ret;

	ret = 0;
	while (n)
	{
		n >>= 1;
		ret++;
	}
	return (ret);
}
