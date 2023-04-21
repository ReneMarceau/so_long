/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:48:36 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/21 16:13:12 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Checks if the mapfile has the correct extension (.ber)
int	verify_extension(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] == 'r'
		&& argv[i - 2] == 'e'
		&& argv[i - 3] == 'b'
		&& argv[i - 4] == '.')
		return (1);
	return (0);
}

// Checks if the map has only right elements inside it
int	check_element(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != 'P'
				&& map[i][j] != 'C'
				&& map[i][j] != '1'
				&& map[i][j] != '0'
				&& map[i][j] != 'E'
				&& map[i][j] != '\n')
				return (0);
		}
	}
	return (1);
}

// Try to find a possible path from the player to the exit
static void	verify_path(t_game *game, char **map, int row, int col)
{
	if ((row >= 0 && row < game->height) && (col >= 0 && col < game->width))
	{
		if (ft_strchr("CE", map[row][col]))
		{
			if (map[row][col] == 'E')
				map[row][col] = '1';
			game->collpath++;
		}
		if (!ft_strchr("C0P", map[row][col]))
			return ;
		map[row][col] = 'S';
		verify_path(game, map, row + 1, col);
		verify_path(game, map, row - 1, col);
		verify_path(game, map, row, col + 1);
		verify_path(game, map, row, col - 1);
	}
	return ;
}

// Verifies if there is a valid path
int	verify_map(t_game *game)
{
	static char	**map;

	map = copymap(game->map);
	verify_path(game, map, game->player.y, game->player.x);
	free_map(map);
	return (game->collpath == game->item_max + 1);
}
