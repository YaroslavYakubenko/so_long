/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:30:12 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 20:07:36 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <time.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "inc/libft/libft.h"
# include "inc/get_next_line/get_next_line.h"
# include "inc/ft_printf/ft_printf.h"
# include "MiniLibX/mlx.h"

# define WALL_SYMBOL		49
# define FLOOR_SYMBOL		48
# define COLLECT_SYMBOL		67
# define CHARACTER_SYMBOL	80
# define EXIT_SYMBOL		69
# define OPEN_SYMBOL		79
# define ENEMY_SYMBOL		77

# define PATH_CHARACTER "textures/character/Character00.xpm"
# define PATH_COLLECTIBLE "textures/collectible/Collectible00.xpm"
# define PATH_ENEMY "textures/enemy/Enemy00.xpm"
# define PATH_EXIT "textures/exit/Black_hole00.xpm"
# define PATH_EXIT1 "textures/exit/Black_hole01.xpm"
# define PATH_EXIT2 "textures/exit/Black_hole02.xpm"
# define PATH_EXIT3 "textures/exit/Black_hole03.xpm"
# define PATH_FLOOR "textures/floor/Floor00.xpm"
# define PATH_WALL "textures/wall/Wall00.xpm"

# define PRESS_W		'w'
# define PRESS_S		's'
# define PRESS_A		'a'
# define PRESS_D		'd'
# define PRESS_ESC		65307

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map_data;
	char	**map_copy;
	int		map_height;
	int		map_width;
	void	*wall;
	void	*floor;
	void	*character;
	void	*enemy;
	void	*collectible;
	void	*exit;
	void	*success;
	int		steps;
	int		x;
	int		y;
	int		i_player;
	int		i_exit;
	int		i_collect;
	int		pos_player_x;
	int		pos_player_y;
	int		max_score;
	int		score;
	int		pos_exit_x;
	int		pos_exit_y;
	int		exit_check;
	int		heads;
}	t_game;

int		count_y(int fd);
void	error_fd(void);
int		exit_game(void);
char	**path_map(t_game *data, char *map);
void	path_image(t_game *data);
void	image_error(t_game *data);
void	image_to_window(t_game *data);
void	assign_coordinates(t_game *data, int y, int x);
void	image_alloc(t_game *data, char c, int y, int x);
int		check_map(t_game *data);
char	**first_spread(t_game *data, char **map, int x, int y);
char	**second_spread(t_game *data, char **map);
int		check_spread(t_game *data, char **map);
void	collect_parse(t_game *data, char **map, int x, int y);
void	floor_parse(char **map, int x, int y);
void	exit_parse(t_game *data, char **map, int x, int y);
int		handle_error(t_game *data);
int		walls_error(t_game *data);
int		symbols_error(t_game *data);
int		index_error(t_game *data);
int		error_map_size(t_game *data);
int		actions(int press, t_game *data);
void	step_change(t_game *data, int i);
void	shadow_change(t_game *data);
int		char_picture(int press, t_game *data);
void	check_collectible(t_game *data);
int		check_complete(t_game *data);
void	char_actions(int press, t_game *data);
int		empty_map(t_game *data);

#endif