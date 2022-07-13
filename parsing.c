/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 00:11:44 by gbierny           #+#    #+#             */
/*   Updated: 2022/07/13 20:44:13 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

unsigned int	ft_atoi_base(char *s, char *base)
{
	int				i;
	unsigned int	res;
	int				s_len;

	s_len = ft_strlen(base);
	res = 0;
	i = 1;
	if (!s)
		return (0);
	ft_toupper_str(s);
	if (s[0] != '0' || s[1] != 'X')
		return (0xFFFFFF);
	while (s[++i])
	{	
		res = res * s_len + hex_to_dec(s[i], base);
		if (res < 0)
			error_message("hex for color invalid");
	}
	return ((unsigned int)res);
}

void	read_file(char *argv, t_index *ind, char **whole_file)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd<0)
		error_message("fichier invalide");
	line = get_next_line(fd);
	while (line)
	{
		ind->y++;
		*whole_file = ft_strjoin(*whole_file, line);
		free(line);
		line = get_next_line(fd);
	}
}

void	loop_to_set_point(t_index ind[2], char **all_split[2],
	t_coor ***point, t_image *image)
{
	while (ind[1].y < ind[0].y)
	{
		ind[0].x = 0;
		all_split[1] = ft_split(all_split[0][ind[1].y], ' ');
		while (all_split[1][ind[0].x])
			ind[0].x++;
		(*point)[ind[1].y] = (t_coor *)malloc(sizeof(t_coor)
				* (ind[0].x + 1));
		if (!(*point)[ind[1].y])
			exit(EXIT_FAILURE);
		ind[1].x = ind[0].x;
		set_point((*point)[ind[1].y], ind[1], all_split[1], image);
		free_split(all_split[1]);
		ind[1].y++;
	}
}

void	get_point(char *argv, t_image *image, t_coor ***point)
{
	int		fd;
	char	*whole_file;
	char	**all_split[2];
	t_index	ind[2];

	ind[1].y = 0;
	ind[0].y = 0;
	whole_file = NULL;
	read_file(argv, &ind[0], &whole_file);
	*point = (t_coor **)malloc((ind[0].y + 1) * sizeof(t_coor *));
	if (!*point)
		error_message("probleme de malloc");
	printf("%s\n", whole_file);
	all_split[0] = ft_split(whole_file, '\n');
	loop_to_set_point(ind, all_split, point, image);
	(*point)[ind[0].y] = malloc(sizeof(t_coor) * 1);
	if (!(*point)[ind[0].y])
		error_message("probleme de malloc");
	(*point)[ind[0].y][0].exist = 0;
	free_split(all_split[0]);
}

void	dup_tab_point(t_coor **source, t_coor ***dest)
{
	int	y;
	int	x;
	int	horizontal;

	x = 0;
	y = 0;
	while (source[y][0].exist)
		y++;
	while (source[0][x].exist)
		x++;
	(*dest) = (t_coor **)malloc(sizeof(t_coor *) * (y + 1));
	if (!*dest)
		error_message("probleme de malloc");
	horizontal = 0;
	while (horizontal < y)
	{
		(*dest)[horizontal] = (t_coor *)malloc(sizeof(t_coor)
				* (x + 1));
		if (!(*dest)[horizontal])
			error_message("probleme de malloc");
		set_same_value(dest, source, x, horizontal);
		horizontal++;
	}
	(*dest)[y] = malloc(sizeof(t_coor) * 1);
	if (!(*dest)[y])
		error_message("probleme de malloc");
	(*dest)[y][0].exist = 0;
}