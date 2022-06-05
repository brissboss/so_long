/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:31:22 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 17:12:51 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char *error)
{
	printf("Error : %s\n", error);
	exit (1);
}

void	print_mov(t_data *vars)
{
	ft_putstr_fd("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", 1);
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(vars->nbr_mov, 1);
}

int	destroy_win(t_data *vars)
{
	int	i;

	i = 0;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	while (i < vars->line)
	{
		free(vars->map_copy[i]);
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	free(vars->map_copy);
	exit(0);
}

int	strlen_n(char *map)
{
	int	size;

	size = 0;
	while (map[size] != '\n')
		size++;
	return (size);
}
