/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:59:49 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 10:19:37 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	code_thirteen(t_data *vars, int keycode)
{
	if (vars->map[vars->pos_player_x - 1][vars->pos_player_y] == '1')
		vars->nbr_mov -= 1;
	else if (vars->map[vars->pos_player_x - 1][vars->pos_player_y] == 'C')
		collect(vars, keycode);
	else if (vars->map[vars->pos_player_x - 1][vars->pos_player_y] == 'E')
		exit_g(vars, keycode);
	else
		mov_player_up(vars, 0);
}

void	code_zero(t_data *vars, int keycode)
{
	if (vars->map[vars->pos_player_x][vars->pos_player_y - 1] == '1')
		vars->nbr_mov -= 1;
	else if (vars->map[vars->pos_player_x][vars->pos_player_y - 1] == 'C')
		collect(vars, keycode);
	else if (vars->map[vars->pos_player_x][vars->pos_player_y - 1] == 'E')
		exit_g(vars, keycode);
	else
		mov_player_left(vars, 0);
}

void	code_one(t_data *vars, int keycode)
{
	if (vars->map[vars->pos_player_x + 1][vars->pos_player_y] == '1')
		vars->nbr_mov -= 1;
	else if (vars->map[vars->pos_player_x + 1][vars->pos_player_y] == 'C')
		collect(vars, keycode);
	else if (vars->map[vars->pos_player_x + 1][vars->pos_player_y] == 'E')
		exit_g(vars, keycode);
	else
		mov_player_down(vars, 0);
}

void	code_two(t_data *vars, int keycode)
{
	if (vars->map[vars->pos_player_x][vars->pos_player_y + 1] == '1')
		vars->nbr_mov -= 1;
	else if (vars->map[vars->pos_player_x][vars->pos_player_y + 1] == 'C')
		collect(vars, keycode);
	else if (vars->map[vars->pos_player_x][vars->pos_player_y + 1] == 'E')
		exit_g(vars, keycode);
	else
		mov_player_rigth(vars, 0);
}
