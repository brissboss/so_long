/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:32:27 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 16:59:02 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "lib42/libft.h"

typedef struct s_data
{
	int		line;
	int		column;
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	char	**map_copy;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_with;
	int		img_height;
	int		pos_player_x;
	int		pos_player_y;
	int		player_point;
	int		collectible;
	int		nbr_mov;
	int		exit_end;
}	t_data;

int		main(int argc, char **argv);

// Fonction pour initialiser la map
char	**get_map(char *path_map, t_data *vars);
char	**fill_tab_map(char **map, char *path_map, t_data *vars);

// Fonction pour afficher la map
void	print_map(t_data *vars, int dir);
void	get_path(char c, char **path, int dir);

// Fonction pour deplacer le personnage
void	code_zero(t_data *vars, int keycode);
void	mov_player_left(t_data *vars, int end);
void	code_two(t_data *vars, int keycode);
void	mov_player_rigth(t_data *vars, int end);
void	code_thirteen(t_data *vars, int keycode);
void	mov_player_up(t_data *vars, int end);
void	code_one(t_data *vars, int keycode);
void	mov_player_down(t_data *vars, int end);
int		mov(int keycode, t_data *vars);

// Fonction verifier si le joueur se deplace sur une sortie ou un collectible
void	collect(t_data *vars, int keycode);
void	exit_g(t_data *vars, int keycode);

// Fonction pour check la map et renvoyer les erreur
void	check_ber(char *argv);
int		check_map(t_data *vars);
void	check_map_wall(t_data *vars);
void	check_item(t_data *vars);
void	item(t_data *vars, int *player, int *exit);

// Fonction utils
void	print_error(char *error);
int		strlen_n(char *map);

// Fonction pour le debut et la fin
void	finish(t_data *vars);

// Fonction pour gerer l'impression
char	**copy_tab(t_data *vars);
void	print_player(t_data *vars, int dir);

void	print_mov(t_data *vars);
int		destroy_win(t_data *vars);

#endif
