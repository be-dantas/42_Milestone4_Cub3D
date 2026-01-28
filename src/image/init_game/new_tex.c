#include "../../../includes/cub3d.h"

int	new_tex_utils(char *line, char **var, t_game *game)
{
	if (*var)
		error_exit(game, "Error file map\n");
	*var = ft_substr(line, 3, ft_strlen(line) - 4);
	if (!*var)
		error_exit(game, "Error malloc\n");
	return (1);
}

int	new_tex(char *line, t_game *game)
{
	if (game->flag_start_map == 1)
		return (0);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (new_tex_utils(line, &game->tex_no, game));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (new_tex_utils(line, &game->tex_so, game));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (new_tex_utils(line, &game->tex_we, game));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (new_tex_utils(line, &game->tex_ea, game));
	else
		return (0);
}
