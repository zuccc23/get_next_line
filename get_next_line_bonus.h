/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:00:17 by dahmane           #+#    #+#             */
/*   Updated: 2024/12/09 23:12:46 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h> 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

int		ft_strlen_after_line(char *str);
int		ft_strlen_before_line(char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		check(char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

char	*get_next_line(int fd);
char	*read_line(char *temp, int fd);

#endif