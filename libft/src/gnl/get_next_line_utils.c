/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:54:17 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/28 13:20:11 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_get_strjoin(char *stash, char *buff)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!stash)
		stash = (char *)ft_calloc(1, sizeof(char));
	if (!stash || !buff)
		return (NULL);
	line = ft_calloc(ft_strlen(stash) + ft_strlen(buff) + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (stash[++i])
		line[i] = stash[i];
	j = 0;
	while (buff[j])
		line[i++] = buff[j++];
	line[i] = '\0';
	free(stash);
	return (line);
}

char	*ft_get_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	line = (char *)ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (stash[i])
	line[j++] = stash[i++];
	line[j] = '\0';
	free(stash);
	return (line);
}
