/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:42:05 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/03 16:49:01 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    loadxpm (t_game *game)
{
    game->xpm[PLAYER] = mlx_load_xpm42("../sprites/player.xpm42");
    game->xpm[DOOR_CLOSE] = mlx_load_xpm42("../sprites/door_close.xpm42");
    game->xpm[DOOR_OPEN] = mlx_load_xpm42("../sprites/door_open.xpm42");
    game->xpm[FLOOR] = mlx_load_xpm42("../sprites/floor.xpm42");
    game->xpm[COLLECTIBLE] = mlx_load_xpm42("../sprites/item.xpm42");
    game->xpm[WALL] = mlx_load_xpm42("../sprites/wall.xpm42");   
}

void    texture_to_img(t_game *game)
{
	game->img[PLAYER] = mlx_texture_to_image(game->mlx, &game->xpm[PLAYER]->texture);
	game->img[DOOR_CLOSE] = mlx_texture_to_image(game->mlx, &game->xpm[DOOR_CLOSE]->texture);
	game->img[DOOR_OPEN] = mlx_texture_to_image(game->mlx, &game->xpm[DOOR_OPEN]->texture);
	game->img[FLOOR] = mlx_texture_to_image(game->mlx, &game->xpm[FLOOR]->texture);
	game->img[COLLECTIBLE] = mlx_texture_to_image(game->mlx, &game->xpm[COLLECTIBLE]->texture);
	game->img[WALL] = mlx_texture_to_image(game->mlx, &game->xpm[WALL]->texture);
}
