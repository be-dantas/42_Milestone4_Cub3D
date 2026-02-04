/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:19:58 by bedantas          #+#    #+#             */
/*   Updated: 2026/02/04 15:19:59 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	valid_player(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (0);
	return (1);
}

void	valid_game(t_access *ac)
{
	if (!ac->g->tex_no || !ac->g->tex_so
		|| !ac->g->tex_we || !ac->g->tex_ea
		|| ac->g->floor_color == -1
		|| ac->g->ceiling_color == -1
		|| ac->g->flag_start_map == 0)
		error_exit(ac, "Error file map\n", NULL);
	else if (!valid_player(ac->g->map) || !valid_map(ac->g->map))
		error_exit(ac, "Error map\n", NULL);
}
