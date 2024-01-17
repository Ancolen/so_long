/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:26:17 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:26:17 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../get_next_line/get_next_line.h"

int	check_map_name(char *map_name)
{
	int		size;

	size = ft_strlen(map_name);
	if (size < 4)
		return (0);
	size -= 4;
	while (map_name[size++])
		if (ft_strchr(".ber", map_name[size]) == 0)
			return (0);
	return (1);
}

int	fill_map(t_game *game, int fd)
{
	char	*line;
	char	*swap;

	line = get_next_line(fd);
	if (!line || fd < 0)
		return (0);
	game->map_swap = ft_strdup(line);
	free(line);
	if (!game->map_swap)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\0')
			break ;
		swap = ft_strjoin(game->map_swap, line);
		free(line);
		if (!swap || ft_strlen(game->map_swap) < 4)
			return (free(game->map_swap), 0);
		free(game->map_swap);
		game->map_swap = swap;
	}
	return (1);
}

int	map_calculate(t_game *game)
{
	game->map = ft_split(game->map_swap, '\n');
	if (game->map == 0)
	{
		free(game->map_swap);
		return (0);
	}
	free(game->map_swap);
	return (1);
}
