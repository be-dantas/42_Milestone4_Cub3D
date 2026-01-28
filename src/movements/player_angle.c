#include "../../includes/cub3d.h"

void	left_angle(t_access *ac)
{
	ac->p->pos_ang -= 0.01;
	if (ac->p->pos_ang < 0)
		ac->p->pos_ang += 2 * PI;
}

void	right_angle(t_access *ac)
{
	ac->p->pos_ang += 0.01;
	if (ac->p->pos_ang > 2 * PI)
		ac->p->pos_ang -= 2 * PI;
}
