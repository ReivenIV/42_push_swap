/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:23:30 by gyong-si          #+#    #+#             */
/*   Updated: 2025/01/23 18:21:48 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *src, char caracter)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] != caracter)
		{
			count++;
			while (src[i] && src[i] != caracter)
				i++;
		}
		else if (src[i] == caracter)
			i++;
	}
	return (count);
}

static	size_t	get_word_len(char const *src, char caracter)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != caracter)
		i++;
	return (i);
}

static void	free_dest(size_t i, char **dest)
{
	while (i > 0)
	{
		i--;
		free(dest[i]);
	}
	free(dest);
}

static	char	**splitter(char const *src, char caracter,
	char **dest, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (src[j] && src[j] == caracter)
			j++;
		dest [i] = ft_substr(src, j, get_word_len(&src[j], caracter));
		if (!dest[i])
		{
			free_dest(i, dest);
			return (NULL);
		}
		while (src[j] && src[j] != caracter)
			j++;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_split(char const *src, char caracter)
{
	char	**dest;
	size_t	src_count_words;

	if (!src)
		return (NULL);
	src_count_words = count_words(src, caracter);
	dest = (char **)malloc(sizeof(char *) * (src_count_words + 1));
	if (!dest)
		return (NULL);
	dest = splitter(src, caracter, dest, src_count_words);
	return (dest);
}
