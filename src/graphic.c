/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:42:05 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/04 19:09:13 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    loadxpm(t_game *game)
{
    game->xpm[P] = mlx_load_xpm42("./sprites/player.xpm42");
    game->xpm[DC] = mlx_load_xpm42("./sprites/door_close.xpm42");
    game->xpm[DO] = mlx_load_xpm42("./sprites/door_open.xpm42");
    game->xpm[F] = mlx_load_xpm42("./sprites/floor.xpm42");
    game->xpm[C] = mlx_load_xpm42("./sprites/item.xpm42");
    game->xpm[W] = mlx_load_xpm42("./sprites/wall.xpm42");   
}

void    texture_to_img(t_game *game)
{
	game->img[P] = mlx_texture_to_image(game->mlx, &game->xpm[P]->texture);
	game->img[DC] = mlx_texture_to_image(game->mlx, &game->xpm[DC]->texture);
	game->img[DO] = mlx_texture_to_image(game->mlx, &game->xpm[DO]->texture);
	game->img[F] = mlx_texture_to_image(game->mlx, &game->xpm[F]->texture);
	game->img[C] = mlx_texture_to_image(game->mlx, &game->xpm[C]->texture);
	game->img[W] = mlx_texture_to_image(game->mlx, &game->xpm[W]->texture);
}

void	render_window(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map[y])
	{
		game->width = 0;
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				game->player.width = game->width;
				game->player.height = game->height;
			}
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img[DC], game->width, game->height);
			else if (game->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->img[F], game->width, game->height);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img[C], game->width, game->height);
			else if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img[W], game->width, game->height);
			x++;
			game->width += 64;
		}
		y++;
		game->height += 64;
	}
	mlx_image_to_window(game->mlx, game->img[F], game->player.width, game->player.height);
	mlx_image_to_window(game->mlx, game->img[P], game->player.width, game->player.height);
}
