/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:47:14 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/11 17:55:09 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_map(t_game *game)
{
    int i;

    i = 0;
    while (i < game->height)
        free(game->map[i++]);
    free(game->map);
}

int	end_success(t_game *game)
{
    free_map(game);
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
    exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	end_failure(t_game *game, char *error_message)
{
	ft_putendl_fd(error_message, 2);
	free_map(game);
    if (game->mlx)
    {
        mlx_close_window(game->mlx);
        mlx_terminate(game->mlx);
    }
	exit (EXIT_FAILURE);
}
