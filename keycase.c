/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:22:44 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 11:28:57 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	make_the_zoom_and_h(int kc, t_all_struct *as)
{
	double	z_and_h;
	double	zoom;
	int		x;
	int		y;

	if (kc != 126 && kc != 125 && kc != 91 && kc != 84 && kc
		!= 6 && kc != 7 && kc != 8 && kc != 9 && kc != 16
		&& kc != 32 && kc != 256 && kc != 0)
		return (1);
	zoom = as->image->zoom;
	z_and_h = as->image->hauteur * zoom;
	y = 0;
	while ((*as->p3drotated)[y][0].exist)
	{
		x = 0;
		while ((*as->p3drotated)[y][x].exist)
		{
			(*as->p3drotated)[y][x].x = (int)((((*as->p3d)[y][x].x) * zoom));
			(*as->p3drotated)[y][x].y = (int)((((*as->p3d)[y][x].y) * zoom));
			(*as->p3drotated)[y][x].z = (int)((((*as->p3d)[y][x].z) * z_and_h));
			x++;
		}
		y++;
	}
	return (0);
}

int	get_z_bigger(int kc, t_all_struct *as)
{
	double	incr;
	int		y;
	int		x;

	y = 0;
	x = 0;
	incr = 2;
	if ((kc != 126 && kc != 125) || (kc == 126 && as->image->zoom + incr > 100)
		|| (kc == 125 && as->image->zoom - incr <= 0))
		return (1);
	if (kc == 126)
		as->image->zoom += incr;
	if (kc == 125)
		as->image->zoom -= incr;
	return (0);
}

int	all_key_case(int kc, t_all_struct *as)
{
	printf("%d\n", kc);
	change_projection(kc, as);
	make_modif(kc, as);
	translation_vertical(kc, as);
	translation_horizontal(kc, as);
	change_color(kc, as);
	degrade_color_mode(kc, as);
	persistance(kc, as);
	push_updated_image(as);
	cluse(kc, as->mlx_vars->mlx);
	return (0);
}

void	resize_the_image(t_image image, t_all_struct *as)
{
	int	correct;

	correct = 0;
	while (!correct)
	{
		make_the_zoom_and_h(0, as);
		rotation(0, as);
		converse_to_d(*as->p3drotated, &(*as->p2d), &image, 0);
		correct = get_dimension_to_project(*as->p2d, as->image);
	}
	as->image->first_zoom = as->image->zoom;
	as->image->img = mlx_new_image(as->mlx_vars->mlx, WIDTH, HEIGHT);
	as->image->address = mlx_get_data_addr(as->image->img,
			&as->image->bits_per_pixel,
			&as->image->line_length, &as->image->endian);
}
