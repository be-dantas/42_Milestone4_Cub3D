#include "../../includes/cub3d.h"

int	coloring_no(t_access *ac, t_calc *calc, int d)
{
	int	color;

	color = 0;
	calc->tex_x = (int)(calc->wall_x * ac->xpm_no.width);
	calc->tex_y = ((d * ac->xpm_no.height) / calc->wall_height) / 256;
	if (calc->tex_y < 0)
		calc->tex_y = 0;
	if (calc->tex_y >= ac->xpm_no.height)
		calc->tex_y = ac->xpm_no.height - 1;
	if (calc->tex_x < 0)
		calc->tex_x = 0;
	if (calc->tex_x >= ac->xpm_no.width)
		calc->tex_x = ac->xpm_no.width - 1;
	color = *(int *)(ac->xpm_no.img_pointer
			+ calc->tex_y * ac->xpm_no.line_len
			+ calc->tex_x * (ac->xpm_no.bpp / 8));
	return (color);
}

int	coloring_so(t_access *ac, t_calc *calc, int d)
{
	int	color;

	color = 0;
	calc->tex_x = (int)(calc->wall_x * ac->xpm_so.width);
	calc->tex_y = ((d * ac->xpm_so.height) / calc->wall_height) / 256;
	if (calc->tex_y < 0)
		calc->tex_y = 0;
	if (calc->tex_y >= ac->xpm_so.height)
		calc->tex_y = ac->xpm_so.height - 1;
	if (calc->tex_x < 0)
		calc->tex_x = 0;
	if (calc->tex_x >= ac->xpm_so.width)
		calc->tex_x = ac->xpm_so.width - 1;
	color = *(int *)(ac->xpm_so.img_pointer
			+ calc->tex_y * ac->xpm_so.line_len
			+ calc->tex_x * (ac->xpm_so.bpp / 8));
	return (color);
}

int	coloring_we(t_access *ac, t_calc *calc, int d)
{
	int	color;

	color = 0;
	calc->tex_x = (int)(calc->wall_x * ac->xpm_we.width);
	calc->tex_y = ((d * ac->xpm_we.height) / calc->wall_height) / 256;
	if (calc->tex_y < 0)
		calc->tex_y = 0;
	if (calc->tex_y >= ac->xpm_we.height)
		calc->tex_y = ac->xpm_we.height - 1;
	if (calc->tex_x < 0)
		calc->tex_x = 0;
	if (calc->tex_x >= ac->xpm_we.width)
		calc->tex_x = ac->xpm_we.width - 1;
	color = *(int *)(ac->xpm_we.img_pointer
			+ calc->tex_y * ac->xpm_we.line_len
			+ calc->tex_x * (ac->xpm_we.bpp / 8));
	return (color);
}

int	coloring_ea(t_access *ac, t_calc *calc, int d)
{
	int	color;

	color = 0;
	calc->tex_x = (int)(calc->wall_x * ac->xpm_ea.width);
	calc->tex_y = ((d * ac->xpm_ea.height) / calc->wall_height) / 256;
	if (calc->tex_y < 0)
		calc->tex_y = 0;
	if (calc->tex_y >= ac->xpm_ea.height)
		calc->tex_y = ac->xpm_ea.height - 1;
	if (calc->tex_x < 0)
		calc->tex_x = 0;
	if (calc->tex_x >= ac->xpm_ea.width)
		calc->tex_x = ac->xpm_ea.width - 1;
	color = *(int *)(ac->xpm_ea.img_pointer
			+ calc->tex_y * ac->xpm_ea.line_len
			+ calc->tex_x * (ac->xpm_ea.bpp / 8));
	return (color);
}
