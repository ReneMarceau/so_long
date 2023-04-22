/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:11:02 by klaksi            #+#    #+#             */
/*   Updated: 2023/04/22 12:57:50 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Handles movement functionality
void	movements(t_game *game)
{
	ft_printf("Movement %d\n",++game->print_move);
	if ((game->map[game->player.y][game->player.x] == 'E')
			&& (game->item_collected == game->item_max))
	{
		ft_printf("\033[0;95mCONGRATULATIONS!! YOU DID IT IN %d MOVEMENTS\n",++game->print_move);
			end_success(game);
	}
	else if (game->map[game->player.y][game->player.x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->img[FLOOR], game->player.width,
			game->player.height);
		mlx_image_to_window(game->mlx, game->img[PLAYER], game->player.width,
			game->player.height);
		game->item_collected++;
		game->map[game->player.y][game->player.x] = '0';
		if (game->item_collected == game->item_max)
			mlx_image_to_window(game->mlx, game->img[EXIT_OPEN],
				game->exit.width,
				game->exit.height);
	}
}

// Handles left movement
void	move_left(t_game *game)
{
	if (game->map[game->player.y][game->player.x - 1] != '1')
	{
		game->img[PLAYER]->instances[game->item_collected].x -= IMG_SIZE;
		game->player.x--;
		game->player.width -= IMG_SIZE;
		movements (game);
	}
}

// Handles right movement
void	move_right(t_game *game)
{
	if (game->map[game->player.y][game->player.x + 1] != '1')
	{
		game->img[PLAYER]->instances[game->item_collected].x += IMG_SIZE;
		game->player.x++;
		game->player.width += IMG_SIZE;
		movements(game);
	}
}

// Handles down movement
void	move_down(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] != '1')
	{
		game->img[PLAYER]->instances[game->item_collected].y += IMG_SIZE;
		game->player.y++;
		game->player.height += IMG_SIZE;
		movements(game);
	}
}

// Handles up movement
void	move_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
		game->img[PLAYER]->instances[game->item_collected].y -= IMG_SIZE;
		game->player.y--;
		game->player.height -= IMG_SIZE;
		movements(game);
	}
}
