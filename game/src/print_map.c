/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:03:26 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 17:08:00 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_path(char c, char **path, int dir)
{
	if (c == '1')
		*path = "./sprite/wall.xpm";
	else if (c == '0')
		*path = "./sprite/floor.xpm";
	else if (c == 'P')
	{
		if (dir == 0)
			*path = "./sprite/player_u.xpm";
		else if (dir == 1)
			*path = "./sprite/player_l.xpm";
		else if (dir == 2)
			*path = "./sprite/player_d.xpm";
		else
			*path = "./sprite/player_r.xpm";
	}
	else if (c == 'E')
		*path = "./sprite/exit.xpm";
	else if (c == 'C')
		*path = "./sprite/collect.xpm";
}

void	print_map(t_data *vars, int dir)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	path = "./sprite/wall.xpm";
	while (i < vars->line)
	{
		j = 0;
		while (j < vars->column)
		{
			get_path(vars->map[i][j], &path, dir);
			vars->img = mlx_xpm_file_to_image(vars->mlx, path, &vars->img_with,
					&vars->img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				j * 31, i * 31);
			j++;
		}
		i++;
	}
}

void	print_player(t_data *vars, int dir)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (i < vars->line)
	{
		j = 0;
		while (j < vars->column)
		{
			if (vars->map_copy[i][j] != vars->map[i][j])
			{
				vars->map_copy[i][j] = vars->map[i][j];
				get_path(vars->map_copy[i][j], &path, dir);
				vars->img = mlx_xpm_file_to_image(vars->mlx, path,
						&vars->img_with, &vars->img_height);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
					j * 31, i * 31);
				mlx_destroy_image(vars->mlx, vars->img);
			}
			j++;
		}
		i++;
	}
}
