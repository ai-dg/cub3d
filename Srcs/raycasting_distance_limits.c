/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_distance_limits.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 13:42:02 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	calculation_distance_steps(t_params *var)
{
	if (var->calc.ray_dir_x < 0)
	{
		var->calc.step_x = -1;
		var->calc.side_dist_x = (var->player.pos.x - var->player.map_x)
			* var->calc.delta_dist_x;
	}
	else
	{
		var->calc.step_x = 1;
		var->calc.side_dist_x = (var->player.map_x + 1.0 - var->player.pos.x)
			* var->calc.delta_dist_x;
	}
	if (var->calc.ray_dir_y < 0)
	{
		var->calc.step_y = -1;
		var->calc.side_dist_y = (var->player.pos.y - var->player.map_y)
			* var->calc.delta_dist_y;
	}
	else
	{
		var->calc.step_y = 1;
		var->calc.side_dist_y = (var->player.map_y + 1.0 - var->player.pos.y)
			* var->calc.delta_dist_y;
	}
}

void	calculate_wall_distance(t_params *var, int is_x_direction)
{
	double	delta;
	double	position;
	double	map_position;
	double	ray_direction;

	if (is_x_direction)
	{
		delta = (1 - (double)var->calc.step_x) / 2;
		position = var->player.pos.x;
		map_position = var->player.map_x;
		ray_direction = var->calc.ray_dir_x;
	}
	else
	{
		delta = (1 - (double)var->calc.step_y) / 2;
		position = var->player.pos.y;
		map_position = var->player.map_y;
		ray_direction = var->calc.ray_dir_y;
	}
	var->calc.distance_wall = (map_position - position + delta) / ray_direction;
	var->zbuffer[var->calc.x] = var->calc.distance_wall;
	if (var->calc.collission == 3)
		var->zdoor[var->calc.x] = var->calc.distance_wall;
}

void	calculate_line_limits(t_params *var)
{
	var->calc.line_height = (int)(var->screen_height / var->calc.distance_wall);
	var->calc.start = -var->calc.line_height / 2 + var->screen_height / 2;
	if (var->calc.start < 0)
		var->calc.start = 0;
	var->calc.end = var->calc.line_height / 2 + var->screen_height / 2;
	if (var->calc.end >= var->screen_height || var->calc.end < 0)
		var->calc.end = var->screen_height - 1;
}

void	calculation_start_and_end(t_params *var)
{
	if (var->calc.step == 0)
		calculate_wall_distance(var, 1);
	else
		calculate_wall_distance(var, 0);
	calculate_line_limits(var);
}
