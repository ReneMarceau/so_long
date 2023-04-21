/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:56:57 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/21 13:26:59 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Parses the map file and returns a 2D array of strings
char    **pars_tacus(char *mapfile)
{
    char	**map;
	int		maplen;
    int 	fd;
    int 	i;

	maplen = count_line(mapfile);
    map = (char **)ft_calloc(maplen + 1, sizeof(char *));
    if (!map)
    {
        ft_putendl_fd(ERROR_MALLOC, 2);
        exit(EXIT_FAILURE);
    }
    fd = open(mapfile, O_RDONLY);
    i = 0;
    while (i <= maplen)
       map[i++] = get_next_line(fd);
    close(fd);
    return (map);
}
