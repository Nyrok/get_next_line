/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:04:21 by hkonte            #+#    #+#             */
/*   Updated: 2025/01/17 12:29:55 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, const char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result || !s1 || !s2)
		return (NULL);
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		if (i < ft_strlen(s1))
			result[i] = s1[i];
		else
			result[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	free(s1);
	result[i] = '\0';
	return (result);
}
