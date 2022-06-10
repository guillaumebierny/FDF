/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:58 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 11:43:56 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	rx(int keycode, t_all_struct *as, int incrementation_angle)
{
	if (keycode == 7)
		as->angle_x += incrementation_angle;
	if (keycode == 8)
		as->angle_x -= incrementation_angle;
	if (as->angle_x >= 360 || as->angle_x <= -360)
		as->angle_x = 0;
	return (0);
}

int	ry(int keycode, t_all_struct *as, int incrementation_angle)
{
	if (keycode != 16 && keycode != 32)
		return (1);
	if (keycode == 16)
		as->angle_y += incrementation_angle;
	if (keycode == 32)
		as->angle_y -= incrementation_angle;
	if (as->angle_y >= 360 || as->angle_y <= -360)
		as->angle_y = 0;
	return (0);
}

int	rz(int keycode, t_all_struct *as, int incrementation_angle)
{
	if (keycode != 6 && keycode != 9)
		return (1);
	if (keycode == 6)
		as->angle_z += incrementation_angle;
	if (keycode == 9)
		as->angle_z -= incrementation_angle;
	if (as->angle_z >= 360 || as->angle_z <= -360)
		as->angle_z = 0;
	return (0);
}

int	rotation_on_axe(int keycode, t_all_struct *as)
{
	int	x;
	int	y;
	int	incrementation_angle;

	y = 0;
	incrementation_angle = -10;
	if (keycode == 7 || keycode == 8)
		rx(keycode, as, incrementation_angle);
	else if (keycode == 16 || keycode == 32)
		ry(keycode, as, incrementation_angle);
	else if (keycode == 6 || keycode == 9)
		rz(keycode, as, incrementation_angle);
	else
		return (1);
	return (0);
}
