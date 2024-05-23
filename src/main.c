/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:26:37 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 20:14:17 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_mlx_init(t_game *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map_width * 128, data->map_height * 128, "so_long");
	if (!data->win_ptr)
		free(data->mlx_ptr);
	return ;
}

int	main(int ac, char **av)
{
	t_game	*data;

	if (ac != 2)
	{
		ft_printf("\n\t\033[0;31mWrong amount of arguments\033[0m\n\n");
		return (0);
	}
	data = calloc(sizeof(t_game), 1);
	data->map_data = path_map(data, av[1]);
	if (empty_map(data) == 1)
		exit_game();
	data->map_copy = path_map(data, av[1]);
	data->map_width = ft_strlenn(data->map_data[0]) - 1;
	// data->mlx_ptr = mlx_init();
	// if (!data->mlx_ptr)
	// 	return (1);
	// data->win_ptr = mlx_new_window(data->mlx_ptr,
	// 		data->map_width * 128, data->map_height * 128, "so_long");
	// if (!data->win_ptr)
	// 	return (free(data->mlx_ptr), 1);
	ft_mlx_init(data);
	path_image(data);
	image_to_window(data);
	handle_error(data);
	mlx_hook(data->win_ptr, DestroyNotify,
		KeyPressMask, exit_game, data);
	mlx_key_hook(data->win_ptr, actions, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
