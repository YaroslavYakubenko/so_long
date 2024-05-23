/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:19:45 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 20:04:52 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_alloc(t_game *data, char c, int x, int y)
{
	if (c == WALL_SYMBOL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, x, y);
	else if (c == FLOOR_SYMBOL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor, x, y);
	else if (c == CHARACTER_SYMBOL)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->character, x, y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->character, x, y);
		data->i_player += 1;
	}
	else if (c == COLLECT_SYMBOL)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collectible, x, y);
		data->i_collect += 1;
	}
	else if (c == EXIT_SYMBOL)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, x, y);
		data->i_exit += 1;
	}
}

void	assign_coordinates(t_game *data, int y, int x)
{
	if (data->map_data[y][x] == CHARACTER_SYMBOL)
	{
		data->pos_player_x = x;
		data->pos_player_y = y;
	}
	else if (data->map_data[y][x] == COLLECT_SYMBOL)
	{
		data->max_score += 1;
	}
	else if (data->map_data[y][x] == EXIT_SYMBOL)
	{
		data->pos_exit_x = x;
		data->pos_exit_y = y;
	}
}

void	image_to_window(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y != data->map_height)
	{
		x = 0;
		while (x != data->map_width)
		{
			assign_coordinates(data, y, x);
			image_alloc(data, data->map_data[y][x], x * 128, y * 128);
			x++;
		}
		y++;
	}
}
