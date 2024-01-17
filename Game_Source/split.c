/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:26:35 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:26:35 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < word)
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (ft_free(strs, j));
		while (s[i] == c)
			i++;
		strs[j] = ft_substr(s, i, ft_size_word(s, c, i));
		if (!(strs[j]))
			return (ft_free(strs, j));
		i += ft_size_word(s, c, i);
	}
	strs[j] = 0;
	return (strs);
}
