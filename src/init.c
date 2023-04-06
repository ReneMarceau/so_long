/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:19:46 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/06 18:30:34 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int get_winsize(char **map, int flag)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        while (map[i][j])
            j++;
        i++;
    }
    if (flag == WIDTH)
        return ((j - 1) * IMG_SIZE);
    else if (flag == HEIGHT)
        return (i * IMG_SIZE);
    return (0);
}
