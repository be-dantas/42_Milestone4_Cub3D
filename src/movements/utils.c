#include "../../includes/cub3d.h"

int	close_window(t_access *ac)
{
	if (ac->img)
		mlx_destroy_image(ac->mlx_connection, ac->img);
	if (ac->mlx_window)
		mlx_destroy_window(ac->mlx_connection, ac->mlx_window);
	if (ac->mlx_connection)
	{
		mlx_destroy_display(ac->mlx_connection);
		free(ac->mlx_connection);
	}
	exit(0);
	return (0);
}
