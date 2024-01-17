/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:25:50 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:25:50 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/mlx.h"
#include "../ft_printf/ft_printf.h"

int	object_image_up(t_game *g)
{
	int	x;
	int	y;

	g->floor_s = mlx_xpm_file_to_image(g->mlx, "./textures/heaven.xpm", &x, &y);
	g->coin_s = mlx_xpm_file_to_image(g->mlx, "./textures/apple.xpm", &x, &y);
	g->wall_s = mlx_xpm_file_to_image(g->mlx, "./textures/hell.xpm", &x, &y);
	g->player_s = mlx_xpm_file_to_image(g->mlx, "./textures/adam.xpm", &x, &y);
	g->exit_s = mlx_xpm_file_to_image(g->mlx, "./textures/earth.xpm", &x, &y);
	if (g->floor_s == 0 || g->coin_s == 0 || g->wall_s == 0 || g->player_s == 0
		|| g->exit_s == 0)
	{
		game_exit(g);
		ft_printf("False XPM Extension");
		return (0);
	}
	return (1);
}

void	object_put(char *str, t_game *game, int y)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '0')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_s,
				x * 32, y * 32);
		else if (str[x] == '1')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall_s,
				x * 32, y * 32);
		else if (str[x] == 'C')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin_s,
				x * 32, y * 32);
		else if (str[x] == 'P')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_s,
				x * 32, y * 32);
		else if (str[x] == 'E')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit_s,
				x * 32, y * 32);
		x++;
	}
}

int	move_player(int keycode, t_game *g)
{
	int	x;
	int	y;

	x = g->player_x;
	y = g->player_y;
	if (keycode == KEY_ESC)
		game_exit(g);
	else if (keycode == KEY_W && g->map[g->player_y - 1][g->player_x] != '1')
		g->player_y--;
	else if (keycode == KEY_S && g->map[g->player_y + 1][g->player_x] != '1')
		g->player_y++;
	else if (keycode == KEY_A && g->map[g->player_y][g->player_x - 1] != '1')
		g->player_x--;
	else if (keycode == KEY_D && g->map[g->player_y][g->player_x + 1] != '1')
		g->player_x++;
	if (x != g->player_x || y != g->player_y)
	{
		player_object_update(g);
		g->step++;
		return (ft_putnbr(g->step), ft_putstr(". Step.\n"), 1);
	}
	return (1);
}
