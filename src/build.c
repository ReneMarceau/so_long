/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:11:52 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/10 12:54:47 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	if (!check_element(game->map))
		end_failure(game, ERROR_ELEMENT);
	if (!check_element_number(game))
		end_failure(game, ERROR_ELEMENT_NUM);
	load_xpm(game);
	texture_to_img(game);
	render_window(game);
}
