/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovchan <mmovchan@student.your42network>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:11:59 by mmovchan          #+#    #+#             */
/*   Updated: 2024/10/22 14:24:39 by mmovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init_remainder(void)
{
	char	*ptr;

	ptr = (char *)malloc(1 * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_newline(char *remainder)
{
	ssize_t	i;
	ssize_t	n;
	char	*line;

	if (!remainder)
		return (NULL);
	i = 0;
	n = 0;
	while (remainder[i] != '\n' && remainder[i])
		i++;
	if (remainder[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (n < i)
	{
		line[n] = remainder[n];
		n++;
	}
	line[n] = '\0';
	return (line);
}

char	*ft_remainder(int fd, char *remainder)
{
	ssize_t	bytes_read;
	char	*buffer;

	if (!remainder)
		remainder = ft_init_remainder();
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(remainder);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = ft_join_free(remainder, buffer);
		if (ft_nl(remainder) == 1 || bytes_read == 0)
			break ;
	}
	free(buffer);
	return (remainder);
}

char	*ft_afternewline(char *remainder)
{
	ssize_t	i;
	char	*tmp;

	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n' && remainder[i + 1] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	if (remainder[i] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	tmp = malloc((ft_strlen(remainder + i + 1) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, remainder + i + 1);
	free(remainder);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = ft_remainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_newline(remainder);
	remainder = ft_afternewline(remainder);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("t.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}
