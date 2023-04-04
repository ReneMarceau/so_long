/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:49:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/04 17:27:56 by klaksi           ###   ########.fr       */
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
	P,
	C,
	DO,
	DC,
	W,
	F,
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
}	t_game;

void	build(t_game *game, char **argv);
char    **pars_tacus(char *mapfile);
void    loadxpm(t_game *game);
void    texture_to_img(t_game *game);
void	render_window(t_game *game);
void    keyhook(mlx_key_data_t keydata, void *param);

#endif
