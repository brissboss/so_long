/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:01:36 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 17:13:41 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	finish(t_data *vars)
{
	char	*path;

	path = "./sprite/finish.xpm";
	mlx_destroy_window(vars->mlx, vars->win);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 512, 512, "So Long");
	vars->img = mlx_xpm_file_to_image(vars->mlx, path, &vars->img_with,
			&vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	vars->exit_end = 1;
	mlx_hook(vars->win, 2, 1L << 0, mov, vars);
	mlx_hook(vars->win, 17, 1L << 17, destroy_win, vars);
	mlx_loop(vars->mlx);
}
