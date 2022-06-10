/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:30:43 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 17:50:08 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	main(int argc, char **argv)
{
	t_image			image;
	t_mlx_vars		mlx_vars;
	t_coordonnees	**point[3];
	t_all_struct	as;

	if (argc == 1)
		return (error_message("vous n'avez pas rentre de fichier"));
	if (argc > 2)
		return (error_message("vous avez trop d'arguments"));
	mlx_vars = initialyze_mlx_vars();
	image = initialyze_image();
	as = initialyze_all_struct(&mlx_vars);
	as.mlx_vars->mlx = mlx_init();
	as.mlx_vars->win_mlx = mlx_new_window(as.mlx_vars->mlx,
			WIDTH, HEIGHT, "window_of_my_game");
	as.image = &image;
	get_point(argv[1], as.image, &point[0]);
	dup_tab_point(point[0], &point[2]);
	dup_tab_point(point[0], &point[1]);
	printf("nous voila\n");
	gather_struct(&as, &point[0], &point[1], &point[2]);
	resize_the_image(image, &as);
	printf("width and height: %d | %d\n", as.image->width, as.image->height); 
	push_updated_image(&as);
	mlx_hook(as.mlx_vars->win_mlx, 2, 1L<<0, all_key_case, &as);
	// mlx_hook(as.mlx_vars->win_mlx, 3, 1L<<1, all_key_case, &as);
	// mlx_loop_hook(as.mlx_vars->win_mlx, all_key_case, &as);
	mlx_loop(as.mlx_vars->mlx);
	return (0);
}
