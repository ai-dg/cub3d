/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools_orientation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:16:08 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 12:04:26 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static bool	is_north(double dir_x, double dir_y)
{
	return (dir_y <= 0 && dir_y >= -1 && dir_x < ORIENTATION_THRESHOLD
		&& dir_x > -ORIENTATION_THRESHOLD);
}

static bool	is_south(double dir_x, double dir_y)
{
	return (dir_y >= 0 && dir_y <= 1 && dir_x < ORIENTATION_THRESHOLD && dir_x
		> -ORIENTATION_THRESHOLD);
}

static bool	is_west(double dir_x, double dir_y)
{
	return (dir_x <= 0 && dir_x >= -1 && dir_y < ORIENTATION_THRESHOLD
		&& dir_y > -ORIENTATION_THRESHOLD);
}

static bool	is_east(double dir_x, double dir_y)
{
	return (dir_x >= 0 && dir_x <= 1 && dir_y < ORIENTATION_THRESHOLD && dir_y
		> -ORIENTATION_THRESHOLD);
}

int	get_orientation(t_params *var)
{
	double	dir_x;
	double	dir_y;

	dir_x = var->player.dir.x;
	dir_y = var->player.dir.y;
	if (is_north(dir_x, dir_y))
		return (NORTH);
	if (is_south(dir_x, dir_y))
		return (SOUTH);
	if (is_west(dir_x, dir_y))
		return (WEST);
	if (is_east(dir_x, dir_y))
		return (EAST);
	return (ERROR_MAP);
}
