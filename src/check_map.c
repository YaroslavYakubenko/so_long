/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:01:27 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 20:04:13 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_spread(t_game *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y != data->map_height - 1)
	{
		x = 0;
		while (x != data->map_width)
		{
			if (x == data->map_width - 1)
			{
				y++;
				break ;
			}
			if (map[y][x] != 'R')
				x++;
			else if (map[y][x] == 'R')
				return (0);
		}
	}
	return (1);
}

char	**second_spread(t_game *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y][x] != 'R')
	{
		if (x != data->map_width)
			x++;
		else
		{
			y++;
			x = 0;
		}
	}
	while (map[y][x] != WALL_SYMBOL)
	{
		collect_parse(data, map, x, y);
		floor_parse(map, x, y);
		exit_parse(data, map, x, y);
		x++;
	}
	return (map);
}

char	**first_spread(t_game *data, char **map, int x, int y)
{
	while (map[y][x] != WALL_SYMBOL)
	{
		collect_parse(data, map, x, y);
		floor_parse(map, x, y);
		exit_parse(data, map, x, y);
		x++;
	}
	return (map);
}

int	check_map(t_game *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map_copy;
	x = data->pos_player_x;
	y = data->pos_player_y;
	first_spread(data, map, x, y);
	while (data->exit_check != 1 || data->heads != data->max_score)
	{
		if (check_spread(data, map) == 0)
			second_spread(data, map);
		else if (check_spread(data, map) == 1)
			return (1);
	}
	return (0);
}
