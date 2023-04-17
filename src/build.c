/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:11:52 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/13 16:36:26 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	build(t_game *game, char **argv)
{
	init(game);
	game->height = count_line(argv[1]);
	game->map = pars_tacus(argv[1]);
	game->mapcopy = copymap(game->map);
	if (!game->map || !game->mapcopy)
		end_failure(game, ERROR_PARSING);
	if (!game->map[game->height - 1])
		end_failure(game, ERROR_NEWLINE);
	if (!is_map_width(game) || !is_map_height(game))
		end_failure(game, ERROR_RECTANGLE);
	if (!check_element(game->map))
		end_failure(game, ERROR_ELEMENT);
	if (!get_coordinate(game, 'P'))
		end_failure(game, ERROR_PLAYER);
	if (!get_coordinate(game, 'E'))
		end_failure(game, ERROR_EXIT);
	if (!get_collectible_num(game))
		end_failure(game, ERROR_ITEM);
	if (!verify_path(game, game->player.y, game->player.x))
		end_failure(game, ERROR_PATH);
	game->mlx = mlx_init(game->width * IMG_SIZE, game->height * IMG_SIZE, "Kam la bg", false);
	if (!game->mlx)
		end_failure(game, ERROR_MLX);
	if (!verify_ext(argv[1]))
		end_failure(game, ERROR_FILE);
		
	load_xpm(game);
	texture_to_img(game);
	render_window(game);
}
