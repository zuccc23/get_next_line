/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:19:09 by dahmane           #+#    #+#             */
/*   Updated: 2024/12/03 18:35:44 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_before_line(char *str)
{
	int	n;

	n = 0;
	while (str[n] && str[n] != '\n')
	{
		n++;
	}
	if (str[n] == '\n')
		n++;
	return (n);
}
int	ft_strlen_after_line(char *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[n] && str[n] != '\n')
		n++;
	if (str[n] == '\n')
		n++;
	while (str[n])
	{
		i++;
		n++;
	}
	return (i);
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

char	*get_after_nline(char *temp)
{
	char	*str;
	int		n;
	int		i;

	i = 0;
	n = 0;
	str = malloc(ft_strlen_after_line(temp) * sizeof(char));
	if (!str)
		return(NULL);
	while (temp[n] != '\n' && temp[n])
		n++;
	if (temp[n] == '\n')
		n++;
	while (temp[n])
	{
		str[i] = temp[n];
		i++;
		n++;
	}
	return (str);
}
char	*get_before_nline(char *temp)
{
	char	*str;
	int		n;
	int		i;

	i = 0;
	n = 0;
	str = malloc(ft_strlen_before_line(temp) * sizeof(char));
	if (!str)
		return(NULL);
	while (temp[n - 1] != '\n' && temp[n])
	{
		str[i] = temp[n];
		i++;
		n++;
	}
	return (str);
}

char *read_line(char *temp, int fd)
{
	char	*buffer = NULL;
	int		nb_read;
	char	*cache;
	
	if (!temp)
		temp = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nb_read = 1;
	while (nb_read > 0 && check(temp, '\n') != 1)
	{
		if (nb_read < 0)
			return(free(temp), free(buffer), NULL);
		nb_read = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_read] = '\0';
		cache = ft_strjoin(temp, buffer);
		if (!cache)
			return(free(temp), free(buffer), NULL); 
		free(temp);
		temp = cache;
	}
	free(buffer);
	printf("%s", temp);
	return (temp);
}
// char	*divide_line(char *temp)
// {
// 	char	*res;
	
// 	res = get_before_nline(temp);
// 	temp = get_after_nline(temp);
// 	return(res);
// }

char *get_next_line(int fd)
{
	char static	*temp = NULL;
	char	*res;
	
	temp = read_line(temp, fd);
	//res = get_before_nline(temp);
	//temp = get_after_nline(temp);
	// printf("%s\n", res);
	return (res);
}

int	main(int argc, char *argv[])
{
	char s[] = "hello\nwelcome";
	int fd = open (argv[1], O_RDONLY);
	get_next_line(fd);
	// char *str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	close(fd);
	// printf("%s\n", ft_strchr(s, 'w'));
	// printf("%s\n", get_before_nline(s));
	// printf("%s\n", get_after_nline(s));
}
  