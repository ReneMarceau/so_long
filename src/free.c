/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:47:14 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/06 18:09:21 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}

int	end_success(t_game *game)
{
    free_map(game->map);
	mlx_close_window(game->mlx);
    mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

void	end_failure(t_game *game, char *error_message)
{
	ft_putendl_fd(error_message, 2);
	free_map(game->map);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit (EXIT_FAILURE);
}
