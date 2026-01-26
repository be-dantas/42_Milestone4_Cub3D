#include "../../includes/cub3d.h"

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
	if (access->player)
		free(access->player);
	if (access)
		free(access);
	exit(0);
	return (0);
}
