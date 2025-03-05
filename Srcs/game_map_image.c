/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:55:55 by ls                #+#    #+#             */
/*   Updated: 2024/08/06 00:42:05 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	set_pix_color(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = (char *)img->addr + ((int)y * img->line_length + (int)x
			* (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

static int	get_pix_color(t_image *img, int x, int y)
{
	char	*pixel;

	pixel = (char *)img->addr + (y * img->line_length + x * (img->bits_per_pixel
				/ 8));
	return (*(int *)pixel);
}

void	fill_img(t_params *var, int start_x, int start_y, int color)
{
	int	x;
	int	y;
	int	saved_x;

	x = 0;
	y = 0;
	saved_x = start_x;
	while (y < 16)
	{
		while (x < 16)
		{
			set_pix_color(&var->image, start_x, start_y, color);
			start_x++;
			x++;
		}
		start_x = saved_x;
		x = 0;
		start_y++;
		y++;
	}
}

void	img_put_tile(t_params *var, SPRITE *sprite, int start_x, int start_y)
{
	int	x;
	int	y;
	int	saved_x;
	int	color;

	x = 0;
	y = 0;
	saved_x = start_x;
	while (y < sprite->frames[0].height)
	{
		while (x < sprite->frames[0].width)
		{
			color = get_pix_color(&sprite->frames[0], x, y);
			set_pix_color(&var->image, start_x, start_y, color);
			start_x++;
			x++;
		}
		start_x = saved_x;
		x = 0;
		start_y++;
		y++;
	}
}
