#include "../includes/cub3d.h"

void	init(t_access *access)
{
	access->player = malloc(sizeof(t_player));
	access->player->pos_x = SCREEN_WIDTH / 4;
	access->player->pos_y = SCREEN_HEIGHT / 4;
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
	access->mlx_window = mlx_new_window(access->mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	create_image(access);
}

int	main(int argc, char **argv)
{
	t_access	*access;

	(void)argc;
	(void)argv;
	access = malloc(sizeof(t_access));
	init(access);
	game_keyboard(access);
	mlx_hook(access->mlx_window, 17, 0, close_window, access);
	mlx_loop(access->mlx_connection);
	return (0);
}
