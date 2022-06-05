/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:34:01 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 10:09:57 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_ber(char *argv)
{
	char	*ber;
	int		i;
	int		j;

	ber = ".ber";
	i = ft_strlen(argv);
	i -= 4;
	j = 0;
	while (argv[i])
		if (argv[i++] != ber[j++])
			print_error("not a .ber file");
}

void	check_map_wall(t_data *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x != vars->column)
		if (vars->map[y][x++] != '1')
			print_error("Map is not surrounded by a wall");
	while (y < (vars->line - 1))
	{
		x = 0;
		while (x != vars->column)
		{
			if (x < 1 || x == (vars->column - 1))
				if (vars->map[y][x] != '1')
					print_error("Map is not surrounded by a wall");
			x++;
		}
		y++;
	}
	x = 0;
	while (x != vars->column)
		if (vars->map[y][x++] != '1')
			print_error("Map is not surrounded by a wall");
}

void	item(t_data *vars, int *player, int *exit)
{
	int	x;
	int	y;

	y = 0;
	while (++y < (vars->line - 1))
	{
		x = 0;
		while (++x < vars->column)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->pos_player_x = y;
				vars->pos_player_y = x;
				*player += 1;
			}
			else if (vars->map[y][x] == 'C')
				vars->collectible++;
			else if (vars->map[y][x] == 'E')
				*exit += 1;
		}
	}
}

void	check_item(t_data *vars)
{
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	vars->collectible = 0;
	item(vars, &player, &exit);
	if (player != 1)
		print_error("No or to few player");
	else if (vars->collectible <= 0)
		print_error("No collectible in the map");
	else if (exit != 1)
		print_error("No or to few exit in the map");
}

int	check_map(t_data *vars)
{
	check_map_wall(vars);
	check_item(vars);
	return (0);
}
