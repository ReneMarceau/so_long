/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:49:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/21 16:51:01 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "./error.h"

# include <fcntl.h>

# define IMG_SIZE 64

# define PLAYER_PATH "./sprites/player.xpm42"
# define ITEM_PATH "./sprites/item.xpm42"
# define WALL_PATH "./sprites/wall.xpm42"
# define FLOOR_PATH "./sprites/floor.xpm42"
# define EXIT_OPEN_PATH "./sprites/exit_open.xpm42"
# define EXIT_CLOSE_PATH "./sprites/exit_close.xpm42"

typedef enum mlx_images
{
	PLAYER,
	ITEM,
	WALL,
	FLOOR,
	EXIT_OPEN,
	EXIT_CLOSE,
	IMG_COUNTER
}	t_mlx_images;

typedef struct s_coord
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_coord;

typedef struct s_game
{
	mlx_t		*mlx;
	xpm_t		*xpm[IMG_COUNTER];
	mlx_image_t	*img[IMG_COUNTER];
	t_coord		player;
	t_coord		exit;
	t_coord		current;
	char		**map;
	int			width;
	int			height;
	int			item_collected;
	int			item_max;
	int			collpath;
}	t_game;

// Initialisation
void	build(t_game *game, char **argv);
char	**pars_tacus(char *mapfile);
void	load_xpm(t_game *game);
void	texture_to_img(t_game *game);
void	render_window(t_game *game);
int		get_coordinate(t_game *game, char element);
int		get_collectible_num(t_game *game);

// Keyhook
void	keyhook(mlx_key_data_t keydata, void *param);
void	movements(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);

// Free
void	free_map(char **map);
int		end_success(t_game *game);
void	end_failure(t_game *game, char *error_message);

//Error
int		check_element(char **map);
int		is_map_width(t_game *game);
int		is_map_height(t_game *game);
int		verify_extension(char *argv);
int		verify_map(t_game *game);

//Utils
int		count_line(char *mapfile);
char	**copymap(char **map);

#endif
