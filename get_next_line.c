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

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		size;
	int		total_size;
	char	*line;
	char	*temp;

	size = read(fd, &buffer, BUFFER_SIZE);
	total_size = 0;
	line = malloc(size * sizeof(char));
	temp = malloc(0);
	while (size != 0)
	{
		if (size == -1)
			break ;
		free(temp);
		temp = malloc(total_size * sizeof(char));
		ft_strlcpy(temp, line, total_size);
		free(line);
		line = malloc((total_size + size) * sizeof(char));
		ft_strlcpy(line, temp, total_size);
		total_size += size;
		ft_strlcat(line, buffer, total_size);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	free(temp);
	if (total_size > 0)
		return (line);
	return (NULL);
}
