/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:26:39 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:26:39 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**copy_map(char **array)
{
	int		i;
	int		j;
	char	**copy_array;

	copy_array = (char **)malloc(sizeof(char *) * array_count(array) + 1);
	i = 0;
	j = 0;
	if (!copy_array)
		return (NULL);
	while (array[i])
	{
		j = 0;
		copy_array[i] = malloc(sizeof(char *) * ft_strlen(array[i]) + 1);
		if (!(copy_array[i]))
			return (ft_free(copy_array, i), NULL);
		while (array[i][j])
		{
			copy_array[i][j] = array[i][j];
			j++;
		}
		copy_array[i][j] = '\0';
		i++;
	}
	copy_array[i] = NULL;
	return (copy_array);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

int	array_count(char **two_dimensional_array)
{
	int	i;

	i = 0;
	while (two_dimensional_array[i])
		i++;
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
