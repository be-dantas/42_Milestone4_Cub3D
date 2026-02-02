#include "../../../includes/cub3d.h"

static void	trate_color_error(char *color, t_access *ac, char *line, char **split_color)
{
	if (!split_color)
	{
		free(color);
		error_exit(ac, "Error malloc\n", line);
	}
	free(color);
	ft_free_array(split_color);
	error_exit(ac, "Error file map\n", line);
}

static int	trate_color(char *color, t_access *ac, char *line)
{
	char	**split_color;
	int		r;
	int		g;
	int		b;

	split_color = ft_split(color, ',');
	if (!split_color)
		trate_color_error(color, ac, line, split_color);
	if (ft_strlen_array(split_color) != 3)
		trate_color_error(color, ac, line, split_color);
	r = ft_atoi(split_color[0]);
	g = ft_atoi(split_color[1]);
	b = ft_atoi(split_color[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		trate_color_error(color, ac, line, split_color);
	ft_free_array(split_color);
	return (r << 16 | g << 8 | b);
}

int	new_color(char *line, t_access *ac)
{
	char	*temp;

	temp = NULL;
	if (ac->g->flag_start_map == 1)
		return (0);
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (ac->g->floor_color != -1)
			error_exit(ac, "Error file map\n", line);
		temp = ft_substr(line, 2, ft_strlen(line) - 3);
		ac->g->floor_color = trate_color(temp, ac, line);
		free(temp);
		return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (ac->g->ceiling_color != -1)
			error_exit(ac, "Error file map\n", line);
		temp = ft_substr(line, 2, ft_strlen(line) - 3);
		ac->g->ceiling_color = trate_color(temp, ac, line);
		free(temp);
		return (1);
	}
	else
		return (0);
}
