/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 06:56:48 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 06:56:48 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	count_words(const char *s, const char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_memory(char **dest, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

static char	**fill_words(const char *s, char c, size_t w_count, char **dest)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] && j < w_count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		len = i - start;
		if (len > 0)
		{
			dest[j] = ft_substr(s, start, len);
			if (!dest[j])
				return (free_memory(dest, j), NULL);
			j++;
		}
	}
	return ((char **)dest);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**res;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	res[word_count] = NULL;
	if (!fill_words(s, c, word_count, res))
		return (NULL);
	return (res);
}
