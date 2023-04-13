/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:42:05 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/12 16:39:33 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    load_xpm(t_game *game)
{
    game->xpm[PLAYER] = mlx_load_xpm42(PLAYER_PATH);
    game->xpm[ITEM] = mlx_load_xpm42(ITEM_PATH);
    game->xpm[WALL] = mlx_load_xpm42(WALL_PATH);   
    game->xpm[FLOOR] = mlx_load_xpm42(FLOOR_PATH);
    game->xpm[EXIT_OPEN] = mlx_load_xpm42(EXIT_OPEN_PATH);
    game->xpm[EXIT_CLOSE] = mlx_load_xpm42(EXIT_CLOSE_PATH);
	if (!game->xpm[PLAYER]
		|| !game->xpm[ITEM]
		|| !game->xpm[WALL]
		|| !game->xpm[FLOOR]
		|| !game->xpm[EXIT_OPEN]
		|| !game->xpm[EXIT_CLOSE])
			end_failure(game, ERROR_XPM);
}

void    texture_to_img(t_game *game)
{
	game->img[PLAYER] = mlx_texture_to_image(game->mlx, &game->xpm[PLAYER]->texture);
	game->img[ITEM] = mlx_texture_to_image(game->mlx, &game->xpm[ITEM]->texture);
	game->img[WALL] = mlx_texture_to_image(game->mlx, &game->xpm[WALL]->texture);
	game->img[FLOOR] = mlx_texture_to_image(game->mlx, &game->xpm[FLOOR]->texture);
	game->img[EXIT_OPEN] = mlx_texture_to_image(game->mlx, &game->xpm[EXIT_OPEN]->texture);
	game->img[EXIT_CLOSE] = mlx_texture_to_image(game->mlx, &game->xpm[EXIT_CLOSE]->texture);
	if (!game->img[PLAYER]
		|| !game->img[ITEM]
		|| !game->img[WALL]
		|| !game->img[FLOOR]
		|| !game->img[EXIT_OPEN]
		|| !game->img[EXIT_CLOSE])
			end_failure(game, ERROR_IMG);
}

void	render_window(t_game *game)
{
	int	x;
	int	y;
	int	width;
	int	height;
	
	height = 0;
	y = -1;
	while (game->map[++y])
	{
		width = 0;
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player.width = width;
				game->player.height = height;
			}
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img[ITEM], width, height);
			else if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img[WALL], width, height);
			else if (game->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->img[FLOOR], width, height);
			else if (game->map[y][x] == 'E')
			{
				game->exit.width = width;
				game->exit.height = height;
			}
			width += IMG_SIZE;
		}
		height += IMG_SIZE;
	}
	mlx_image_to_window(game->mlx, game->img[EXIT_CLOSE], game->exit.width, game->exit.height);
	mlx_image_to_window(game->mlx, game->img[FLOOR], game->player.width, game->player.height);
	mlx_image_to_window(game->mlx, game->img[PLAYER], game->player.width, game->player.height);
}
