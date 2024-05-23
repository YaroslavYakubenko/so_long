/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 22:25:28 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 20:03:52 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	win_state(t_game *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->character,
		data->pos_exit_x * 128, data->pos_exit_y * 128);
}

int	check_complete(t_game *data)
{
	int	x;
	int	y;

	y = data->pos_player_y;
	x = data->pos_player_x;
	if (data->score == data->max_score)
	{
		if (data->map_data[y][x] == OPEN_SYMBOL)
			return (0);
	}
	return (1);
}

void	check_collectible(t_game *data)
{
	int	y;
	int	x;

	y = data->pos_player_y;
	x = data->pos_player_x;
	if (data->map_data[y][x] == COLLECT_SYMBOL)
	{
		data->score += 1;
		data->map_data[y][x] = FLOOR_SYMBOL;
		if (data->score == data->max_score)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,
				data->pos_exit_x * 128, data->pos_exit_y * 128);
			data->map_data[data->pos_exit_y][data->pos_exit_x] = OPEN_SYMBOL;
		}
	}
}
