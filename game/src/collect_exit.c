/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:06:40 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 10:44:23 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect(t_data *vars, int keycode)
{
	if (keycode == 13)
		mov_player_up(vars, 0);
	else if (keycode == 0)
		mov_player_left(vars, 0);
	else if (keycode == 1)
		mov_player_down(vars, 0);
	else if (keycode == 2)
		mov_player_rigth(vars, 0);
	vars->player_point++;
}

void	exit_g(t_data *vars, int keycode)
{
	if (keycode == 13)
	{
		if (vars->player_point == vars->collectible)
			mov_player_up(vars, 1);
	}
	else if (keycode == 0)
	{
		if (vars->player_point == vars->collectible)
			mov_player_left(vars, 1);
	}
	else if (keycode == 1)
	{
		if (vars->player_point == vars->collectible)
			mov_player_down(vars, 1);
	}
	else if (keycode == 2)
	{
		if (vars->player_point == vars->collectible)
			mov_player_rigth(vars, 1);
	}
	vars->nbr_mov -= 1;
}
