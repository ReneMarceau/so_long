/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:14:57 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/04 17:43:54 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    keyhook(mlx_key_data_t keydata, void *param)
{ 
    t_game  *game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->img[P]->instances[0].y -= 64;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->img[P]->instances[0].y += 64;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->img[P]->instances[0].x += 64;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->img[P]->instances[0].x -= 64;
}
