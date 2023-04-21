/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:48:12 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/21 16:47:47 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		build(&game, argv);
		mlx_key_hook(game.mlx, &keyhook, &game);
		mlx_close_hook(game.mlx, (mlx_closefunc) & end_success, & game);
		mlx_loop(game.mlx);
	}
	else
	{
		ft_putendl_fd(ERROR_ARGS, 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
