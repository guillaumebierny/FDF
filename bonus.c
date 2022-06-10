/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:00:46 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 17:18:23 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	make_modif(int kc, t_all_struct *as)
{
	int	z_bigger;
	int	h_increased;
	int	p;

	z_bigger = 0;
	h_increased = 0;
	z_bigger = get_z_bigger(kc, as);
	h_increased = increase_hauteur(kc, as);
	if (reset_dimension(kc, as) && z_bigger && h_increased
		&& rotation_on_axe(kc, as))
		return (1);
	make_the_zoom_and_h(kc, as);
	rotation(kc, as);
	converse_to_d(*as->p3drotated, as->p2d, as->image, as->top);
	get_width_and_height(as->image, *as->p2d);
	return (0);
}

void	push_updated_image(t_all_struct *as)
{
	int	x;

	x = 10;
	if (!as->persistance)
		reset_image(as->image, 0);
	else
	{
		// printf("PERSISTANCE!!!!!\n");
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

int	increase_hauteur(int kc, t_all_struct *as)
{
	double	augmentation_de_hauteur;

	augmentation_de_hauteur = 0.1;
	if ((kc != 91 && kc != 84)
		|| (kc == 84 && (as->image->hauteur - augmentation_de_hauteur) < -50)
		|| (kc == 91 && (as->image->hauteur + augmentation_de_hauteur) > 50))
		return (1);
	if (kc == 91)
		as->image->hauteur += augmentation_de_hauteur;
	if (kc == 84)
		as->image->hauteur -= augmentation_de_hauteur;
	return (0);
}

void	translation_vertical(int kc, t_all_struct *as)
{
	int	y_incresement;

	y_incresement = 5;
	if ((kc != 89 && kc != 83)
		|| (kc == 83 && (as->image->t_vertical - y_incresement) < -HEIGHT)
		|| (kc == 89 && (as->image->t_vertical + y_incresement) > HEIGHT))
		return ;
	if (kc == 89)
		as->image->t_vertical -= y_incresement;
	if (kc == 83)
		as->image->t_vertical += y_incresement;
}

void	translation_horizontal(int kc, t_all_struct *as)
{
	int	x_incresement;

	x_incresement = 5;
	if ((kc != 86 && kc != 88)
		|| (kc == 86 && (as->image->t_horizontal - x_incresement) < -WIDTH)
		|| (kc == 88 && (as->image->t_horizontal + x_incresement) > WIDTH))
		return ;
	if (kc == 86)
		as->image->t_horizontal -= x_incresement;
	if (kc == 88)
		as->image->t_horizontal += x_incresement;
}
