/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:24:09 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 20:01:56 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_map_size(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		if (ft_strlenn(data->map_data[0]) == ft_strlenn(data->map_data[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	index_error(t_game *data)
{
	if (data->i_player != 1)
	{
		ft_printf("\n\t\033[0;31mWrong number of elements.\033[0m\n\n");
		return (1);
	}
	else if (data->i_exit != 1)
	{
		ft_printf("\n\t\033[0;31mWrong number of elements.\033[0m\n\n");
		return (1);
	}
	else if (data->i_collect < 1)
	{
		ft_printf("\n\t\033[0;31mWrong number of elements.\033[0m\n\n");
		return (1);
	}
	else
		return (0);
}

int	symbols_error(t_game *data)
{
	int		x;
	int		y;
	char	**map;

	map = data->map_data;
	y = 0;
	while (y != data->map_height)
	{
		x = 0;
		while (x != data->map_width)
		{
			if (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'P' ||
				map[y][x] == 'C' || map[y][x] == 'E')
				x++;
			else
				return (1);
		}
		y++;
	}
	return (0);
}

int	walls_error(t_game *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != data->map_width)
	{
		if (data->map_data[y][x] != WALL_SYMBOL ||
			data->map_data[data->map_height - 1][x] != WALL_SYMBOL)
			return (1);
		else
			x++;
	}
	y = 1;
	while (y != data->map_height - 1)
	{
		if (data->map_data[y][0] != WALL_SYMBOL ||
			data->map_data[y][x - 1] != WALL_SYMBOL)
			return (1);
		else
			y++;
	}
	return (0);
}

int	handle_error(t_game *data)
{
	if (index_error(data) == 1)
		exit_game();
	else if (error_map_size(data) == 1)
	{
		ft_printf("\n\t\033[0;31mThe map size is wrong.\033[0m\n\n");
		exit_game();
	}
	else if (symbols_error(data) == 1)
	{
		ft_printf("\n\t\033[0;31mWrong map characters.\033[0m\n\n");
		exit_game();
	}
	else if (walls_error(data) == 1)
	{
		ft_printf("\n\t\033[0;31mWrong wall allocation.\033[0m\n\n");
		exit_game();
	}
	else if (check_map(data) == 1)
	{
		ft_printf("\n\t\033[0;31mThis quest can't be completed.\033[0m\n\n");
		exit_game();
	}
	return (0);
}
