/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 06:58:27 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 06:58:27 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	source_len;
	size_t	index;
	char	*target;

	if (!s)
		return (NULL);
	source_len = ft_strlen(s);
	if (source_len <= start)
		return (ft_strdup(""));
	if (len > source_len - start)
		len = source_len - start;
	target = (char *)malloc(sizeof(char) * (len + 1));
	if (!target)
		return (NULL);
	index = 0;
	while (s[index + start] && index < len)
	{
		target[index] = s[start + index];
		index++;
	}
	target[index] = '\0';
	return (target);
}
