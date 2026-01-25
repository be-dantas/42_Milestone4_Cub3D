#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_player t_player;

typedef struct s_access
{
	void	*mlx_connection;
	void	*mlx_window;
	void	*img;
	char	*img_pointer;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	t_player *player;
}	t_access;

typedef struct s_player
{
	float		pos_x;
	float		pos_y;
	float		left;
	float		right;
	float		up;
	float		down;
} t_player;


#endif