#include "../includes/cub3d.h"

void	init(t_access *access)
{
	access->player = malloc(sizeof(t_player));
	access->player->pos_x = WIDTH / 2;
	access->player->pos_y = HEIGHT / 2;
	access->player->down = 0;
	access->player->up = 0;
	access->player->right = 0;
	access->player->left = 0;
	access->player->arrow_left = 0;
	access->player->arrow_right = 0;
	access->player->pos_dx = cos(access->player->pos_ang) * 0.01;
	access->player->pos_dy = sin(access->player->pos_ang) * 0.01;
	access->player->pos_ang = 0;
	access->mlx_connection = mlx_init();
	access->mlx_window = mlx_new_window(access->mlx_connection, WIDTH, HEIGHT, "Cub3D");
	access->img = mlx_new_image(access->mlx_connection, WIDTH, HEIGHT);
	access->img_pointer = mlx_get_data_addr(access->img, &access->bits_per_pixel, &access->line_len, &access->endian);
}

int	main(int argc, char **argv)
{
	t_access	*access;

	(void)argc;
	(void)argv;
	access = malloc(sizeof(t_access));
	init(access);
	game_keyboard(access);
	mlx_loop(access->mlx_connection);
	return (0);
}
