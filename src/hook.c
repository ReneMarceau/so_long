/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:14:57 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/06 18:14:51 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    keyhook(mlx_key_data_t keydata, void *param)
{ 
    t_game  *game;
	
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		end_success(game);
		exit(EXIT_SUCCESS);
	}
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
	{
		if(game->map[game->player.y - 1][game->player.x] != '1')
		{
			game->img[PLAYER]->instances[0].y -= IMG_SIZE;
			game->player.y = game->player.y - 1;
		}
	}
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
	{
		if(game->map[game->player.y + 1][game->player.x] != '1')
		{
			game->img[PLAYER]->instances[0].y += IMG_SIZE;
			game->player.y = game->player.y + 1;
		}
	}
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
	{
		if(game->map[game->player.y][game->player.x + 1] != '1')
		{
			game->img[PLAYER]->instances[0].x += IMG_SIZE;
			game->player.x = game->player.x + 1;
		}
	}
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
	{
		if(game->map[game->player.y][game->player.x - 1] != '1')
		{
			game->img[PLAYER]->instances[0].x -= IMG_SIZE;
			game->player.x = game->player.x - 1;
		}
	}
}
