/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:57:52 by yyakuben          #+#    #+#             */
/*   Updated: 2024/05/23 23:28:39 by yyakuben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_y(int fd)
{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	free(s);
	return (i);
}

void	error_fd(void)
{
	ft_printf("\n\t\033[0;31mError. Invalid read.\033[0m\n\n");
	exit_game();
}

int	exit_game(void)
{
	exit (0);
	return (0);
}

void	path_map_helper(char ***path_map, int fd, char **str, int *i)
{
	(*(path_map))[(*i)++] = ft_strdup(*str);
	free(*str);
	(*str) = get_next_line(fd);
}

char	**path_map(t_game *data, char *map)
{
	char	**path_map;
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_fd();
	data->map_height = (count_y(fd));
	path_map = ft_calloc(sizeof(char *) * (data->map_height + 1), 1);
	if (!path_map)
		return (NULL);
	close (fd);
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str)
		path_map_helper(&path_map, fd, &str, &i);
	close (fd);
	path_map[i] = NULL;
	return (path_map);
}

// char	**path_map_helper(t_game *data, int fd)
// {
// 	int		i;
// 	char	**path_map;
// 	char	*str;

// 	i = 0;
// 	path_map = ft_calloc(sizeof(char *) * (data->map_height + 1), 1);
// 	if (!path_map)
// 		return (NULL);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		path_map[i] = ft_strdup(str);
// 		free(str);
// 		str = get_next_line(fd);
// 		i++;
// 	}
// 	path_map[i] = NULL;
// 	return (path_map);
// }

// char	**path_map(t_game *data, char *map)
// {
// 	int		fd;
// 	char	**path_map;

// 	fd = open(map, O_RDONLY);
// 	if (fd < 0)
// 		error_fd();
// 	data->map_height = (count_y(fd));
// 	close (fd);
// 	fd = open(map, O_RDONLY);
// 	path_map = path_map_helper(data, fd);
// 	close (fd);
// 	return (path_map);
// }

int	empty_map(t_game *data)
{
	int	i;

	i = 0;
	if (!data || !data->map_data || !data->map_data[0]
		|| ft_strlenn(data->map_data[0]) < 3)
	{
		ft_printf("\n\t\033[0;31mError. The map is empty.\033[0m\n\n");
		if (data->map_data)
		{
			while (data->map_data[i])
			{
				free(data->map_data[i]);
				i++;
			}
			free(data->map_data);
		}
		if (data)
			free(data);
		return (1);
	}
	return (0);
}
