/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:35:13 by dahmane           #+#    #+#             */
/*   Updated: 2024/12/09 21:09:02 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *temp, int fd)
{
	char	*buffer;
	int		nb_read;
	char	*cache;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!temp)
		temp = ft_strdup("");
	nb_read = 1;
	while (nb_read > 0 && check(temp, '\n') != 1)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
			return (free(temp), free(buffer), temp = NULL, NULL);
		buffer[nb_read] = '\0';
		cache = ft_strjoin(temp, buffer);
		if (!cache)
			return (free(temp), free(buffer), NULL);
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

	if (!*temp || !**temp)
		return (NULL);
	n = 0;
	while ((*temp)[n] != '\n' && (*temp)[n] != '\0')
		n++;
	if ((*temp)[n] == '\n')
		n++;
	res = ft_substr(*temp, 0, n);
	if (!res)
		return (free(*temp), *temp = NULL, NULL);
	cache = ft_strdup(*temp + n);
	if (!cache)
		return (free(res), free(*temp), *temp = NULL, NULL);
	free(*temp);
	*temp = cache;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_line(temp, fd);
	if (!temp)
		return (NULL);
	if (!*temp)
		return (free(temp), temp = NULL, NULL);
	res = divide_line(&temp);
	return (res);
}

// int	main(int argc, char *argv[])
// {
// 	// char s[] = "hello\nwelcome";
// 	int fd = open (argv[1], O_RDONLY);
// 	argc = 0;

// 	char *str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	close(fd);
// 	// printf("%s\n", ft_strchr(s, 'w'));
// 	// printf("%s\n", get_before_nline(s));
// 	// printf("%s\n", get_after_nline(s));
// }