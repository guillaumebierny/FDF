/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:22:44 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/30 19:40:57 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	get_z_bigger(int kc, t_as *as)
{
	double	incr;
	int		y;
	int		x;

	y = 0;
	x = 0;
	incr = 0.5;
	if (kc == ARROW_UP)
		as->image->zoom += incr;
	if (kc == ARROW_DOWN)
		as->image->zoom -= incr;
}

int	key_press(int keycode, t_as *as)
{
	as->key = keycode;
	printf("keycode = %d\n", keycode);
	if (keycode == KEY_W)
		as->w = 1;
	if (keycode == KEY_S)
		as->s = 1;
	if (keycode == KEY_A)
		as->a = 1;
	if (keycode == KEY_D)
		as->d = 1;
	return (0);
}

int	key_release(int keycode, t_as *as)
{
	as->key = -1;
	if (keycode == KEY_W)
		as->w = 0;
	if (keycode == KEY_S)
		as->s = 0;
	if (keycode == KEY_A)
		as->a = 0;
	if (keycode == KEY_D)
		as->d = 0;
	return (0);
}

int	all_key_case(t_as *as)
{
	change_projection(as->key, as);
	make_modif(as->key, as);
	translation_vertical(as->key, as);
	translation_horizontal(as->key, as);
	change_color(as->key, as);
	degrade_color_mode(as->key, as);
	persistance(as->key, as);
	push_updated_image(as);
	cluse(as->key, as->mlx_vars->mlx);
	return (0);
}
