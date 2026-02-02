#include "../../includes/cub3d.h"

static void	free_close_window(t_access *ac)
{
	if (ac->g->tex_no)
		free(ac->g->tex_no);
	if (ac->g->tex_so)
		free(ac->g->tex_so);
	if (ac->g->tex_we)
		free(ac->g->tex_we);
	if (ac->g->tex_ea)
		free(ac->g->tex_ea);
	if (ac->g->map)
		ft_free_array(ac->g->map);
}

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
	free_close_window(ac);
	exit(0);
	return (0);
}
