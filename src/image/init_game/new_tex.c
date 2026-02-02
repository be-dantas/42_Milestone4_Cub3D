#include "../../../includes/cub3d.h"

static int	new_tex_utils(char *line, char **var, t_access *ac)
{
	if (*var)
		error_exit(ac, "Error file map\n", line);
	*var = ft_substr(line, 3, ft_strlen(line) - 4);
	if (!*var)
		error_exit(ac, "Error malloc\n", line);
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
