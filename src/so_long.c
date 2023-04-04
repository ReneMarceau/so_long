/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:48:12 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/04 17:18:59 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_display_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		build(&game, argv);
		ft_display_map(game.map);
		mlx_key_hook(game.mlx, &keyhook, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_printf("ERROR\n");
	return (0);
}
