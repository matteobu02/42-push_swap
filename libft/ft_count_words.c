/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:08:07 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/22 01:11:37 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *s, char c)
{
	int	flag;
	int	count;
	int	i;

	flag = 0;
	count = 0;
	i = -1;
	while (s[++i])
	{
		if (flag && s[i] == c)
			flag = 0;
		else if (!flag && s[i] != c)
		{
			count++;
			flag = 1;
		}
	}
	return (count);
}
