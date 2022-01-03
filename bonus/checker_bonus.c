/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 13:39:07 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/02 01:45:16 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	get_stdin(&stack_a, &stack_b);
	if (check_sorted(stack_a) == 1)
		if (check_sorted(stack_b) == -1)
			close_program(stack_a, stack_b, "OK\n");
	close_program(stack_a, stack_b, "KO\n");
	return (0);
}
