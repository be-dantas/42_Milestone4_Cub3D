#include "../../includes/cub3d.h"

void	put_pixel_player(t_access *access)
{
		char *map[] = {
		"111111111111111",
		"100000000000001",
		"100011000100001",
		"100011000010101",
		"100011000011001",
		"100000000110001",
		"100010011010001",
		"111111111111111",
		NULL
	};

	char	*px;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (map[i] != NULL)
	{
		draw_map(map, i, 0, access);
		i++;
	}
	px = access->img_pointer + ((int)access->player->pos_y * access->line_len
			+ (int)access->player->pos_x * (access->bits_per_pixel / 8));
	*(unsigned int *)px = 0xFFFFFF;
}

void	frame_update(t_access *access)
{
	put_pixel_player(access);
	mlx_put_image_to_window(access->mlx_connection,
		access->mlx_window, access->img, 0, 0);
}
