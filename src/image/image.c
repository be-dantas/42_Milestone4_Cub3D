#include "../../includes/cub3d.h"

void	put_pixel_player(t_access *access)
{
	char	*px;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			px = access->img_pointer + (y * access->line_len + x
					* (access->bits_per_pixel / 8));
			*(unsigned int *)px = 0;
			x++;
		}
		y++;
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