/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:14:57 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/17 14:43:12 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	movements(t_game *game)
{
	if ((game->map[game->player.y][game->player.x] == 'E') && (game->item_collected == game->item_max))
	{
		end_success(game);
	}
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->img[FLOOR], game->player.width, game->player.height);
		game->item_collected++;
		game->map[game->player.y][game->player.x] = '0';
		if (game->item_collected == game->item_max)
		{
			mlx_image_to_window(game->mlx, game->img[EXIT_OPEN], game->exit.width, game->exit.height);
		}
	}	
}

void    keyhook(mlx_key_data_t keydata, void *param)
{ 
    t_game  *game;
	
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		end_success(game);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
	{
		move_up(game);
	}
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
	{
		move_down(game);
	}
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
	{
		move_right(game);
	}
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
	{
		move_left(game);
	}
}
