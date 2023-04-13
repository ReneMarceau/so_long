/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:49:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/12 18:22:48 by rmarceau         ###   ########.fr       */
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
	char		**map;
	char		**mapcopy;
	int			width;
	int			height;
	int			item_collected;
	int			item_max;
}	t_game;

// Initialisation
void	init(t_game *game);
void	build(t_game *game, char **argv);
int 	count_line(char *mapfile);
char    **pars_tacus(char *mapfile);
void    load_xpm(t_game *game);
void    texture_to_img(t_game *game);
void	render_window(t_game *game);
int 	get_coordinate(t_game *game, char element);
int 	get_collectible_num(t_game *game);

// Keyhook
void    keyhook(mlx_key_data_t keydata, void *param);

// Free
int	    end_success(t_game *game);
void	end_failure(t_game *game, char *error_message);

//Error
int check_element(char **map);
int	check_element_number(t_game *game);
int is_map_width(t_game *game);
int is_map_height(t_game *game);
int verify_path(t_game *game, int row, int col);

//Utils
char **copymap(char **map);

#endif
