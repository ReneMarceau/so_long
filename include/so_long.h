/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:49:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/03 16:39:14 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <fcntl.h>

# define ERROR "ERROR\n"

typedef enum mlx_images
{
	PLAYER,
	COLLECTIBLE,
	DOOR_OPEN,
	DOOR_CLOSE,
	WALL,
	FLOOR,
	IMG_COUNTER
}	t_mlx_images;

typedef struct s_game
{
	mlx_t		*mlx;
	xpm_t		*xpm[IMG_COUNTER];
	mlx_image_t	*img[IMG_COUNTER];
	char		**map;
	int			width;
	int			height;
	int			x;
	int			y;
}	t_game;

void	build(t_game *game, char **argv)
char    **pars_tacus(char *mapfile);

#endif