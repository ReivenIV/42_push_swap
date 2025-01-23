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

#include <stdio.h>
#include <stdlib.h>

/*
- static size_t	count_words(char const *src, char caracter);

- static	size_t	get_word_len(char const *src, char caracter);

- static	char	**splitter(char const *src, char caracter,
	char **dest, size_t words_count);

- char	**ft_split(char const *src, char caracter);

- static void	free_dest(size_t i, char **dest);


*/

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		str_len;
	char	*dup;

	i = 0;
	str_len = ft_strlen(str);
	dup = (char *)malloc(str_len * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	while (i < str_len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t	i;
	size_t	src_len;
	char	*str;

	if (src == NULL)
		return (NULL);
	src_len = ft_strlen(src);
	if (start >= src_len)
		return (ft_strdup(""));
	if (start + len > src_len)
		len = src_len - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && src[start + i] != '\0')
	{
		str[i] = src[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// --------------------

static size_t	count_words(char const *src)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] != ' ')
		{
			count++;
			while (src[i] && src[i] != ' ')
				i++;
		}
		else if (src[i] == ' ')
			i++;
	}
	return (count);
}

static	size_t	get_word_len(char const *src)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != ' ')
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

static	char	**splitter(char const *src,	char **dest, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (src[j] && src[j] == ' ')
			j++;
		dest [i] = ft_substr(src, j, get_word_len(&src[j]));
		if (!dest[i])
		{
			free_dest(i, dest);
			return (NULL);
		}
		while (src[j] && src[j] != ' ')
			j++;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_split(char const *src)
{
	char	**dest;
	size_t	src_count_words;

	if (!src)
		return (NULL);
	src_count_words = count_words(src);
	dest = (char **)malloc(sizeof(char *) * (src_count_words + 1));
	if (!dest)
		return (NULL);
	dest = splitter(src, dest, src_count_words);
	return (dest);
}
// //!  Main function to test ft_split
#include <stdio.h>
void print_split(char **split) {
	for (int i = 0; split[i]; i++) {
		printf("Segment %d: '%s'\n", i, split[i]);
		free(split[i]);
	}
	free(split);
}

int main() {
	char **result;

	// Test 1: Basic string with delimiters
	result = ft_split("15 -85 42 99");
	printf("Test 1:\n");
	print_split(result);
	// Expected Output:
	// Segment 0: 'Hello'
	// Segment 1: 'World'
	// Segment 2: '42'

	return 0;
}