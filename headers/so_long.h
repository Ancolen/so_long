/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:27:09 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/10 13:27:09 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct so_long
{
	void	*mlx;
	void	*mlx_win;
	void	*floor_s;
	void	*coin_s;
	void	*wall_s;
	void	*player_s;
	void	*exit_s;
	char	**map;
	char	*map_swap;
	char	**copy_map;
	int		map_size;
	int		coin_count;
	int		map_h;
	int		map_w;
	int		step;
	int		coin_cnt_copy;
	int		player_x;
	int		player_y;
	int		player_e_x;
	int		player_e_y;

}			t_game;

//START
int		move_player(int keycode, t_game *g);
int		object_image_up(t_game *g);

//MAP
int		controls(t_game *particles);
int		map_open(char *map_name, t_game *particles);
int		fill_map(t_game *particles, int fd);
int		check_map(t_game *particles);
int		check_map_name(char *map_name);
int		control_wall(t_game *particles);
int		control_member(t_game *particles);
int		map_update(t_game *game);
void	object_put(char *str, t_game *game, int y);
int		game_exit(t_game *game);
void	player_object_update(t_game *game);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);
int		map_calculate(t_game *particles);
int		mlx_operations(t_game *particles);

//UTILS
int		ft_strlen(const char *str);
int		array_count(char **two_dimensional_array);
int		ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	**copy_map(char **array);
void	ft_map_free(t_game *particles);

//SPLIT UTILS
int		ft_count_word(char const *s, char c);
int		ft_size_word(char const *s, char c, int i);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_free(char **strs, int j);

//PATH FINDER
int		path_finder(t_game *particles);
int		player_exit_control(t_game *particles);
void	recursive_p(t_game *map, int y, int x);
void	ft_mapcopy_free(t_game *particles);

#endif
