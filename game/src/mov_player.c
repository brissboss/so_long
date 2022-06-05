/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:46:56 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 16:56:02 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mov_player_up(t_data *vars, int end)
{
	int		new_play_x;
	int		new_play_y;
	char	temp;

	vars->map[vars->pos_player_x - 1][vars->pos_player_y] = '0';
	new_play_x = vars->pos_player_x - 1;
	new_play_y = vars->pos_player_y;
	temp = vars->map[vars->pos_player_x][vars->pos_player_y];
	vars->map[vars->pos_player_x][vars->pos_player_y]
		= vars->map[new_play_x][vars->pos_player_y];
	vars->map[new_play_x][vars->pos_player_y] = temp;
	vars->pos_player_x = new_play_x;
	print_player(vars, 0);
	if (end == 1)
		finish(vars);
}

void	mov_player_down(t_data *vars, int end)
{
	int		new_play_x;
	int		new_play_y;
	char	temp;

	vars->map[vars->pos_player_x + 1][vars->pos_player_y] = '0';
	new_play_x = vars->pos_player_x + 1;
	new_play_y = vars->pos_player_y;
	temp = vars->map[vars->pos_player_x][vars->pos_player_y];
	vars->map[vars->pos_player_x][vars->pos_player_y]
		= vars->map[new_play_x][vars->pos_player_y];
	vars->map[new_play_x][vars->pos_player_y] = temp;
	vars->pos_player_x = new_play_x;
	print_player(vars, 2);
	if (end == 1)
		finish(vars);
}

void	mov_player_rigth(t_data *vars, int end)
{
	int		new_play_x;
	int		new_play_y;
	char	temp;

	vars->map[vars->pos_player_x][vars->pos_player_y + 1] = '0';
	new_play_x = vars->pos_player_x;
	new_play_y = vars->pos_player_y + 1;
	temp = vars->map[vars->pos_player_x][vars->pos_player_y];
	vars->map[vars->pos_player_x][vars->pos_player_y]
		= vars->map[vars->pos_player_x][new_play_y];
	vars->map[vars->pos_player_x][new_play_y] = temp;
	vars->pos_player_y = new_play_y;
	print_player(vars, 3);
	if (end == 1)
		finish(vars);
}

void	mov_player_left(t_data *vars, int end)
{
	int		new_play_x;
	int		new_play_y;
	char	temp;

	vars->map[vars->pos_player_x][vars->pos_player_y - 1] = '0';
	new_play_x = vars->pos_player_x;
	new_play_y = vars->pos_player_y - 1;
	temp = vars->map[vars->pos_player_x][vars->pos_player_y];
	vars->map[vars->pos_player_x][vars->pos_player_y]
		= vars->map[vars->pos_player_x][new_play_y];
	vars->map[vars->pos_player_x][new_play_y] = temp;
	vars->pos_player_y = new_play_y;
	print_player(vars, 1);
	if (end == 1)
		finish(vars);
}
