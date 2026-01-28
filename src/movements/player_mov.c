#include "../../includes/cub3d.h"

void	w_m(t_access *ac)
{
	ac->p->pos_x += ac->p->pos_dx;
	ac->p->pos_y += ac->p->pos_dy;
}

void	s_m(t_access *ac)
{
	ac->p->pos_x -= ac->p->pos_dx;
	ac->p->pos_y -= ac->p->pos_dy;
}

void	a_m(t_access *ac)
{
	ac->p->pos_x += ac->p->pos_dy;
	ac->p->pos_y -= ac->p->pos_dx;
}

void	d_m(t_access *ac)
{
	ac->p->pos_x -= ac->p->pos_dy;
	ac->p->pos_y += ac->p->pos_dx;
}
