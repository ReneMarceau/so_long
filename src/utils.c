/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:50:14 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/21 13:27:19 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Count the number of lines in the map file
int count_line(char *mapfile)
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
            ft_putendl_fd(ERROR_FILE, 2);
            close(fd);
            exit(EXIT_FAILURE);
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

// Copy the map to a new 2D array of strings
char **copymap(char **map)
{
    char **newmap;
    int i;

    i = 0;
    while (map[i])
        i++;
    newmap = (char **)ft_calloc(i + 1, sizeof(char *));
    if (!newmap)
        return (NULL);
    i = -1;
    while (map[++i])
        newmap[i] = ft_strdup(map[i]);
    return (newmap);
}
