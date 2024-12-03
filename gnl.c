/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:19:09 by dahmane           #+#    #+#             */
/*   Updated: 2024/12/03 14:55:28 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
char	*ft_strdupn(char *src)
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
char	*ft_strchr(const char *s, int c)
{
	unsigned char	u_c;
	int	i;

	i = 0;
	u_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == u_c)
			return ((char *)&s[i + 1]);
		i++;
	}
	if (u_c == '\0')
		return ((char *)&s[i]);
	return ((char *)s);
}
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*s2;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	if (start > ft_strlen(s))
// 		return (ft_strdup(""));
// 	i = 0;
// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;
// 	s2 = malloc((len + 1) * sizeof(char));
// 	if (s2 == NULL)
// 		return (NULL);
// 	while (i < len && s[start])
// 	{
// 		s2[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	s2[i] = '\0';
// 	return (s2);
// }

// char	*get_before_nline(char *temp)
// {
	
// }

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
char	*divide_line(char *temp)
{
	char	*res;
	
	
	temp = ft_strchr(temp, '\n');
	return(temp);
}

char *get_next_line(int fd)
{
	char static	*temp;
	char	*res;
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
	temp = divide_line(temp);
	return (temp);
}

int	main(int argc, char *argv[])
{
	char s[] = "hello\nwelcome";
	int fd = open (argv[1], O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s\n", str);
	close(fd);
	// printf("%s\n", ft_strchr(s, 'w'));
	printf("%d\n", ft_strlen_before_line(s));
}
  