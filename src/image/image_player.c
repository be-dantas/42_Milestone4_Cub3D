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

	int r;
	int k;
	double ray_angle;
	double ray_dx;
	double ray_dy;
	double xx;
	double yy;

	r = 0;
	while (r < N_RAYS)
	{
		ray_angle = access->player->pos_ang
			- (FOV * PI / 180.0) / 2
			+ r * ((FOV * PI / 180.0) / N_RAYS);

		ray_dx = cos(ray_angle);
		ray_dy = sin(ray_angle);

		xx = access->player->pos_x;
		yy = access->player->pos_y;

		k = 0;
		while (1)
		{
			int map_x = (int)(xx / CUB_SIZE);
			int map_y = (int)(yy / CUB_SIZE);
			if (map[map_y][map_x] == '1')
				break;
			px = access->img_pointer + ((int)yy * access->line_len
					+ (int)xx * (access->bits_per_pixel / 8));
			*(unsigned int *)px = 0x99FFFF;

			xx += ray_dx;
			yy += ray_dy;
			k++;
		}
		r++;
	}

}

void	frame_update(t_access *access)
{
	put_pixel_player(access);
	mlx_put_image_to_window(access->mlx_connection,
		access->mlx_window, access->img, 0, 0);
}
