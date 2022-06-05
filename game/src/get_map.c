/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:37:25 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/08 17:32:06 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	get_map_column(t_data *vars, char *path_map)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(path_map, O_RDONLY);
	str = get_next_line(fd);
	while (str[i] != '\n')
		i++;
	vars->column = i;
	while (get_next_line(fd))
		i++;
	close(fd);
}

char	**fill_tab_map(char **map, char *path_map, t_data *vars)
{
	int		i;
	int		j;
	int		fd;
	char	*test;

	i = 0;
	j = -1;
	get_map_column(vars, path_map);
	fd = open(path_map, O_RDONLY);
	while (i < vars->line)
	{
		test = get_next_line(fd);
		map[i] = (char *)malloc(sizeof(char) * (ft_strlen(test) - 1));
		while (++j < vars->column)
			map[i][j] = test[j];
		if (strlen_n(test) != vars->column)
			print_error("Map is not a rectangle");
		map[i][j] = '\n';
		free(test);
		i++;
		j = -1;
	}
	close (fd);
	return (map);
}

char	**get_map(char *path_map, t_data *vars)
{
	int		fd;
	int		i;
	char	**map;

	vars->line = 0;
	i = 0;
	fd = open(path_map, O_RDONLY);
	while (get_next_line(fd))
		vars->line++;
	close (fd);
	map = (char **)malloc(sizeof(char *) * vars->line);
	if (!map)
		return (NULL);
	fill_tab_map(map, path_map, vars);
	return (map);
}
