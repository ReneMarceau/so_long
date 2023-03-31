/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:56:57 by klaksi            #+#    #+#             */
/*   Updated: 2023/03/31 18:43:54 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int count_line(char *mapfile)
{
    int fd;
    char c;
    int readbytes;
    int count;
    
    count = 0;
    fd = open(mapfile, O_RDONLY);
    while (1)
    {
        readbytes = read(fd, &c, 1);
        if (readbytes == 0)
            break;
        if (readbytes < 0)
   
            return (-1);
             
        if (c == '\n')
            count++;
    }
    count++;
    close(fd);
    return (count);
}

char    **pars_tacus(char *mapfile)
{
    char    **map;
    int fd;
    int i;

    fd = open(mapfile, O_RDONLY);
    map = ft_calloc(count_line(mapfile), sizeof(char *));
    if (!map)
        return(NULL);
    
    i = 0;
    while (i <= count_line(mapfile))
    {
       map[i] = get_next_line(fd);
       i++;
    }

    close(fd);
    return (map);
}

