/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_variable_calc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/12 09:54:34 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	calculate_delta_distance_save(double ray_dir_x, double ray_dir_y,
		double *delta_dist_x, double *delta_dist_y)
{
	if (ray_dir_y == 0)
	{
		*delta_dist_y = INFINITY;
	}
	else
		*delta_dist_x = sqrt(1 + pow(ray_dir_y, 2) / pow(ray_dir_x, 2));
	if (ray_dir_x == 0)
	{
		*delta_dist_x = INFINITY;
	}
	else
		*delta_dist_y = sqrt(1 + (pow(ray_dir_x, 2) / (pow(ray_dir_y, 2))));
}

void	calculate_delta_distance(double ray_dir_x, double ray_dir_y,
		double *delta_dist_x, double *delta_dist_y)
{
	if (ray_dir_y == 0)
		*delta_dist_y = INFINITY;
	else
		*delta_dist_x = sqrt(1 + pow(ray_dir_y, 2) / pow(ray_dir_x, 2));
	if (ray_dir_x == 0)
		*delta_dist_x = INFINITY;
	else
		*delta_dist_y = sqrt(1 + (pow(ray_dir_x, 2) / (pow(ray_dir_y, 2))));
}

void	variable_declaration_calc(t_params *var)
{
	var->calc.collission = 0;
	var->calc.door_found = 0;
	var->calc.distance_wall = 0;
	var->calc.camera_x = 2 * var->calc.x / (double)var->screen_width - 1;
	var->calc.ray_dir_x = var->player.dir.x + var->player.plan.x
		* var->calc.camera_x;
	var->calc.ray_dir_y = var->player.dir.y + var->player.plan.y
		* var->calc.camera_x;
	var->player.map_x = (int)var->player.pos.x;
	var->player.map_y = (int)var->player.pos.y;
	calculate_delta_distance(var->calc.ray_dir_x, var->calc.ray_dir_y,
		&var->calc.delta_dist_x, &var->calc.delta_dist_y);
}
