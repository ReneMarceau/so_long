/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:14:57 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/04 19:12:07 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    keyhook(mlx_key_data_t keydata, void *param)
{ 
    t_game  *game;
	
	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		if(game->map[game->player.y - 1][game->player.x] != '1')
		{
			game->img[P]->instances[0].y -= 64;
			game->player.y = game->player.y - 1;
		}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		
		if(game->map[game->player.y + 1][game->player.x] != '1')
		{
			game->img[P]->instances[0].y += 64;
			game->player.y = game->player.y + 1;
		}
		
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		
		if(game->map[game->player.y][game->player.x + 1] != '1')
		{
			game->img[P]->instances[0].x += 64;
			game->player.x = game->player.x + 1;
		}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		
			if(game->map[game->player.y][game->player.x - 1] != '1')
		{
			game->img[P]->instances[0].x -= 64;
			game->player.x = game->player.x - 1;
		}
}
