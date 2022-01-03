/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:03:50 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/02 02:33:43 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_count_words(char *s, char c);
void	ft_error(char *s);
void	*ft_free_tab(char **tab);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
void	*free_str(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
