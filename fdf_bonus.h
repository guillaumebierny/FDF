/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:51:54 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/30 19:53:15 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "FDF.h"

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_R = 15,
	KEY_G = 5,
	KEY_H = 4,
	KEY_B = 11,
	KEY_PLUS = 69,
	KEY_MIN = 78,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_C = 8,
	KEY_V = 9,
	KEY_I = 34,
	KEY_P = 35,
	KEY_N = 45,
	KEY_ESC = 53,
	ARROW_UP = 126,
	ARROW_LEFT = 123,
	ARROW_DOWN = 125,
	ARROW_RIGHT = 124,
	CONTROL_LEFT = 256
};

void			cluse(int keycode, t_mlx_vars *mlx);
//
//KEYCASE.C:
//
void			get_z_bigger(int keycode, t_as *as);
int				all_key_case(t_as *as);
int				key_press(int keycode, t_as *as);
int				key_release(int keycode, t_as *as);
//
//BONUS.C:
//
void			increase_hauteur(int keycode, t_as *as);
void			translation_vertical(int keycode, t_as *as);
void			translation_horizontal(int keycode, t_as *as);
void			make_modif(int keycode, t_as *as);
void			push_updated_image(t_as *as);
//
//BONUS_COLOR.C:
//
void			change_color(int keycode, t_as *as);
void			degrade_color_mode(int keycode, t_as *as);

#endif
