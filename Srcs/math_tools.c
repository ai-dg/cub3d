/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:16:08 by ls                #+#    #+#             */
/*   Updated: 2024/08/05 23:51:05 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

/**
 * @brief   Rotates a vector (x,
	y) by a given angle using the cosine and sine values
 */
void	rotate_vector(double *x, double *y, double cos_angle, double sin_angle)
{
	double	old_x;

	old_x = *x;
	*x = old_x * cos_angle - *y * sin_angle;
	*y = old_x * sin_angle + *y * cos_angle;
}

int	get_sign(int nbr)
{
	if (nbr < 0)
		return (-1);
	else
		return (1);
}
