/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:09:27 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/14 04:02:31 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1250
# define HEIGHT 850
# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct s_image
{
	void			*img;
	char			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	color;
	double			zoom;
	double			first_zoom;
	double			hauteur;
	int				height;
	int				higher;
	int				minest_x;
	int				width;
	int				t_vertical;
	int				t_horizontal;
	int				switch_color;
	int				lowest_z;
	int				bigest_z;
	int				correct;
}					t_image;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win_mlx;
}			t_mlx_vars;

typedef struct s_rgb
{
	unsigned int	color;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}					t_rgb;

typedef struct s_coordonnees
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
	int				exist;
}					t_coor;

typedef struct s_radian
{
	double	x;
	double	y;
	double	z;
}			t_radian;

typedef struct s_bres_v
{
	unsigned int	color_point1;
	unsigned int	r1;
	unsigned int	g1;
	unsigned int	b1;
	unsigned int	color_point2;
	unsigned int	r2;
	unsigned int	g2;
	unsigned int	b2;
	unsigned int	dif_r;
	unsigned int	dif_g;
	unsigned int	dif_b;
	int				dy;
	int				dx;
	int				x_incr;
	int				y_incr;
	int				x;
	int				y;
	int				ex;
	int				ey;
	int				end_dx;
	int				end_dy;
	unsigned int	i;
	int				x1;
	int				y1;
}					t_bres_v;

typedef struct s_index
{
	int	y;
	int	x;
	int	w;
	int	h;
	int	choice;
}		t_index;

typedef struct s_all_struct
{
	t_mlx_vars		*mlx_vars;
	t_image			*image;
	t_coor			***p3d;
	t_coor			***p2d;
	t_coor			***p3drotated;
	int				angle_x;
	int				angle_y;
	int				angle_z;
	int				first_anglex;
	int				first_angley;
	int				first_anglez;
	unsigned int	color;
	double			to_radian;
	int				previous_height;
	int				previous_higher;
	int				interupteur_couleur;
	int				persistance;
	unsigned int	incr_r;
	unsigned int	incr_g;
	unsigned int	incr_b;
	int				top;
	int				w;
	int				s;
	int				a;
	int				d;
	int				key;
}					t_as;

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

void			gather_struct(t_as *as, t_coor ***p3d,
					t_coor ***p3drot, t_coor ***p2d);
void			my_mlx_pixel_put(t_image *image,
					int x, int y, unsigned int color);
void			cluse(int keycode, t_mlx_vars *mlx);
void			get_coordinates(int x, int y, int z, t_coor *p);
void			get_right_incrementation(int *x_inc,
					int *y_incr, t_coor p1, t_coor p2);
unsigned int	ft_atoi_base(char *s, char *base);
void			resize_the_image(t_image image, t_as *as);
void			set_right_value(t_coor *point, int x, int y, char *z);
void			set_point(t_coor *point, t_index ind, char **z, t_image *image);
void			set_same_value(t_coor ***dest, t_coor **source, int x, int y);
void			get_point(char *argv, t_image *image, t_coor ***point);
void			converse_to_d(t_coor **point_3d, t_coor ***point_2d,
					t_image *image, int type_of_conv);
//INITIALYZE:
t_bres_v		initialyse_t_bres_v(t_coor p1, t_coor p2, t_image *image);
t_image			initialyze_image(void);
t_mlx_vars		initialyze_mlx_vars(void);
t_as			initialyze_all_struct(t_mlx_vars *mlx_vars);
//FDF_UTILS:
int				error_message(char *str);
int				get_absolute(int n);
void			free_split(char **double_tab);
void			ft_toupper_str(char *s);
int				hex_to_dec(char s, char *base);
int				get_dimension_to_project(t_coor **point, t_image *image);
void			dup_tab_point(t_coor **point_3d, t_coor ***point_2d);
void			get_width_and_height(t_image *image, t_coor **point);
void			converse_to_d(t_coor **p3d, t_coor ***p2d,
					t_image *image, int type_of_conv);
//BRESENHAM:
void			bresenham_algo(t_coor p[4], t_as *as, t_index ind);
void			make_bresenham(t_coor **point, t_as *as);
void			bresenham_dx_bigger(t_bres_v *bres_v, t_image *image,
					int framing_w, int framing_h);
void			bresenham_dy_bigger(t_bres_v *bres_v, t_image *image,
					int framing_w, int framing_h);
//BRESENHAM_UTILS:
void			get_right_incrementation(int *x_incr, int *y_incr,
					t_coor point1, t_coor point2);
void			red_case(t_bres_v *bres, unsigned int *color,
					double spacing, double i);
void			green_case(t_bres_v *bres, unsigned int *color,
					double spacing, double i);
void			blue_case(t_bres_v *bres, unsigned int *color,
					double spacing, double i);
int				framing(int little_var, int big_var);
void			lil_loop_bresenham(t_index ind, t_coor p[4],
					t_coor **point, t_as *as);
//
//BONUS
//
int				all_key_case(t_as *as);
int				key_press(int keycode, t_as *as);
int				key_release(int keycode, t_as *as);
void			rx(int keycode, t_as *as, int incrementation_angle);
void			mrx(t_coor *p, t_as *as, double angle);
void			ry(int keycode, t_as *as, int incrementation_angle);
void			mry(t_coor *p, t_as *as, double angle);
void			rz(int keycode, t_as *as, int incrementation_angle);
void			mrz(t_coor *p, t_as *as, double angle);

void			rotation_on_axe(int keycode, t_as *as);
void			reset_image(t_image *image, unsigned int color);
void			increase_hauteur(int keycode, t_as *as);
void			translation_vertical(int keycode, t_as *as);
void			translation_horizontal(int keycode, t_as *as);
void			change_color(int keycode, t_as *as);
void			reset_dimension(int keycode, t_as *as);
void			degrade_color_mode(int keycode, t_as *as);
void			make_rotation(int keycode, t_coor *point_rotated,
					t_as *as, t_radian rad);
void			get_z_bigger(int keycode, t_as *as);
void			make_modif(int keycode, t_as *as);
void			rotation(int keycode, t_as *as);
void			push_updated_image(t_as *as);
void			make_the_zoom_and_h(int keycode, t_as *as);
void			persistance(int keycode, t_as *as);
void			change_projection(int keycode, t_as *as);

//COLOR_BY_Z:
void			get_color_by_z(unsigned int *color_point, t_coor p, t_as *as);
unsigned int	degraded_for_line(t_bres_v *bres_v, double i, double spacing);
unsigned int	get_right_r(unsigned int dif);
unsigned int	get_right_g(unsigned int dif);
unsigned int	get_right_b(unsigned int dif);

#endif
