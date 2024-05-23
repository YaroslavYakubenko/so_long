/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:59:29 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 20:04:28 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect_parse(t_game *data, char **map, int x, int y)
{
	if (map[y][x] == COLLECT_SYMBOL)
	{
		data->heads += 1;
		map[y][x] = 'B';
	}
	if (map[y - 1][x] == COLLECT_SYMBOL)
	{
		data->heads += 1;
		map[y - 1][x] = 'R';
	}
	if (map[y + 1][x] == COLLECT_SYMBOL)
	{
		data->heads += 1;
		map[y + 1][x] = 'R';
	}
	if (map[y][x - 1] == COLLECT_SYMBOL)
	{
		data->heads += 1;
		map[y][x - 1] = 'R';
	}
}

void	floor_parse(char **map, int x, int y)
{
	if (map[y][x] == 'R' || map[y][x] == FLOOR_SYMBOL)
		map[y][x] = 'B';
	if (map[y - 1][x] == FLOOR_SYMBOL)
		map[y - 1][x] = 'R';
	if (map[y + 1][x] == FLOOR_SYMBOL)
		map[y + 1][x] = 'R';
	if (map[y][x - 1] == FLOOR_SYMBOL)
		map[y][x - 1] = 'R';
}

void	exit_parse(t_game *data, char **map, int x, int y)
{
	if (map[y - 1][x] == 'E' || map[y + 1][x] == 'E' ||
		map[y][x - 1] == 'E' || map[y][x + 1] == 'E')
	{
		data->exit_check += 1;
		map[data->pos_exit_y][data->pos_exit_x] = WALL_SYMBOL;
	}
}
