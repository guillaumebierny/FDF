/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:00:46 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/30 19:08:58 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	make_modif(int kc, t_as *as)
{
	int	z_bigger;
	int	h_increased;
	int	p;

	get_z_bigger(kc, as);
	increase_hauteur(kc, as);
	reset_dimension(kc, as);
	rotation_on_axe(kc, as);
	make_the_zoom_and_h(kc, as);
	rotation(kc, as);
	converse_to_d(*as->p3drotated, as->p2d, as->image, as->top);
	get_width_and_height(as->image, *as->p2d);
}

void	push_updated_image(t_as *as)
{
	int	x;

	x = 3;
	if (!as->persistance)
		reset_image(as->image, 0);
	else
	{
		while (x--)
		{
			reset_image(as->image, 0xF0000000);
			mlx_put_image_to_window(as->mlx_vars->mlx,
				as->mlx_vars->win_mlx, as->image->img, 0, 0);
		}
	}
	make_bresenham(*as->p2d, as);
	mlx_put_image_to_window(as->mlx_vars->mlx,
		as->mlx_vars->win_mlx, as->image->img, 0, 0);
}

void	increase_hauteur(int kc, t_as *as)
{
	double	augmentation_de_hauteur;

	augmentation_de_hauteur = 0.1;
	if (kc == ARROW_LEFT)
		as->image->hauteur += augmentation_de_hauteur;
	if (kc == ARROW_RIGHT)
		as->image->hauteur -= augmentation_de_hauteur;
}

void	translation_vertical(int kc, t_as *as)
{
	int	y_incresement;

	y_incresement = 5;
	if (as->w)
		as->image->t_vertical -= y_incresement;
	if (as->s)
		as->image->t_vertical += y_incresement;
}

void	translation_horizontal(int kc, t_as *as)
{
	int	x_incresement;

	x_incresement = 5;
	if (as->a)
		as->image->t_horizontal -= x_incresement;
	if (as->d)
		as->image->t_horizontal += x_incresement;
}
