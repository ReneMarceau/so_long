/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:11:52 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/03 16:40:48 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define WIDTH 1280
#define HEIGHT 720

static void	init(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->x = 0;
	game->y = 0;
}

void	build(t_game *game, char **argv)
{
	init(game);
	game->map = pars_tacus(argv[1]);
	game->mlx = mlx_init(WIDTH, HEIGHT, "René le bg", false);
	if (!game->mlx)
	{
		ft_putendl_fd("Error\nmlx_init failed", 2);
		exit(2);
	}
}
