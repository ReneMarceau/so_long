/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:11:52 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/11 16:01:36 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	build(t_game *game, char **argv)
{
	init(game);
	game->height = count_line(argv[1]);
	game->map = pars_tacus(argv[1]);
	if (!game->map)
		end_failure(game, ERROR_PARSING);
	if (!game->map[game->height - 1])
		end_failure(game, ERROR_NEWLINE);
	if (!is_map_width(game) || !is_map_height(game))
		end_failure(game, ERROR_RECTANGLE);
	if (!check_element(game->map))
		end_failure(game, ERROR_ELEMENT);
	if (!check_element_number(game))
		end_failure(game, ERROR_ELEMENT_NUM);
	game->mlx = mlx_init(game->width * IMG_SIZE, game->height * IMG_SIZE, "René le bg", false);
	if (!game->mlx)
		end_failure(game, ERROR_MLX);
	load_xpm(game);
	texture_to_img(game);
	render_window(game);
}
