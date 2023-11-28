/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:47:54 by mlow              #+#    #+#             */
/*   Updated: 2023/09/21 21:05:56 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_tokens_start(char const *s, char c)
{
	size_t	totallength;
	size_t	totalwords;

	totallength = 0;
	totalwords = 0;
	while (s[totallength])
	{
		if (s[totallength] != c && (totallength == 0
				|| s[totallength - 1] == c))
			totalwords++;
		totallength++;
	}
	return (totalwords);
}

static char	*readwords(char const **s, char c)
{
	char	*word;
	size_t	wordlen;
	size_t	string;

	wordlen = 0;
	while (**s == c && **s)
		(*s)++; 
	while (**s != c && **s)
	{
		wordlen++;
		(*s)++;
	}
	word = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (!word)
		return (NULL);
	string = 0;
	while (string < wordlen)
	{
		word[string] = *(*s - wordlen + string);
		string++;
	}
	word[string] = '\0';
	return (word);
}

static char	**backtrack_free(char **arrays, size_t string)
{
	while ((int)string >= 0)
	{
		free(arrays[string]);
		string--;
	}
	free(arrays);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arrays;
	size_t	string;
	size_t	totalwords;

	string = 0;
	totalwords = count_tokens_start(s, c);
	arrays = (char **)malloc(sizeof(char *) * (totalwords + 1));
	if (arrays == NULL)
		return (NULL);
	while (string < totalwords)
	{
		arrays[string] = readwords(&s, c);
		if (!arrays[string])
			return (backtrack_free(arrays, string));
		string++;
	}
	arrays[string] = NULL;
	return (arrays);
}
//
////objective: To split a string into an array of substrings
//tokenize(substring) a string to process input or parsing data.
//
//"static size_t	count_tokens_start(char const *s, char c)"
//Purpose is to count the total no of words, thus function
// focuses when it hits the first letter and then counts.
// it will only count again once it detects a value by "char c"
// which is "space". This value is "totalwords".
// "totallength" is just to move the function forward.
//
//"static char  *readwords(char const **s, char c)"
//-Purpose of this function is to detect words and then
// copy the words down one by one. The reason why 
// *readwords has a pointer for this is because it
// is supposed to read strings in an array. we 
// want to give it strings, word by word, 
// not letter by letter.
// "(**s == c && **s)" reads char and ends when it fails,
// basically it fails when it reads something other
// than "char c" which is "words or NULL".
// -"(*s)++;" is due to c operator priority, to prevent
// only "s" to be the only one being read instead of
// "*s".
// while "(**s != c && **s)" checks if the current
// character is different from "char c" and if it's
// true, it will count the wordlen of the word and
// contiune reading till it fails, "char c or NULL".
//1)word = (char *)malloc(sizeof(char) * (wordlen + 1));
// -counts totalsize of word first obtained from wordlen.
// while "(string < wordlen)" does is that it gets the 
// word from the current *s. 
// "*(*s - wordlen + string)" i used "- wordlen" cause the
// current *s is already moved from it's beginning s[0]
// forward by "(**s == c && **s)" & "(**s != c && **s)".
// and the reason why its a **s being used here, it is 
// because we want to give word[string] one letter at
// the time. and thanks to string++, both will move
// forward together.
//
//"static char	**backtrack(**arrays, string)" what it
// does is that it could
//
//"char	**ft_split(char const *s, char c)"
//Purpose of ft_split is to obtain array
// malloc u used sizeof(char *) because you want string not char
//1)arrays[string] = readwords(&s, c);
// -arrays[string] to put characters into the string
//
/*
int	main(void)
{
	char const	*s = "  How   are  you today? ";
	char		c = ' ';
	char		**split_strings = ft_split(s, c); calls ft_split to get arraystrings
	size_t		i;

	printf("Value of orignal string: %s\n", s);
	if(split_strings != NULL)
	{
		i = 0; reads the strings one by one
		while (split_strings[i] != NULL)
		{
			
			printf("current string %zu: %s\n", i, split_strings[i]);
			free(split_strings[i]); free each individual string
			i++;
		}
		free(split_strings); free the array containing all string (pointers)
	}
	else
		printf("ft_split returned NULL\n");
	printf("total words found start: %lu\n", count_tokens_start(s, c));
	printf("Current string: %s\n", readwords(&s, c));
	printf("Current string: %s\n", readwords(&s, c));
	printf("Current string: %s\n", readwords(&s, c));
	printf("Current string: %s\n", readwords(&s, c));
	printf("Compare strings %s\n", *ft_split(s, c)); why does this null?
	printf("Compare strings %s\n", split_strings);
	return (0);
}
*/
//
//Objective is to - hit until string,
//in that loop freeing each char *arrays, then free char **arrays.
//
//The reason why we use this version is if we free this backtrack
// with void, we can use just the function then bottom return
// "NULL".
/*static void     backtrack_free(char **arrays, size_t string)
{
        while ((int)string >= 0)
        {
                free(arrays[string]);
                string--;
        }
        free(arrays);
}

char    **ft_split(char const *s, char c)
{
        char    **arrays;
        size_t  string;
        size_t  totalwords;

        string = 0;
        totalwords = count_tokens_start(s, c);
        arrays = (char **)malloc(sizeof(char *) * (totalwords + 1));
        if (arrays == NULL)
                return (NULL);
        while (string < totalwords)
        {
                arrays[string] = readwords(&s, c);
                if (!arrays[string])
                {
                        backtrack_free(arrays, string);
                        return (NULL);
                }
                string++;
        }
        arrays[string] = NULL;
        return (arrays);
}
*/
//"static char     **backtrack_free(char **arrays, size_t string)".
//The current backtrack version uses double pointer
// due to array's double pointer. and since
// we want to free them one by one before we free
// the entire array, we need to double pointer it.
