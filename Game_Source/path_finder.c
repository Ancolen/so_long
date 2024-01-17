/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:26:22 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:26:22 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	path_finder(t_game *game)
{
	game->copy_map = copy_map(game->map);
	game->coin_cnt_copy = game->coin_count;
	recursive_p(game, game->player_y, game->player_x);
	if (game->coin_cnt_copy != 0)
		return (ft_mapcopy_free(game), 0);
	if (player_exit_control(game) == 0)
		return (ft_mapcopy_free(game), 0);
	return (ft_mapcopy_free(game), 1);
}

int	player_exit_control(t_game *game)
{
	int	count;

	count = 0;
	if (game->copy_map[game->player_e_x + 1]
		[game->player_e_y] == 'P' || game->copy_map[game->player_e_x + 1]
		[game->player_e_y] == '1')
		count++;
	if (game->copy_map[game->player_e_x - 1]
		[game->player_e_y] == 'P' || game->copy_map[game->player_e_x - 1]
		[game->player_e_y] == '1')
		count++;
	if (game->copy_map[game->player_e_x]
		[game->player_e_y + 1] == 'P' || game->copy_map[game->player_e_x]
		[game->player_e_y + 1] == '1')
		count++;
	if (game->copy_map[game->player_e_x]
		[game->player_e_y - 1] == 'P' || game->copy_map[game->player_e_x]
		[game->player_e_y - 1] == '1')
		count++;
	if (count == 4)
		return (1);
	return (0);
}

static void	coin_control(t_game *map, int y, int x)
{
	if (map->copy_map[y][x] == 'C' || map->copy_map[y][x] == 'E')
		map->coin_cnt_copy--;
	map->copy_map[y][x] = 'P';
}

void	recursive_p(t_game *map, int y, int x)
{
	if (map->copy_map[y][x + 1] == '0' || map->copy_map[y][x + 1] == 'C'
		|| map->copy_map[y][x + 1] == 'E')
	{
		coin_control(map, y, x + 1);
		recursive_p(map, y, x + 1);
	}
	if (map->copy_map[y][x - 1] == '0' || map->copy_map[y][x - 1] == 'C'
	|| map->copy_map[y][x - 1] == 'E')
	{
		coin_control(map, y, x - 1);
		recursive_p(map, y, x - 1);
	}
	if (map->copy_map[y + 1][x] == '0' || map->copy_map[y + 1][x] == 'C'
		|| map->copy_map[y + 1][x] == 'E')
	{
		coin_control(map, y + 1, x);
		recursive_p(map, y + 1, x);
	}
	if (map->copy_map[y - 1][x] == '0' || map->copy_map[y - 1][x] == 'C'
		|| map->copy_map[y - 1][x] == 'E')
	{
		coin_control(map, y - 1, x);
		recursive_p(map, y - 1, x);
	}
}
