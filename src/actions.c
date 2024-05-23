/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:29:14 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 20:03:30 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	char_picture(int press, t_game *data)
{
	int	x;
	int	y;

	y = data->pos_player_y;
	x = data->pos_player_x;
	if (data->map_data[y][x] == COLLECT_SYMBOL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->character, x * 128, y * 128);
	else if (press == PRESS_A || press == PRESS_D || press == PRESS_S
		|| press == PRESS_W)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->character,
			x * 128, y * 128);
	return (0);
}

void	shadow_change(t_game *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		data->pos_player_x * 128, data->pos_player_y * 128);
}

void	step_change(t_game *data, int i)
{
	if (i == 1)
	{
		data->pos_player_y -= 1;
		data->steps += 1;
	}
	else if (i == 2)
	{
		data->pos_player_x -= 1;
		data->steps += 1;
	}
	else if (i == 3)
	{
		data->pos_player_y += 1;
		data->steps += 1;
	}
	else if (i == 4)
	{
		data->pos_player_x += 1;
		data->steps += 1;
	}
}

void	char_actions(int press, t_game *data)
{
	int	x;
	int	y;

	x = data->pos_player_x;
	y = data->pos_player_y;
	shadow_change(data);
	if (press == PRESS_W && data->map_data[y - 1][x] != WALL_SYMBOL &&
		data->map_data[y - 1][x] != EXIT_SYMBOL)
		step_change(data, 1);
	else if (press == PRESS_A && data->map_data[y][x - 1] != WALL_SYMBOL &&
		data->map_data[y][x - 1] != EXIT_SYMBOL)
		step_change(data, 2);
	else if (press == PRESS_S && data->map_data[y + 1][x] != WALL_SYMBOL &&
		data->map_data[y + 1][x] != EXIT_SYMBOL)
		step_change(data, 3);
	else if (press == PRESS_D && data->map_data[y][x + 1] != WALL_SYMBOL &&
		data->map_data[y][x + 1] != EXIT_SYMBOL)
		step_change(data, 4);
	ft_printf("Number of steps done: %d\n", data->steps);
}

int	actions(int press, t_game *data)
{
	if ((press == PRESS_W || press == PRESS_A || press == PRESS_S
			|| press == PRESS_D) && check_complete(data) != 0)
	{
		char_actions(press, data);
		char_picture(press, data);
		check_collectible(data);
		if (check_complete(data) == 0)
		{
			ft_printf("\n\t\033[1;32mCongratulation. You won.\033[0m\n\n");
			exit_game();
		}
	}
	if (press == PRESS_ESC)
		exit_game();
	return (0);
}
