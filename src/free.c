/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:47:14 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/21 13:33:14 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Free the 2D array map
void	free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}

// Free, close the game and exit if success
int	end_success(t_game *game)
{
    free_map(game->map);
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
    exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

// Free, close the game and exit and throw an error message if failure
void	end_failure(t_game *game, char *error_message)
{
	ft_putendl_fd(error_message, 2);
    if (game->map)
        free_map(game->map);
    if (game->mlx)
    {
        mlx_close_window(game->mlx);
        mlx_terminate(game->mlx);
    }
	exit (EXIT_FAILURE);
}
