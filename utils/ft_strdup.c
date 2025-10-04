/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 06:57:38 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 06:57:38 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	index;
	char	*location_pointer;

	length = ft_strlen(s);
	location_pointer = (char *)malloc(sizeof(char) * (length + 1));
	if (!location_pointer)
		return (NULL);
	index = 0;
	while (index < length)
	{
		location_pointer[index] = s[index];
		index++;
	}
	location_pointer[index] = '\0';
	return (location_pointer);
}
