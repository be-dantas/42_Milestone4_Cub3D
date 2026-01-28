#include "../includes/cub3d.h"

void	init_access(t_access *access)
{
	access->mlx_connection = mlx_init();
	access->mlx_window = mlx_new_window(access->mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	create_image(access);
}

void	init_player(t_player *player)
{
	player->up = 0;
	player->down = 0;
	player->left = 0;
	player->right = 0;
	player->arrow_left = 0;
	player->arrow_right = 0;
	player->pos_ang = 0;
	player->pos_dx = cos(player->pos_ang) * 0.01;
	player->pos_dy = sin(player->pos_ang) * 0.01;
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_access	access;
	t_player	player;

	if (argc != 2)
		return (1);
	access.player = &player;
	access.game = &game;
	game.player = &player;
	init_game(&game, argv[1]);
	init_access(&access);
	init_player(&player);
	game_keyboard(&access);
	mlx_hook(access.mlx_window, 17, 0, close_window, &access);
	mlx_loop(access.mlx_connection);
	return (0);
}
