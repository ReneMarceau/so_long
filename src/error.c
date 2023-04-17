/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:48:36 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/13 16:08:28 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_display_map(char **map);

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

// int verify_path(t_game *game, int row, int col)
// {
//     if (row < 0 || row >= game->height || col < 0 || col >= game->width || game->mapcopy[row][col] == '1')
//         return (0);
//     else if (game->mapcopy[row][col] == 'C')
//     {
//         game->mapcopy[row][col] = '0';
//         game->item_collected++;
//     }
//     else if (game->mapcopy[row][col] == 'E' && game->item_collected == game->item_max)
//         return (1);
//     else if (game->mapcopy[row][col] != 'E')
//         game->mapcopy[row][col] = '1';
//     return (verify_path(game, row + 1, col)
//         || verify_path(game, row - 1, col)
//         || verify_path(game, row, col + 1)
//         || verify_path(game, row, col - 1));
// }

int verify_path(t_game *game, int row, int col)
{
    (void)game;
    (void)row;
    (void)col;
    return (1);
}