/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:11:52 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/06 19:06:27 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init(t_game *game)
{
	game->width = 0;
	game->height = 0;
}

void	build(t_game *game, char **argv)
{
	init(game);
	game->map = pars_tacus(argv[1]);
	if (!game->map)
	{
		ft_putendl_fd(ERROR_PARSING, 2);
		exit(EXIT_FAILURE);
	}
	game->mlx = mlx_init(get_winsize(game->map, WIDTH), get_winsize(game->map, HEIGHT), "René le bg", false);
	if (!game->mlx)
		end_failure(game, ERROR_MLX);
	load_xpm(game);
	texture_to_img(game);
	render_window(game);
}
