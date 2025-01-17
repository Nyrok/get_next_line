/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:29:47 by hkonte            #+#    #+#             */
/*   Updated: 2025/01/17 12:42:53 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*parse_buffer_line(const char *buffer, int siz)
{
	size_t	i;
	char	*result;

	i = 0;
	result = malloc(siz * sizeof(char));
	while (buffer[i] && buffer[i] != '\n')
	{
		result[i] = buffer[i];
		i++;
	}
	return (result);
}

char	*parse_buffer_memory(char *buffer)
{
	size_t	i;

	i = 0;
	while (*buffer && *buffer != '\n')
		buffer++;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;
	int			total_size;
	char		buffer[BUFFER_SIZE];
	int			size;

	size = read(fd, &buffer, BUFFER_SIZE);
	line = malloc(4096 * sizeof(char));
	total_size = 0;
	if (memory)
	{
		total_size = ft_strlcpy(line, memory, ft_strlen(memory));
		memory = NULL;
	}
	while (size != 0)
	{
		if (size == -1)
			break ;
		total_size += size;
		if (ft_strchr(buffer, '\n'))
		{
			memory = parse_buffer_memory(buffer);
			ft_strlcat(line, parse_buffer_line(buffer, total_size), total_size + 1);
			break ;
		}
		ft_strlcat(line, buffer, total_size + 1);
		size = read(fd, &buffer, BUFFER_SIZE);
	}
	if (total_size > 0)
		return (line);
	return (NULL);
}
