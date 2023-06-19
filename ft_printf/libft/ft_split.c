/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:32:33 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/20 14:22:04 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!s || (!*s && c != '\0'))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = (char *)malloc(n + 1);
	if (cpy == NULL)
		return (NULL);
	while (i < n)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static char	**ft_allocate_memory(char const *s, char c, int words)
{
	char	**split;

	if (!s || (!*s && c != '\0'))
	{
		split = (char **)malloc(sizeof(char *));
		if (split == NULL)
			return (NULL);
		split[0] = NULL;
	}
	else
	{
		split = (char **)malloc(sizeof(char *) * (words + 1));
		if (!split)
			return (NULL);
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;
	int		j;
	int		wordlen;

	i = 0;
	j = 0;
	words = ft_count_words(s, c);
	split = ft_allocate_memory(s, c, words);
	if (split == NULL)
		return (NULL);
	while (i < words)
	{
		while (s[j] == c)
			j++;
		wordlen = 0;
		while (s[j + wordlen] && s[j + wordlen] != c)
			wordlen++;
		split[i] = ft_strndup(&s[j], wordlen);
		j = j + wordlen;
		i++;
	}
	split[i] = NULL;
	return (split);
}
