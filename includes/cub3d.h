#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "../src/gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 800
# define PI 3.1415926535
# define FOV 60
# define N_RAYS 1000
# define CUB_SIZE 64

typedef struct s_game 	t_game;
typedef struct s_player	t_player;
typedef struct s_calc 	t_calc;
typedef struct s_access t_access;
typedef struct s_xpm_no	t_xpm_no;
typedef struct s_xpm_we	t_xpm_we;
typedef struct s_xpm_ea	t_xpm_ea;
typedef struct s_xpm_so	t_xpm_so;

typedef struct s_xpm_ea
{
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	char	*img_pointer;
}	t_xpm_ea;

typedef struct s_xpm_we
{
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	char	*img_pointer;
}	t_xpm_we;

typedef struct s_xpm_so
{
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	char	*img_pointer;
}	t_xpm_so;

typedef struct s_xpm_no
{
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	char	*img_pointer;
}	t_xpm_no;

typedef struct s_access
{
	void		*mlx_connection;
	void		*mlx_window;
	void		*img;
	char		*img_pointer;
	int			bpp;
	int			line_len;
	int			endian;
	t_game		*g;
	t_player	*p;
	t_calc		*calc;
	t_xpm_no	xpm_no;
	t_xpm_so	xpm_so;
	t_xpm_ea	xpm_ea;
	t_xpm_we	xpm_we;
}	t_access;

typedef struct s_game
{
	int			fd;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	int			flag_start_map;
} t_game;

typedef struct s_player
{
	float		pos_x;
	float		pos_y;
	float		up;
	float		down;
	float		left;
	float		right;
	float		arrow_left;
	float		arrow_right;
	float		pos_ang;
	float		pos_dx;
	float		pos_dy;
	float		shift;
	int			move_speed;
}	t_player;

typedef struct s_calc
{
	double		angle_diff;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	char		*px;
	int			r;
	double		ray_angle;
	double		ray_dx;
	double		ray_dy;
	double		xx;
	double		yy;
	double		dist;
	int			map_x;
	int			map_y;
	double		wall_height;
	int			wall_top;
	int			wall_bottom;
	int			column_width;
	int			column_x;
	int			side;
	double		raw_dist;
	double		wall_x;
	int			tex_x;
	int			tex_y;
}	t_calc;

// image/init_game
void	error_exit(t_access *ac, char *str, char *line);
void	init_game(t_access *ac, char *file);
int		new_tex(char *line, t_access *ac);
int		new_color(char *line, t_access *ac);
int		new_map(char *line, t_access *ac);
void	valid_game(t_access *ac);
int		valid_map(char **map);

// image/image_player.c
void	frame_update(t_access *ac);

// movements/key.c
void	create_image(t_access *ac);
void	game_keyboard(t_access *ac);

// movements/player_angle.c
void	right_angle(t_access *ac);
void	left_angle(t_access *ac);

// movements/player_mov.c
void	w_m(t_access *ac);
void	s_m(t_access *ac);
void	a_m(t_access *ac);
void	d_m(t_access *ac);

// movements/utils.c
int		close_window(t_access *ac);
void	free_close_window(t_access *ac);

// wall && obstacles
void	wall_distance_rays(t_access *ac, t_calc *calc, char **map);
void	wall_perspective_calc(t_calc *calc);
void	draw_obstacles(t_access *access, t_calc *calc);

// coloring texture
int    coloring_no(t_access *ac, t_calc *calc, int d);
int    coloring_so(t_access *ac, t_calc *calc, int d);
int    coloring_we(t_access *ac, t_calc *calc, int d);
int    coloring_ea(t_access *ac, t_calc *calc, int d);
#endif
