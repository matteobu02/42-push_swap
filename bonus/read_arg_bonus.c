/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 13:54:20 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/10 18:20:44 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_arg(char *s, t_stock *ptr)
{
	int	i;

	i = -1;
	if (!*s)
		free_error(ptr, NULL);
	while (s[++i])
		if ((s[i] > 57 || s[i] < 48) && s[i] != 32
			&& s[i] != '-' && s[i] != '+')
			free_error(ptr, NULL);
}

void	get_stack(t_stock *a, int ac, char **args)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		check_arg(args[i], a);
		tab = ft_split(args[i], 32);
		if (!tab)
			free_error(a, NULL);
		while (tab[++j])
		{
			a->val = ft_atoi(tab[j], a, tab);
			if (!tab[j + 1] && !args[i + 1])
				break ;
			a->next = (t_stock *)malloc(sizeof(t_stock));
			if (!a->next)
				free_and_close(tab, a);
			a = a->next;
			a->next = NULL;
		}
		tab = ft_free_tab(tab);
	}
}

int	check_sorted(t_stock *ptr)
{
	int	curr;

	if (!ptr)
		return (-1);
	curr = ptr->val;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->val < curr)
			return (0);
		else
			curr = ptr->val;
	}
	return (1);
}

void	check_stack(t_stock *a)
{
	t_stock	*tmp1;
	t_stock	*tmp2;

	tmp1 = a;
	while (tmp1)
	{
		tmp2 = a;
		while (tmp2 != tmp1)
		{
			if (tmp1->val == tmp2->val)
			{
				tmp1 = NULL;
				tmp2 = NULL;
				free_error(a, NULL);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
