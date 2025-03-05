/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:14:41 by ls                #+#    #+#             */
/*   Updated: 2024/08/06 00:28:37 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	draw_filled_circle(t_params *var, t_point o, int radius, int color)
{
	int	x;
	int	y;

	x = o.x - radius;
	y = o.y - radius;
	while (y <= o.y + radius)
	{
		while (x <= o.x + radius)
		{
			if ((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y) <= radius
				* radius)
				set_pix_color(&var->image, x, y, color);
			x++;
		}
		x = o.x - radius;
		y++;
	}
}
