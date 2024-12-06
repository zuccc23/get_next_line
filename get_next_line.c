/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:19:09 by dahmane           #+#    #+#             */
/*   Updated: 2024/12/06 16:21:37 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(char *temp, int fd)
{
	char	*buffer = NULL;
	int		nb_read;
	char	*cache;
	
	if (!temp)
		temp = ft_strdup("");
	buffer = malloc((BUFFER_SIZE) * sizeof(char));
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
	return (temp);
}

char	*divide_line(char **temp)
{
	char	*res;
	char	*cache;
	int		n;

	n = 0;
	while ((*temp)[n - 1] != '\n' && (*temp)[n] != '\0')
		n++;
	res = ft_substr(*temp, 0, n);
	if (!res)
		return (NULL);
	cache = ft_strdup(&(*temp)[n]);
	if (!cache)
		return (NULL);
	free(*temp);
	*temp = cache;
	return (res);
}

char *get_next_line(int fd)
{
	static char	*temp;
	char	*res;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(temp = read_line(temp, fd)))
		return (NULL);
	if (!(res = divide_line(&temp)))
		return (NULL);
	return (res);
}
/*
int	main(int argc, char *argv[])
{
	char s[] = "hello\nwelcome";
	int fd = open (argv[1], O_RDONLY);

	char *str = get_next_line(fd);
	printf("%s", str);
	// str = get_next_line(fd);
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
}*/
  