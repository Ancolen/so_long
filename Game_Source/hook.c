/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:25:58 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:25:58 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/mlx.h"

int	map_update(t_game *game)
{
	int	y;

	y = 0;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (game->map[y])
	{
		object_put(game->map[y], game, y);
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_s,
		game->player_x * 32, game->player_y * 32);
	return (1);
}

int	game_exit(t_game *game)
{
	if (game)
		ft_map_free(game);
	if (game->coin_s)
		mlx_destroy_image(game->mlx, game->coin_s);
	if (game->player_s)
		mlx_destroy_image(game->mlx, game->player_s);
	if (game->wall_s)
		mlx_destroy_image(game->mlx, game->wall_s);
	if (game->exit_s)
		mlx_destroy_image(game->mlx, game->exit_s);
	if (game->floor_s)
		mlx_destroy_image(game->mlx, game->floor_s);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

void	player_object_update(t_game *game)
{
	if (game->coin_count == 1
		&& game->map[game->player_y][game->player_x] == 'E')
		game_exit(game);
	else if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->coin_count--;
		game->map[game->player_y][game->player_x] = '0';
	}
}
