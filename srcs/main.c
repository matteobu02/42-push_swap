/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:38:31 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/03 00:57:11 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	close_program(t_stock *a, t_stock *b)
{
	clear_list(a);
	clear_list(b);
	exit(0);
}

void	check_case(t_stock **a, t_stock **b)
{
	int	n;

	n = ft_count_links(*a);
	if (n == 2)
		swap(a, "sa\n");
	else if (n == 3)
		small_small_sort(a);
	else if (n <= 5)
		small_sort(a, b, n);
	else
		radix(a, b, &n);
}

int	main(int ac, char **av)
{
	t_stock	*stack_a;
	t_stock	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = (t_stock *)malloc(sizeof(t_stock));
	if (!stack_a)
		free_error(stack_a, NULL);
	stack_a->next = NULL;
	get_stack(stack_a, ac, av);
	check_stack(stack_a);
	stack_b = NULL;
	check_case(&stack_a, &stack_b);
	close_program(stack_a, stack_b);
}
