/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:11:52 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/22 12:13:27 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Initialize the game struct
static void	init(t_game *game)
{
	game->mlx = NULL;
	game->width = 0;
	game->height = 0;
	game->current.x = -1;
	game->current.y = -1;
	game->current.width = 0;
	game->current.height = 0;
	game->item_collected = 0;
	game->item_max = 0;
	game->collpath = 0;
}

// Verifies if the map is valid
static void	verify_all(t_game *game)
{
	if (!game->map)
		end_failure(game, ERROR_PARSING);
	if (!game->map[game->height - 1])
		end_failure(game, ERROR_NEWLINE);
	if (!is_map_width(game) || !is_map_height(game))
		end_failure(game, ERROR_RECTANGLE);
	if (game->width > 40 || game->height > 20)
		end_failure(game, ERROR_MAPSIZE);
	if (!check_element(game->map))
		end_failure(game, ERROR_ELEMENT);
	if (!get_coordinate(game, 'P'))
		end_failure(game, ERROR_PLAYER);
	if (!get_coordinate(game, 'E'))
		end_failure(game, ERROR_EXIT);
	if (!get_collectible_num(game))
		end_failure(game, ERROR_ITEM);
	if (!verify_map(game))
		end_failure(game, ERROR_PATH);
}

// Initializes the game and loads the map
void	build(t_game *game, char **argv)
{
	init(game);
	if (!verify_extension(argv[1]))
		end_failure(game, ERROR_EXTENSION);
	game->height = count_line(argv[1]);
	game->map = pars_tacus(argv[1]);
	verify_all(game);
	game->mlx = mlx_init(game->width * IMG_SIZE, game->height * IMG_SIZE,
			"so_long", false);
	if (!game->mlx)
		end_failure(game, ERROR_MLX);
	load_xpm(game);
	texture_to_img(game);
	render_window(game);
}
