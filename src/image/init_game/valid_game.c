#include "../../../includes/cub3d.h"

// int	valid_map(char **map)
// {

// }

int	valid_game(t_game *game)
{
	if (!game->tex_no || !game->tex_so
			|| !game->tex_we || !game->tex_ea
			|| game->floor_color == -1
			|| game->ceiling_color == -1
			|| game->flag_start_map == 0)
		return (0);
	// if (!valid_map(game->map))
	// 	return (0);
	return (1);
}
