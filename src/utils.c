/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:50:14 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/12 17:07:34 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char **copymap(char **map)
{
    char **newmap;
    int i;

    i = 0;
    while (map[i])
        i++;
    newmap = (char **)ft_calloc(i + 1, sizeof(char *));
    i = -1;
    while (map[++i])
        newmap[i] = ft_strdup(map[i]);
    return (newmap);
}