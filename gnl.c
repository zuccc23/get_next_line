/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:19:09 by dahmane           #+#    #+#             */
/*   Updated: 2024/12/02 19:03:50 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	id;

	i = 0;
	id = 0;
	while (dest[i])
		i++;
	while (src[id])
	{
		dest[i + id] = src[id];
		id++;
	}
	dest[i + id] = '\0';
	return (dest);
}
char	*ft_strdup(char *src)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = strlen(src);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}



char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		o;
	char	*s3;

	o = 0;
	i = 0;
	s3 = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[o])
	{
		s3[i] = s1[o];
		o++;
		i++;
	}
	o = 0;
	while (s2[o])
	{
		s3[i] = s2[o];
		o++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

int	check(char *str, char c)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *read_line(char *temp, int fd)
{
	char	*buffer = NULL;
	int		nb_read;
	
	buffer = malloc(10 * sizeof(char));
	nb_read = 1;
	while (nb_read > 0 && check(buffer, '\n') != 1)
	{
		nb_read = read(fd, buffer, 10);
		buffer[nb_read] = '\0';
		if (!temp)
			temp = ft_strdup(buffer);
		else
			temp = ft_strjoin(temp, buffer);
	}
	return (temp);
}
char	*divide_line(char *temp, char *res)
{
	
}

char *get_next_line(int fd)
{
	char static	*temp;
	// char	*buffer = NULL;
	// int		nb_read;
	
	// buffer = malloc(10 * sizeof(char));
	// nb_read = 1;
	// while (nb_read > 0 && check(buffer, '\n') != 1)
	// {
	// 	nb_read = read(fd, buffer, 10);
	// 	buffer[nb_read] = '\0';
	// 	if (!temp)
	// 		temp = ft_strdup(buffer);
	// 	else
	// 		temp = ft_strjoin(temp, buffer);
	// }
	temp = read_line(temp, fd);
	return (temp);
}

int	main(int argc, char *argv[])
{
	int fd = open (argv[1], O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s\n", str);
	close(fd);
}
  