#include "./includes/cub3d.h"

int	close_window(t_access *access)
{
	if (access->img)
		mlx_destroy_image(access->mlx_connection, access->img);
	if (access->mlx_window)
		mlx_destroy_window(access->mlx_connection, access->mlx_window);
	if (access->mlx_connection)
	{
		mlx_destroy_display(access->mlx_connection);
		free(access->mlx_connection);
	}
	exit(0);
	return (0);
}

int	key_config(int keycode, void *param)
{
    t_access *access;

    access = (t_access *)param;
    if (keycode == 65307)
		close_window(access);
    return (0);
}

void init (t_access access)
{
    access.player = malloc(sizeof(t_player));
    access.mlx_connection = mlx_init();
    access.mlx_window = mlx_new_window
    (access.mlx_connection, WIDTH, HEIGHT, "Cub3D");
    access.img = mlx_new_image(access.mlx_connection, WIDTH, HEIGHT);
    access.img_pointer = mlx_get_data_addr(access.img, &access.bits_per_pixel, &access.line_len, &access.endian);
    mlx_key_hook(access.mlx_window, key_config, &access);
    mlx_loop(access.mlx_connection);
}

int main()
{
    t_access access;

    init(access);
    return (0);
}