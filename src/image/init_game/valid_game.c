#include "../../../includes/cub3d.h"

// int	valid_map(char **map)
// {

// }

int	valid_game(t_access *ac)
{
	if (!ac->g->tex_no || !ac->g->tex_so
			|| !ac->g->tex_we || !ac->g->tex_ea
			|| ac->g->floor_color == -1
			|| ac->g->ceiling_color == -1
			|| ac->g->flag_start_map == 0)
		return (0);
	// if (!valid_map(ac->g->map))
	// 	return (0);
	return (1);
}
