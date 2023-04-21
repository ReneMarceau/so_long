/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:19:46 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/21 16:43:51 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Gets the number of collectibles in the map
int	get_collectible_num(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				game->item_max++;
		}
	}
	if (game->item_max < 1)
		return (0);
	return (1);
}

static void	set_coordinate(t_game *game, char element, int i, int j)
{
	if (element == 'P')
	{
		game->player.x = j;
		game->player.y = i;
	}
	else if (element == 'E')
	{
		game->exit.x = j;
		game->exit.y = i;
	}
}

// Gets the coordinates of the player and the exit
int	get_coordinate(t_game *game, char element)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == element)
				set_coordinate(game, element, i, j);
			return (1);
		}
	}
	return (0);
}

// Calculates the width of the map
int	is_map_width(t_game *game)
{
	int	top_width;
	int	bottom_width;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j] && game->map[i][j] == '1')
		j++;
	top_width = j;
	i = game->height - 1;
	j = 0;
	while (game->map[i][j] && game->map[i][j] == '1')
		j++;
	bottom_width = j;
	if (top_width != bottom_width)
		return (0);
	game->width = top_width;
	return (1);
}

// Calculates the height of the map
int	is_map_height(t_game *game)
{
	int	left_height;
	int	right_height;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] && game->map[i][j] == '1')
		i++;
	left_height = i;
	i = 0;
	j = game->width - 1;
	while (game->map[i] && game->map[i][j] == '1')
		i++;
	right_height = i;
	if (left_height != right_height)
		return (0);
	return (1);
}
