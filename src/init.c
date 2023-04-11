/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:19:46 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/11 16:50:57 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init(t_game *game)
{
    game->mlx = NULL;
    game->width = 0;
    game->height = 0;
    game->element.player_num = 0;
    game->element.exit_num = 0;
    game->element.item_num = 0;
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
