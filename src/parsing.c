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
    int readbytes;
    int count;
    int fd;
    char c;
    
    fd = open(mapfile, O_RDONLY);
    count = 0;
    while (1)
    {
        readbytes = read(fd, &c, 1);
        if (readbytes < 0)
        {
            close(fd);
            return (-1);
        }
        else if (readbytes == 0)
            break;
        else if (c == '\n')
            count++;
    }
    count++;
    close(fd);
    return (count);
}

char    **pars_tacus(char *mapfile)
{
    char	**map;
    int 	fd;
	int		maplen;
    int 	i;

	maplen = count_line(mapfile);
    map = ft_calloc(maplen, sizeof(char *));
    if (!map)
        return(NULL);
    fd = open(mapfile, O_RDONLY);
    i = 0;
    while (i <= maplen)
    {
       map[i] = get_next_line(fd);
       i++;
    }

    close(fd);
    return (map);
}
