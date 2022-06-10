/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:09:27 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 13:20:02 by gbierny          ###   ########.fr       */
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
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	unsigned int	color;
	double	zoom;
	double first_zoom;
	double		hauteur;
	int		height;
	int		higher;
	int minest_x;
	int		width;
	int t_vertical;
	int t_horizontal;
	int switch_color;
	int lowest_z;
	int bigest_z;
	int correct;
}       t_image;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win_mlx;
}			t_mlx_vars;

typedef struct s_rgb
{
	unsigned int color;
	unsigned int red;
	unsigned int green;
	unsigned int blue;
}	t_rgb;

typedef struct s_coordonnees
{
	int x;
	int y;
	int z;
	unsigned int color;
	int exist;
}		t_coordonnees;

typedef struct s_radian
{
	double	x;
	double	y;
	double	z;
}			t_radian;

typedef struct s_bres_v
{
	unsigned int	color_point1;
	unsigned int r1;
	unsigned int g1;
	unsigned int b1;
	unsigned int	color_point2;
	unsigned int r2;
	unsigned int g2;
	unsigned int b2;
	unsigned int dif_r;
	unsigned int dif_g;
	unsigned int dif_b;
	int dy;
	int dx;
	int x_incr;
	int y_incr;
	int x;
	int y;
	int ex;
	int ey;
	int Dx;
	int Dy;
	unsigned int i;
	int x1;
	int y1;
}	t_bres_v;

typedef struct s_index
{
	int y;
	int x;
	int w;
	int h;
	int choice;
}		t_index;

typedef struct s_all_struct
{
	t_mlx_vars *mlx_vars;
	t_image *image;
	t_coordonnees ***p3d;
	t_coordonnees ***p2d;
	t_coordonnees ***p3drotated;
	int angle_x;
	int angle_y;
	int angle_z;
	int	first_anglex;
	int	first_angley;
	int	first_anglez;
	unsigned int	color;
	double to_radian;
	int	previous_height;
	int	previous_higher;
	int interupteur_couleur;
	int persistance;
	unsigned int incr_r;
	unsigned int incr_g;
	unsigned int incr_b;
	int top;
}	t_all_struct;

void	gather_struct(t_all_struct *as, t_coordonnees ***p3d, t_coordonnees ***p3drotated, t_coordonnees ***p2d);
void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color);
int	cluse(int keycode, t_mlx_vars *mlx);
void	get_coordinates(int x, int y, int z, t_coordonnees *p);
void	get_right_incrementation(int *x_incr, int *y_incr, t_coordonnees point1, t_coordonnees point2);
t_bres_v	initialyse_t_bres_v(t_coordonnees point1, t_coordonnees point2, t_image *image);
unsigned int	ft_atoi_base(char *s, char *base);
void	resize_the_image(t_image image, t_all_struct *as);
void	set_right_value(t_coordonnees *point, int x, int y, char *z);
void	set_point(t_coordonnees *point, t_index ind, char **z, t_image *image);
void	set_same_value(t_coordonnees ***dest,
	t_coordonnees **source, int x, int y);
void	get_point(char *argv, t_image *image, t_coordonnees ***point);
void	converse_to_d(t_coordonnees **point_3d, t_coordonnees ***point_2d, t_image *image, int type_of_conv);
//INITIALYZE:
t_bres_v	initialyse_t_bres_v(t_coordonnees p1
		, t_coordonnees p2, t_image *image);
t_image	initialyze_image(void);
t_mlx_vars	initialyze_mlx_vars(void);
t_all_struct	initialyze_all_struct(t_mlx_vars *mlx_vars);
//FDF_UTILS:
int	error_message(char *str);
int	get_absolute(int n);
void	free_split(char **double_tab);
void	ft_toupper_str(char *s);
int		hex_to_dec(char s, char *base);
int	get_dimension_to_project(t_coordonnees **point, t_image *image);
void	dup_tab_point(t_coordonnees **point_3d, t_coordonnees ***point_2d);
void	get_width_and_height(t_image *image, t_coordonnees **point);
void converse_to_d(t_coordonnees **point_3d, t_coordonnees ***point_2d, t_image *image, int type_of_conv);
//BRESENHAM:
void	bresenham_algo(t_coordonnees p[4], t_all_struct *as, t_index ind);
void	make_bresenham(t_coordonnees **point, t_all_struct *as);
void	bresenham_dx_bigger(t_bres_v *bres_v, t_image *image,
	int framing_w, int framing_h);
void	bresenham_dy_bigger(t_bres_v *bres_v, t_image *image,
	int framing_w, int framing_h);
//BRESENHAM_UTILS:
void	get_right_incrementation(int *x_incr, int *y_incr,
	t_coordonnees point1, t_coordonnees point2);
void	red_case(t_bres_v *bres, unsigned int *color, double spacing, double i);
void	green_case(t_bres_v *bres, unsigned int *color,
	double spacing, double i);
void	blue_case(t_bres_v *bres, unsigned int *color,
	double spacing, double i);
int	framing(int little_var, int big_var);
//
//BONUS
//
int	all_key_case(int kc, t_all_struct *as);
int    rx(int keycode, t_all_struct *as, int incrementation_angle);
void mrx(t_coordonnees *p, t_all_struct *as, double angle);
int    ry(int keycode, t_all_struct *as, int incrementation_angle);
void mry(t_coordonnees *p, t_all_struct *as, double angle);
int    rz(int keycode, t_all_struct *as, int incrementation_angle);
void mrz(t_coordonnees *p, t_all_struct *as, double angle);

int		rotation_on_axe(int keycode, t_all_struct *as);
void    reset_image(t_image *image, unsigned int color);
int	increase_hauteur(int keycode, t_all_struct *as);
void	translation_vertical(int keycode, t_all_struct * as);
void	translation_horizontal(int keycode, t_all_struct * as);
void	change_color(int keycode, t_all_struct * as);
int	reset_dimension(int keycode, t_all_struct *as);
void	degrade_color_mode(int keycode, t_all_struct *as);
void	make_rotation(int keycode, t_coordonnees *point_rotated, t_all_struct *as, t_radian rad);
int	get_z_bigger(int keycode, t_all_struct *as);
int	make_modif(int keycode, t_all_struct *as);
void	rotation(int keycode, t_all_struct *as);
void	push_updated_image(t_all_struct *as);
int	make_the_zoom_and_h(int keycode, t_all_struct *as);
void persistance(int keycode, t_all_struct *as);
int	change_projection(int keycode, t_all_struct *as);

//COLOR_BY_Z:
void	get_color_by_z(unsigned int *color_point, t_coordonnees p, t_all_struct *as);
unsigned int	degraded_for_line(t_bres_v *bres_v, double i, double spacing);
unsigned int	get_right_r(unsigned int dif);
unsigned int	get_right_g(unsigned int dif);
unsigned int	get_right_b(unsigned int dif);

#endif