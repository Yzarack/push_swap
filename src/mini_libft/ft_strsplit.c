/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:45:36 by jthierce          #+#    #+#             */
/*   Updated: 2019/08/08 23:55:55 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

size_t			ft_word(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
			word++;
		while (s[i] != c && s[i] != 0)
			i++;
		while (s[i] == c)
			i++;
	}
	return (word);
}

static char		**ft_malloc_tab(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	i_word;

	i = 0;
	j = 0;
	i_word = 1;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i + j] != 0 && s[i + j] != c)
				j++;
			i += j;
			if (!(tab[i_word] = (char *)malloc(sizeof(char) * (j + 1))))
				return (NULL);
			j = 0;
			i_word++;
		}
		while (s[i] != 0 && s[i] == c)
			i++;
	}
	return (tab);
}

static char		**ft_place_word(char const *s, char c, size_t word, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	i_word;

	i = 0;
	j = 0;
	i_word = 1;
	while (s[i] && i_word != word + 1)
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				tab[i_word][j] = s[i];
				j++;
				i++;
			}
			tab[i_word][j] = '\0';
			i_word++;
			j = 0;
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c, int *argc)
{
	size_t	word;
	char	**tab;

	if (s == NULL)
		return (NULL);
	if (s[0] == 0)
		return (NULL);
	if ((word = ft_word(s, c)) == 0)
		return (NULL);
	*argc = word + 1;
	if (!(tab = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	tab[0] = NULL;
	tab = ft_malloc_tab(s, c, tab);
	if (tab == NULL)
		return (NULL);
	tab = ft_place_word(s, c, word, tab);
	return (tab);
}
