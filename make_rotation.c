/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:41:58 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/30 18:56:26 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	mrx(t_coor *p, t_as *as, double angle)
{
	double	source_y;
	double	source_z;

	source_y = (double)(*p).y;
	source_z = (double)(*p).z;
	(*p).y += (int)((double)source_y * cos(angle))
		- ((double)source_z * sin(angle)) - (double)source_y;
	(*p).z += (int)((double)source_y * sin(angle))
		+ ((double)source_z * cos(angle)) - (double)source_z;
}

void	mry(t_coor *p, t_as *as, double angle)
{
	double	source_x;
	double	source_z;

	source_x = (double)(*p).x;
	source_z = (double)(*p).z;
	(*p).y -= (int)((double)source_x * cos(as->angle_y))
		+ ((double)source_z * sin(as->angle_y)) - (double)source_x;
	(*p).z -= (int)((double)source_x * -sin(as->angle_y))
		+ ((double)source_z * cos(as->angle_y)) - (double)source_z;
}

void	mrz(t_coor *p, t_as *as, double angle)
{
	double	source_x;
	double	source_y;

	source_x = (double)(*p).x;
	source_y = (double)(*p).y;
	(*p).x += (int)((double)source_x * cos(angle))
		- ((double)source_y * sin(angle)) - (double)source_x;
	(*p).y += (int)((double)source_x * sin(angle))
		+ ((double)source_y * cos(angle)) - (double)source_y;
}

void	make_rotation(int kc, t_coor *point_rotated,
	t_as *as, t_radian rad)
{
	int	source_x;
	int	source_y;
	int	source_z;

	source_x = (*point_rotated).x;
	source_y = (*point_rotated).y;
	source_z = (*point_rotated).z;
	mrx(&(*point_rotated), as, rad.x);
	mrz(&(*point_rotated), as, rad.z);
}

void	rotation(int kc, t_as *as)
{
	t_radian	rad;
	int			y;
	int			x;

	rad.x = as->angle_x * as->to_radian;
	rad.y = as->angle_y * as->to_radian;
	rad.z = as->angle_z * as->to_radian;
	y = 0;
	while ((*as->p3drotated)[y][0].exist)
	{
		x = 0;
		while ((*as->p3drotated)[y][x].exist)
		{	
			make_rotation(kc, &(*as->p3drotated)[y][x], as, rad);
			x++;
		}
		y++;
	}
}
