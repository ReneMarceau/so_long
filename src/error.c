/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:48:36 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/10 12:53:58 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_element_number(t_game *game)
{
    int i;
    int j;

    i = -1;
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j])
        {
            if (game->map[i][j] == 'P')
                game->element.player_num++;
            else if (game->map[i][j] == 'E')
                game->element.exit_num++;
            else if (game->map[i][j] == 'C')
                game->element.item_num++;
        }
    }
    if (game->element.player_num == 1
        && game->element.exit_num == 1
        && game->element.item_num >= 1)
        return (1);
    return (0);
}

int check_element(char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] != 'P'
                && map[i][j] != 'C'
                && map[i][j] != '1'
                && map[i][j] != '0'
                && map[i][j] != 'E'
                && map[i][j] != '\n')
                return (0);
        }
    }
    return (1);
}