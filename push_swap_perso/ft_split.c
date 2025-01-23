/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:17:52 by rita              #+#    #+#             */
/*   Updated: 2025/01/23 17:17:52 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


static int	count_words(const char *src);
static int	splitter(char **dest, const char *src);
static char	*ft_strndup(const char *src, size_t start, size_t end);
char **ft_split(const char *src);

static int	count_words(const char *src)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[i] != '\0')
	{
		while (src[i] != '\0' && src[i] == ' ')
			i++;
		if (src[i] != '\0')
		{
			count++;
			while (src[i] != '\0' && src[i] != ' ')
				i++;
		}
	}
	return (count);
}

static char	*ft_strndup(const char *src, size_t start, size_t end)
{
	size_t		i;
	char		*dest;

	if (src == NULL || start > end)
		return (NULL);
	dest = malloc((end - start + 2) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start + 1))
	{
		dest[i] = src[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	splitter(char **dest, const char *src)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	end;

	i = 0;
	j = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		while (src[i] != '\0' && src[i] == ' ')
			i++;
		if (src[i] != '\0')
		{
			start = i;
			while (src[i] != '\0' && src[i] != ' ')
				i++;
			end = i - 1;
			dest[j] = ft_strndup(src, start, end);
			j++;
		}
	}
	dest[j] = NULL;
	return (j);
}

char **ft_split(const char *src) {
	int src_count_words;
	char **dest;

	if (src == NULL)
		return (NULL);
	src_count_words = count_words((char *)src);
	dest = malloc((src_count_words + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	if (src_count_words == 0) {
		dest[0] = NULL;
		return (dest);
	}
	if (splitter(dest, src) == 0) {
		for (int i = 0; i < src_count_words; i++) {
			free(dest[i]);
		}
		free(dest);
		return (NULL);
	}
	return (dest);
}




// //!  Main function to test ft_split
// #include <stdio.h>
// void print_split(char **split) {
// 	for (int i = 0; split[i]; i++) {
// 		printf("Segment %d: '%s'\n", i, split[i]);
// 		free(split[i]);
// 	}
// 	free(split);
// }

// int main() {
// 	char **result;

// 	result = ft_split("12 35 48 6 -85 +74 -85");
// 	printf("Test ft_split:\n");
// 	print_split(result);
// 	return 0;
// }