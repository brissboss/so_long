/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:06:32 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/09 14:18:27 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_tab(t_data *vars)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	result = (char **)malloc(sizeof(char *) * vars->line);
	if (!result)
		return (NULL);
	while (i <= vars->line)
	{
		result[i] = (char *)malloc(sizeof(char) * vars->column);
		if (!result[i++])
			return (NULL);
	}
	i = -1;
	while (++i < vars->line)
	{
		j = -1;
		while (++j <= vars->column)
			result[i][j] = vars->map[i][j];
	}
	return (result);
}
