/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:19:09 by bedantas          #+#    #+#             */
/*   Updated: 2026/02/04 15:19:10 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	error_exit(t_access *ac, char *str, char *line)
{
	if (line)
		free(line);
	if (ac->g->tex_no)
		free(ac->g->tex_no);
	if (ac->g->tex_so)
		free(ac->g->tex_so);
	if (ac->g->tex_we)
		free(ac->g->tex_we);
	if (ac->g->tex_ea)
		free(ac->g->tex_ea);
	if (ac->g->map)
		ft_free_array(ac->g->map);
	if (ac->g->fd >= 0)
		close(ac->g->fd);
	if (ac->mlx_connection)
	{
		mlx_destroy_display(ac->mlx_connection);
		free(ac->mlx_connection);
	}
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

static int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	new_variable(t_access *ac, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (empty_line(line))
		{
			if (ac->g->flag_start_map)
				error_exit(ac, "Error file map\n", line);
		}
		else
		{
			if (!new_tex(line, ac) && !new_color(line, ac)
				&& !new_map(line, ac))
				error_exit(ac, "Error file map\n", line);
		}
		free(line);
	}
	close(fd);
}

static void	new_pos_x_y(t_access *ac, int i)
{
	int	j;

	while (ac->g->map[i])
	{
		j = 0;
		while (!ft_strchr("NSEW", ac->g->map[i][j]))
			j++;
		if (ac->g->map[i][j] == 'N' || ac->g->map[i][j] == 'S'
			|| ac->g->map[i][j] == 'W' || ac->g->map[i][j] == 'E')
		{
			if (ac->g->map[i][j] == 'S')
				ac->p->pos_ang = PI / 2;
			if (ac->g->map[i][j] == 'N')
				ac->p->pos_ang = 3 * PI / 2;
			if (ac->g->map[i][j] == 'E')
				ac->p->pos_ang = 2 * PI;
			if (ac->g->map[i][j] == 'W')
				ac->p->pos_ang = PI;
			break ;
		}
		i++;
	}
	ac->p->pos_x = (float)((j + 1) * 64) - 32;
	ac->p->pos_y = (float)((i + 1) * 64) - 32;
}

void	init_game(t_access *ac, char *file)
{
	ac->g->tex_no = NULL;
	ac->g->tex_so = NULL;
	ac->g->tex_we = NULL;
	ac->g->tex_ea = NULL;
	ac->g->floor_color = -1;
	ac->g->ceiling_color = -1;
	ac->g->map = ft_calloc(1, sizeof(char *));
	ac->g->flag_start_map = 0;
	ac->g->fd = open(file, O_RDONLY);
	if (ac->g->fd < 0)
		error_exit(ac, "Error opening file\n", NULL);
	new_variable(ac, ac->g->fd);
	valid_game(ac);
	new_pos_x_y(ac, 0);
}
