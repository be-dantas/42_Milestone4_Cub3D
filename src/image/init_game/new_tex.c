/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:19:55 by bedantas          #+#    #+#             */
/*   Updated: 2026/02/05 14:53:02 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	new_tex_utils(char *line, char **var, t_access *ac)
{
	int	fd_temp;

	if (*var)
		error_exit(ac, "Error file map\n", line);
	*var = ft_substr(line, 3, ft_strlen(line) - 4);
	if (!*var)
		error_exit(ac, "Error malloc\n", line);
	fd_temp = open(*var, O_RDONLY);
	if (fd_temp < 0)
		error_exit(ac, "Error opening file texture\n", line);
	close(fd_temp);
	return (1);
}

int	new_tex(char *line, t_access *ac)
{
	if (ac->g->flag_start_map == 1)
		return (0);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (new_tex_utils(line, &ac->g->tex_no, ac));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (new_tex_utils(line, &ac->g->tex_so, ac));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (new_tex_utils(line, &ac->g->tex_we, ac));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (new_tex_utils(line, &ac->g->tex_ea, ac));
	else
		return (0);
}
