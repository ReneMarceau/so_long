/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:11:02 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/17 14:44:39 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    move_left(t_game *game)
{
    if(game->map[game->player.y][game->player.x - 1] != '1')
    {
        game->img[PLAYER]->instances[0].x -= IMG_SIZE;
        game->player.x = game->player.x - 1;
        game->player.width -= IMG_SIZE;
        movements (game);
    }
}

void    move_right(t_game *game)
{
	if(game->map[game->player.y][game->player.x + 1] != '1')
	{
		game->img[PLAYER]->instances[0].x += IMG_SIZE;
		game->player.x = game->player.x + 1;
		game->player.width += IMG_SIZE;
		movements(game);
	}
}

void	move_down(t_game *game)
{
	if(game->map[game->player.y + 1][game->player.x] != '1')
	{
		game->img[PLAYER]->instances[0].y += IMG_SIZE;
		game->player.y = game->player.y + 1;
		game->player.height += IMG_SIZE;
		movements(game);
	}
}

void	move_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
		game->img[PLAYER]->instances[0].y -= IMG_SIZE;
		game->player.y--;
		game->player.height -= IMG_SIZE;
		movements(game);
	}
}
