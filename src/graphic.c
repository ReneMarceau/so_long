/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:42:05 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/21 13:21:54 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Loads xpm files
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

// Converts xpm files to images
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

// Renders each element of the map
static void render_element(t_game *game)
{
	if (game->map[game->current.y][game->current.x] == 'P')
	{
		game->player.width = game->current.width;
		game->player.height = game->current.height;
	}
	else if (game->map[game->current.y][game->current.x] == 'C')
		mlx_image_to_window(game->mlx, game->img[ITEM], game->current.width, game->current.height);
	else if (game->map[game->current.y][game->current.x] == '1')
		mlx_image_to_window(game->mlx, game->img[WALL], game->current.width, game->current.height);
	else if (game->map[game->current.y][game->current.x] == '0')
		mlx_image_to_window(game->mlx, game->img[FLOOR], game->current.width, game->current.height);
	else if (game->map[game->current.y][game->current.x] == 'E')
	{
		game->exit.width = game->current.width;
		game->exit.height = game->current.height;
	}
}

// Renders the map to the window
void	render_window(t_game *game)
{
	while (game->map[++game->current.y])
	{
		game->current.width = 0;
		game->current.x = -1;
		while (game->map[game->current.y][++game->current.x])
		{
			render_element(game);
			game->current.width += IMG_SIZE;
		}
		game->current.height += IMG_SIZE;
	}
	mlx_image_to_window(game->mlx, game->img[EXIT_CLOSE], game->exit.width, game->exit.height);
	mlx_image_to_window(game->mlx, game->img[FLOOR], game->player.width, game->player.height);
	mlx_image_to_window(game->mlx, game->img[PLAYER], game->player.width, game->player.height);
}
