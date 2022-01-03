/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:12:04 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/01 14:12:42 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stock **src, t_stock **dst, char *msg)
{
	t_stock	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
	temp = NULL;
	ft_putstr_fd(msg, 1);
}

void	swap(t_stock **ptr, char *msg)
{
	t_stock	*temp;

	if (!ptr || !*ptr)
		return ;
	temp = *ptr;
	*ptr = (*ptr)->next;
	temp->next = (*ptr)->next;
	(*ptr)->next = temp;
	temp = NULL;
	ft_putstr_fd(msg, 1);
}

void	rotate(t_stock **ptr, char *msg)
{
	t_stock	*temp1;
	t_stock	*temp2;

	if (!ptr || !*ptr)
		return ;
	temp1 = *ptr;
	*ptr = (*ptr)->next;
	temp1->next = NULL;
	temp2 = *ptr;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp1;
	temp2 = NULL;
	temp1 = NULL;
	ft_putstr_fd(msg, 1);
}

void	reverse_rotate(t_stock **ptr, char *msg)
{
	t_stock	*temp;

	if (!ptr || !*ptr)
		return ;
	temp = *ptr;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *ptr;
	*ptr = temp->next;
	temp->next = NULL;
	temp = NULL;
	ft_putstr_fd(msg, 1);
}
