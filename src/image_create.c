/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:50:04 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 20:00:56 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_error(t_game *data)
{
	if (data->wall == NULL || data->floor == NULL || data->character == NULL
		|| data->collectible == NULL || data->exit == NULL)
	{
		ft_printf("\n\t\033[0;31mError. Invalid sprite path.\033[0m\n\n");
		exit_game();
	}
}

void	path_image(t_game *data)
{
	int	i;

	i = 128;
	if (!data)
		return ;
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			PATH_WALL, &i, &i);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			PATH_FLOOR, &i, &i);
	data->character = mlx_xpm_file_to_image(data->mlx_ptr,
			PATH_CHARACTER, &i, &i);
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			PATH_COLLECTIBLE, &i, &i);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			PATH_EXIT, &i, &i);
	image_error(data);
}
