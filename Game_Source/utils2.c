/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:26:43 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:26:43 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	write (1, &"0123456789"[nbr % 10], 1);
}

void	ft_mapcopy_free(t_game *game)
{
	int		i;

	i = 0;
	while (game->copy_map[i])
	{
		free(game->copy_map[i]);
		i++;
	}
	free(game->copy_map);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_map_free(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
