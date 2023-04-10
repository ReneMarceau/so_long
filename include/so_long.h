/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:49:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/10 12:54:13 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "./error.h"

# include <stdio.h>
# include <fcntl.h>

# define IMG_SIZE 64
# define WIDTH 0
# define HEIGHT 1

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

typedef struct s_count
{
	int	player_num;
	int	exit_num;
	int	item_num;
}	t_count;

typedef struct s_game
{
	mlx_t		*mlx;
	xpm_t		*xpm[IMG_COUNTER];
	mlx_image_t	*img[IMG_COUNTER];
	t_coord		player;
	t_coord		exit;
	char		**map;
	t_count		element;
	// Useless?
	int			width;
	int			height;
}	t_game;

// Initialisation
void	init(t_game *game);
void	build(t_game *game, char **argv);
char    **pars_tacus(char *mapfile);
void    load_xpm(t_game *game);
void    texture_to_img(t_game *game);
void	render_window(t_game *game);
int 	get_winsize(char **map, int flag);

// Keyhook
void    keyhook(mlx_key_data_t keydata, void *param);

// Free
int	    end_success(t_game *game);
void	end_failure(t_game *game, char *error_message);
void    free_map(char **map);

//Error
int check_element(char **map);
int	check_element_number(t_game *game);

#endif
