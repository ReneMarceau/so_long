/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:19:46 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/19 18:31:46 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init(t_game *game)
{
    game->mlx = NULL;
    game->width = 0;
    game->height = 0;
    game->item_collected = 0;
    game->item_max = 0;
    game->collpath = 0;
}

int get_collectible_num(t_game *game)
{
    int i;
    int j;

    i = -1;
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j])
        {
            if (game->map[i][j] == 'C')
                game->item_max++;
        }
    }
    if (game->item_max < 1)
        return (0);
    return (1);
}

int get_coordinate(t_game *game, char element)
{
    int i;
    int j;

    i = -1;
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j])
        {
            if (game->map[i][j] == element)
            {
                if (element == 'P')
                {
                    game->player.x = j;
                    game->player.y = i;
                }
                else if (element == 'E')
                {
                    game->exit.x = j;
                    game->exit.y = i;
                }
                return (1);
            }
        }
    }
    return (0);
}

int is_map_width(t_game *game)
{
    int top_width;
    int bottom_width;
    int i;
    int j;

    i = 0;
    j = 0;
    while (game->map[i][j] && game->map[i][j] == '1')
        j++;
    top_width = j;
	i = game->height - 1;
    j = 0;
    while (game->map[i][j] && game->map[i][j] == '1')
        j++;
    bottom_width = j;
    if (top_width != bottom_width)
        return (0);
    game->width = top_width;
    return (1);
}

int is_map_height(t_game *game)
{
    int left_height;
    int right_height;
    int i;
    int j;

    i = 0;
    j = 0;
    while (game->map[i] && game->map[i][j] == '1')
        i++;
    left_height = i;
    i = 0;
    j = game->width - 1;
    while (game->map[i] && game->map[i][j] == '1')
        i++;
    right_height = i;
    if (left_height != right_height)
        return (0);
    return (1);
}

int    verify_ext(char *argv)
{
    int i;
    i = 0;
    while (argv[i])
        i++;
        
    if (argv[i - 1] == 'r' && argv[i - 2] == 'e' && argv[i - 3] == 'b' && argv[i - 4] == '.')
        return (1);
    return (0);
}
