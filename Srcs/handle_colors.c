/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:26:48 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 22:43:42 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	get_lighter_color(int c, t_params *var, int *j)
{
	int		rgb[3];
	float	max_lighten;
	float	lighten_factor;
	int		color;
	int		i;

	max_lighten = 0.9;
	i = 0;
	rgb[0] = (c >> 16) & 0xFF;
	rgb[1] = (c >> 8) & 0xFF;
	rgb[2] = c & 0xFF;
	lighten_factor = ((float)*j / var->screen_height) * max_lighten;
	while (i < 3)
	{
		rgb[i] = (int)(rgb[i] + (255 - rgb[i]) * lighten_factor);
		if (rgb[i] > 255)
			rgb[i] = 255;
		else if (rgb[i] < 0)
			rgb[i] = 0;
		i++;
	}
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (color);
}

int	get_darker_color(int c, t_params *var, int *j)
{
	int		rgb[3];
	float	max_darken;
	float	darken_factor;
	int		color;
	int		i;

	max_darken = 0.9;
	i = 0;
	rgb[0] = (c >> 16) & 0xFF;
	rgb[1] = (c >> 8) & 0xFF;
	rgb[2] = c & 0xFF;
	darken_factor = ((float)*j / var->screen_height) * max_darken;
	while (i < 3)
	{
		rgb[i] = (int)(rgb[i] * (1.0 - darken_factor));
		if (rgb[i] > 255)
			rgb[i] = 255;
		else if (rgb[i] < 0)
			rgb[i] = 0;
		i++;
	}
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (color);
}
