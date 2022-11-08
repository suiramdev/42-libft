/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:37:32 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/08 17:36:21 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	entire_free(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (0);
}

// It looks terrible, I had to free in another function
// so it fits the norminette
static int	ft_allocate_words(char const *s, char c, char **output)
{
	int	wordcount;
	int	charcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		while (c == s[i] && s[i])
			i++;
		if (s[i])
		{
			charcount = 0;
			while (c != s[i] && s[i])
			{
				charcount++;
				i++;
			}
			output[wordcount] = malloc((charcount + 1) * sizeof(char));
			if (!output[wordcount])
				return (entire_free(output, wordcount));
			wordcount++;
		}
	}
	return (1);
}

// It allocated enough memory to the split's output
static char	**ft_prepare_split(char const *s, char c)
{
	char	**output;
	int		wordcount;
	int		i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		while (c == s[i] && s[i])
			i++;
		if (s[i])
		{
			while (c != s[i] && s[i])
				i++;
			wordcount++;
		}
	}
	output = malloc((wordcount + 1) * sizeof(char *));
	if (!output)
		return (NULL);
	output[wordcount] = 0;
	if (!ft_allocate_words(s, c, output))
		return (NULL);
	return (output);
}

static void	ft_fill_words(char const *s, char c, char **output)
{
	int		wordcount;
	int		charcount;
	int		i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		while (c == s[i] && s[i])
			i++;
		if (s[i])
		{
			charcount = 0;
			while (c != s[i] && s[i])
			{
				output[wordcount][charcount] = s[i];
				charcount++;
				i++;
			}
			output[wordcount][charcount] = '\0';
			wordcount++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**output;

	output = ft_prepare_split(s, c);
	if (!output)
		return (NULL);
	ft_fill_words(s, c, output);
	return (output);
}
