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

#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

static int	count_words(const char *str)
{
    int		count;
    bool	inside_word;
    int		i;

    count = 0;
    inside_word = false;
    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && !inside_word)
        {
            inside_word = true;
            count++;
        }
        else if (str[i] == ' ')
            inside_word = false;
        i++;
    }
    return (count);
}

static char	*get_next_word(const char **str)
{
    int			start;
    char		*word;
    int			len;
    int			i;
    int			j;

    i = 0;
    while ((*str)[i] == ' ' && (*str)[i])
        i++;
    start = i;
    len = 0;
    while ((*str)[i + len] && (*str)[i + len] != ' ')
        len++;
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    j = 0;
    while (j < len)
    {
        word[j] = (*str)[start + j];
        j++;
    }
    word[len] = '\0';
    *str += i + len;
    return (word);
}

char	**ft_split(const char *str)
{
    int		words_number;
    char	**dest;
    int		i;

    if (!str)
        return (NULL);
    words_number = count_words(str);
    dest = malloc(sizeof(char *) * (words_number + 1));
    if (!dest)
        return (NULL);
    i = 0;
    while (i < words_number)
    {
        dest[i] = get_next_word(&str);
        if (!dest[i])
        {
            while (i > 0)
                free(dest[--i]);
            free(dest);
            return (NULL);
        }
        i++;
    }
    dest[i] = NULL;
    return (dest);
}

//*   ---------------------
//*   ::  test it dear   ::
//*  ----------------------
// //!  Main function to test ft_split
// // #include <stdio.h>
// // void print_split(char **split) {
// // 	for (int i = 0; split[i]; i++) {
// // 		printf("Segment %d: '%s'\n", i, split[i]);
// // 		free(split[i]);
// // 	}
// // 	free(split);
// // }
// // int main() {
// // 	char **result;
// // 	// Test 1: Basic string with delimiters
// // 	result = ft_split("15 -85 42 99");
// // 	printf("Test 1:\n");
// // 	print_split(result);
// // 	// Expected Output:
// // 	// Segment 0: 'Hello'
// // 	// Segment 1: 'World'
// // 	// Segment 2: '42'
// // 	return 0;
// // }