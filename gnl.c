/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:19:09 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/29 16:57:19 by dahmane          ###   ########.fr       */
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

char	*ft_realloc(char *str, char *new)
{
	char	*str2;
	int	size;
	
	size = strlen(str) + strlen(new);
	str2 = malloc(size * sizeof(char));
	str2 = str;
	ft_strcat(str2, new);
	return (str2);
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

char	check_n(char *buffer, char *temp, char *res)
{
	int	i;

	i = 0;
	// while (buffer[i] && buffer[i] != '\n')
	// {
	// 	res[i] = buffer[i];
	// 	i++;
	// }
	res = ft_strjoin(res, temp);
}
char *get_next_line(int fd)
{
	char	*res;
	char	*buffer = NULL;
	char	*temp;
	int		nb_read = 0;
	
	buffer = malloc(10 * sizeof(char));
	// nb_read = read(fd, str, 10);
	// temp = strdup(str);
	// nb_read = read(fd, str, 10);
	// res = malloc (21 * sizeof(char));
	// res = ft_strcat(temp, str);
	
	//strr = ft_strdup(res);
	// nb_read = read(fd, buffer, 10);
	// temp = ft_strdup(buffer);
	// res = temp;
	// nb_read = read(fd, buffer, 10);
	// temp = ft_strdup(buffer);
	// res = ft_strjoin(res, temp);
	//res = ft_strjoin(strr, temp);
	nb_read = read(fd, buffer, 10);
	while (nb_read > 0)
	{
		temp = buffer;
		
		if (!res)
		{
			res = temp;
		}
		else
			res = ft_strjoin(res, temp);
		nb_read = read(fd, buffer, 10);
		buffer[nb_read] = '\0';
	}
	return (res);
}

int	main(int argc, char *argv[])
{
	int fd = open (argv[1], O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s\n", str);
	close(fd);
}
