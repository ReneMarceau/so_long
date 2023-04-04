/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:11:52 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/04 18:54:49 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define WIDTH 1280
#define HEIGHT 720

static void	init(t_game *game)
{
	game->width = 0;
	game->height = 0;
}

void	build(t_game *game, char **argv)
{
	init(game);
;	game->map = pars_tacus(argv[1]);
	game->mlx = mlx_init(WIDTH, HEIGHT, "kamélia la bg", false);
	if (!game->mlx)
	{
		ft_putendl_fd("Error\nmlx_init failed", 2);
		exit(2);
	}
	loadxpm(game);
	texture_to_img(game);
	render_window(game);
}
