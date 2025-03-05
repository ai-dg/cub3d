/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:48:38 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 09:17:02 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	init_doors(t_params *var)
{
	int	i;

	i = 0;
	var->doors.img = mlx_new_image(var->mlx, var->screen_width,
			var->screen_height);
	if (!var->doors.img)
		exit_on_error(var, "fail on init minilibx image");
	var->doors.addr = (int *)mlx_get_data_addr(var->doors.img,
			&var->doors.bits_per_pixel, &var->doors.line_length,
			&var->doors.endian);
	while (i < var->doors.line_length)
	{
		if (i % 4 == 0)
			var->doors.addr[i] = 0;
		i++;
	}
}

void	draw_doors(t_params *var)
{
	int	i;

	i = 0;
	while (i < var->screen_height * var->image.line_length / 4)
	{
		if (var->doors.addr[i] != 0)
			var->image.addr[i] = var->doors.addr[i];
		i++;
	}
}
