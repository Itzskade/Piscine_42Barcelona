/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-n <rmarin-n@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:10:05 by rmarin-n          #+#    #+#             */
/*   Updated: 2025/07/30 18:21:15 by rmarin-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     its_charset(char str, char *charset)
{
        while (*charset)
        {
                if (str == *charset)
                        return (1);
                charset++;
        }
        return (0);

}

size_t  count_words(char const *str, char *charset)
{
        size_t  count;

        count = 0;
        while (*str)
        {
                while (*str && its_charset(*str, charset))
                        str++;
                if (*str)
                        count++;
                while (*str && !its_charset(*str, charset))
                        str++;
        }
        return (count);
}

char    *ft_strndup(char const *str, size_t n)
{
        char    *ptr;
        char    *dup;

        if (!str || !n)
                return (NULL);
        dup = malloc(sizeof(*dup) * (n + 1));
        if (!dup)
                return (NULL);
        ptr = dup;
        while (n--)
                *ptr++ = *str++;
        *ptr = '\0';
        return (dup);
}

char    **ft_split(char const *str, char *charset)
{

        char    **ptr;
        char    **arr;
        char    *start;

        arr = malloc(sizeof(*arr) * (count_words(str, charset) + 1));
        if (!arr)
                return (NULL);
        ptr = arr;
        while (*str)
        {
                while (*str && its_charset(*str, charset))
                        str++;
                start = str;
                while (*str && !its_charset(*str, charset))
                        str++;
                if (str != start)
                        *ptr++  = ft_strndup(start, str - start);
        }
        *ptr = NULL;
        return (arr);
}
/*
#include <stdio.h>

int main(void)
{
	char *str = "Hello,,world;this:is;Piscine!";
	char *charset = ",;:";
	char **words = ft_split(str, charset);
	char **ptr = words;
    
    while (*ptr)
    {
		printf("Word: %s\n", *ptr);
		free(*ptr);
		ptr++;
    }
    free(words);
    return 0;
}
*/
