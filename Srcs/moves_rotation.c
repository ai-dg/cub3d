/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:57:55 by ls                #+#    #+#             */
/*   Updated: 2024/09/03 20:14:50 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static bool	set_rotation_angles(t_params *var, double *cos_angle,
		double *sin_angle)
{
	(void)var;
	(void)cos_angle;
	(void)sin_angle;
	if (var->rotate_right == 1)
		return (*cos_angle = cos(ROTATION_SPEED / 2),
			*sin_angle = sin(ROTATION_SPEED / 2), true);
	else if (var->rotate_left == 1)
		return (*cos_angle = cos(-ROTATION_SPEED / 2),
			*sin_angle = sin(-ROTATION_SPEED / 2), true);
	else if (var->mouse.x_pos > var->mouse.oldx
		|| var->mouse.x_pos > var->screen_width - 20)
		return (*cos_angle = cos(ROTATION_SPEED / 2),
			*sin_angle = sin(ROTATION_SPEED / 2), true);
	else if (var->mouse.x_pos < var->mouse.oldx || var->mouse.x_pos == 0)
		return (*cos_angle = cos(-ROTATION_SPEED / 2),
			*sin_angle = sin(-ROTATION_SPEED / 2), true);
	return (false);
}

static void	rotate_vector_move(double *x, double *y, double cos_angle,
		double sin_angle)
{
	double	old_x;

	old_x = *x;
	*x = *x * cos_angle - *y * sin_angle;
	*y = old_x * sin_angle + *y * cos_angle;
}

/**
 * @brief   Rotation of the subjective view orientation and the plane
*/
void	moves_rotate(t_params *var)
{
	double	cos_angle;
	double	sin_angle;

	cos_angle = 0;
	sin_angle = 0;
	if (set_rotation_angles(var, &cos_angle, &sin_angle))
	{
		rotate_vector_move(&var->player.dir.x, &var->player.dir.y, cos_angle,
			sin_angle);
		rotate_vector_move(&var->player.plan.x, &var->player.plan.y, cos_angle,
			sin_angle);
	}
}
