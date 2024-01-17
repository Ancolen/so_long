/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:26:04 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:26:04 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/mlx.h"
#include <fcntl.h>
#include "../ft_printf/ft_printf.h"

int	mlx_operations(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == 0)
		return (0);
	if (object_image_up(game) == 0)
		return (0);
	else
	{
		game->mlx_win = mlx_new_window(game->mlx,
				game->map_w * 32, game->map_h * 32, "so_long");
		if (game->mlx_win == 0)
			return (game_exit(game), 0);
		mlx_key_hook(game->mlx_win, move_player, game);
		mlx_hook(game->mlx_win, 17, 0, game_exit, game);
		mlx_loop_hook(game->mlx, map_update, game);
		mlx_loop(game->mlx);
	}
	return (1);
}

int	controls(t_game *game)
{
	if (check_map(game) == 0)
		return (ft_printf("Map Error"), 0);
	if (control_wall(game) == 0)
		return (ft_printf("Map Wall Error"), 0);
	if (control_member(game) == 0)
		return (ft_printf("Map Component Error"), 0);
	if (path_finder(game) == 0)
		return (ft_printf("Map Path Error"), 0);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	if (ac != 2)
		return (ft_printf("Must be the map name"), 0);
	game.step = 0;
	fd = open(av[1], O_RDONLY);
	if (check_map_name(av[1]) == 0)
		return (ft_printf("Map Name Error"), 0);
	if (fill_map(&game, fd) == 0)
		return (ft_printf("Map Fill Error"), 0);
	if (map_calculate(&game) == 0)
		return (ft_printf("Map Calculate Error"), 0);
	if (controls(&game) == 0)
		return (ft_map_free(&game), 0);
	if (mlx_operations(&game) == 0)
		return (ft_map_free(&game), 0);
	return (ft_map_free(&game), 0);
}
