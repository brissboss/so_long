/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:33:22 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 14:19:02 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	mov(int keycode, t_data *vars)
{
	int	mov_nbr_save;

	mov_nbr_save = vars->nbr_mov;
	if (vars->exit_end == 0)
	{
		if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
			vars->nbr_mov += 1;
		if (keycode == 13)
			code_thirteen(vars, keycode);
		else if (keycode == 0)
			code_zero(vars, keycode);
		else if (keycode == 1)
			code_one(vars, keycode);
		else if (keycode == 2)
			code_two(vars, keycode);
		else if (keycode == 53)
			destroy_win(vars);
		if (vars->nbr_mov != mov_nbr_save && keycode != 53)
			print_mov(vars);
	}
	else
		if (keycode == 53)
			destroy_win(vars);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	vars;

	vars.exit_end = 0;
	if (argc != 2)
		print_error("No or to few argument");
	check_ber(argv[1]);
	vars.player_point = 0;
	vars.map = get_map(argv[1], &vars);
	check_map(&vars);
	vars.map_copy = copy_tab(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.column * 31), (vars.line * 31),
			"So Long");
	mlx_hook(vars.win, 2, 1L << 0, mov, &vars);
	mlx_hook(vars.win, 17, 1L << 17, destroy_win, &vars);
	print_map(&vars, 3);
	mlx_loop(vars.mlx);
	return (0);
}
