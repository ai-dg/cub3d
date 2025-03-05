/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 11:31:09 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	draw_ceiling(t_params *var, int *j)
{
	int	color;

	while (*j < var->calc.start)
	{
		if (var->gradient)
			color = get_lighter_color(var->graphics->ceil_color_temp,
					var, j);
		else
			color = var->graphics->ceil_color_temp;
		var->image.addr[*j * var->image.line_length / 4
			+ var->calc.x] = color;
		*j = *j + 1;
	}
}

void	draw_floor(t_params *var, int *j)
{
	int	color;

	while (*j < var->screen_height)
	{
		if (var->gradient)
			color = get_darker_color(var->graphics->floor_color_temp,
					var, j);
		else
			color = var->graphics->floor_color_temp;
		var->image.addr[*j * var->image.line_length / 4
			+ var->calc.x] = color;
		*j = *j + 1;
	}
}

void	put_texture_on_images(t_params *var, int ELEMENT)
{
	int	j;

	j = 0;
	draw_ceiling(var, &j);
	if (j <= var->calc.end)
	{
		if (ELEMENT == WALL || ELEMENT == OPENED_DOOR || ELEMENT == CLOSED_DOOR)
			put_textures_from_images(var, var->calc.x, j);
		j++;
	}
	j = var->calc.end;
	draw_floor(var, &j);
}

void	raycasting_routine(t_params *var, int ELEMENT)
{
	var->calc.x = 0;
	while (var->calc.x < var->screen_width)
	{
		variable_declaration_calc(var);
		calculation_distance_steps(var);
		calculation_map_side_dist(var);
		calculation_start_and_end(var);
		put_texture_on_images(var, ELEMENT);
		if (var->calc.collission == 3)
		{
			var->calc.collission = 0;
			var->calc.door_found = 0;
			calculation_map_side_dist(var);
			calculation_start_and_end(var);
			put_texture_on_images(var, ELEMENT);
		}
		var->calc.x++;
	}
}
