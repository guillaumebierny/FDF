/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:01:27 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 16:53:51 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int error_message(char *str)
{
    write(2, str, ft_strlen(str));
    exit(EXIT_FAILURE);
}

int get_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	free_split(char **double_tab)
{
	int x;
	x = 0;
	while (double_tab[x])
	{
		free(double_tab[x]);
		x++;
	}
	free(double_tab);
}

void	ft_toupper_str(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32; 
		i++;
	}
}

int hex_to_dec(char s, char *base)
{
	int i;
	
	i = 0;
	while (base[i])
	{
		if (base[i] == s)
			return (i);
		i++;
	}
	return (0);
}
