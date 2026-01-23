#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_access
{
	void	*mlx_connection;
	void	*mlx_window;
	void	*img;
	char	*img_pointer;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_access;

#endif