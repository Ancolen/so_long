/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:26:11 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:26:11 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../get_next_line/get_next_line.h"

int	check_map(t_game *game)
{
	int	i;

	i = 0;
	game->map_h = array_count(game->map);
	game->map_w = ft_strlen(game->map[0]);
	while (game->map[i + 1])
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[i + 1]))
		{
			return (0);
		}
		i++;
	}
	if (ft_strlen(game->map[0]) == array_count(game->map))
	{
		return (0);
	}
	return (1);
}

static int	second_wall_control(t_game *game)
{
	int	j;
	int	size;

	size = array_count(game->map) - 1;
	j = 0;
	while (game->map[0][j])
	{
		if (game->map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (game->map[size][j])
	{
		if (game->map[size][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	control_wall(t_game *game)
{
	int		i;
	int		size;
	int		len;

	if (second_wall_control(game) == 0)
		return (0);
	i = 0;
	size = array_count(game->map) - 1;
	while (game->map[i][0] && i < size)
	{
		len = ft_strlen(game->map[i]) - 1;
		if (game->map[i][0] != '1')
			return (0);
		if (game->map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	member_while(t_game *game,
									int i, int *exit, int *player_start)
{
	int	j;

	j = -1;
	while (game->map[i][++j])
	{
		if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
			game->coin_count++;
		if (game->map[i][j] == 'E')
		{
			game->player_e_x = i;
			game->player_e_y = j;
			(*exit)++;
		}
		if (game->map[i][j] == 'P')
		{
			(*player_start)++;
			game->player_y = i;
			game->player_x = j;
		}
		if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
		game->map[i][j] != 'P' &&
		game->map[i][j] != 'C' && game->map[i][j] != 'E')
			return (0);
	}
	return (1);
}

int	control_member(t_game *game)
{
	int	i;
	int	exit;
	int	player_start;

	i = 0;
	exit = 0;
	player_start = 0;
	game->coin_count = 0;
	while (game->map[i])
	{
		if (member_while(game, i, &exit, &player_start) == 0)
			return (0);
		i++;
	}
	if (exit == 1 && player_start == 1 && game->coin_count != 0)
		return (1);
	return (0);
}
