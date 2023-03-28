/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:08:38 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/18 17:42:09 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	*ft_free(char **split, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(split[i++]);
	free(split);
	return (NULL);
}

static char	**ft_fill_substr(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	size_t	str_len;
	int		index;

	i = 0;
	j = 0;
	str_len = ft_strlen(s);
	index = -1;
	while (i <= str_len)
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == str_len) && index >= 0)
		{
			split[j] = ft_substr(s, index, i - index);
			if (!split[j++])
				return (ft_free(split, j));
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_fill_substr(s, c, split));
}
