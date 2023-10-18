/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:32:09 by hsievier          #+#    #+#             */
/*   Updated: 2023/07/29 15:34:24 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;
	size_t	l;

	l = ft_strlen(s);
	if (start > l)
		len = 0;
	else if ((len + start) > l)
		len = l - start;
	sub = (char *) malloc((len + 1));
	if (!sub || !s)
		return (0);
	i = 0;
	j = start;
	while (i < len && j < l)
	{
		sub[i] = s[j];
		i++;
		j++;
	}
	sub[i] = '\0';
	return (sub);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static void	*ft_free_str(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**ft_get_str(char **split, int index, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_substr(s, index, i - index);
			if (!split[j - 1])
			{
				ft_free_str(split);
				return (NULL);
			}
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		index;
	char	**split;

	i = count_words(s, c);
	split = (char **) malloc((i + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	index = -1;
	split = ft_get_str(split, index, s, c);
	if (!split)
		return (NULL);
	return (split);
}
