/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cycles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:47:36 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 09:26:12 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	loop_hook(t_params *var)
{
	if (var->cursor_hide)
		mlx_mouse_hide(var->mlx, var->win);
	else
		mlx_mouse_show(var->mlx, var->win);
	if (var->close == 1)
		free_memory(var);
	init_doors(var);
	raycasting_routine(var, WALL);
	draw_doors(var);
	if (var->sprites_nbr)
		sprite_routine(var);
	if (var->show_map)
		show_map(var);
	mlx_put_image_to_window(var->mlx, var->win, var->image.img, 0, 0);
	mlx_destroy_image(var->mlx, var->doors.img);
	moves_player(var);
	return (0);
}

void	cube3d_cycle(t_params *var)
{
	mlx_hook(var->win, KeyPress, KeyPressMask, handle_key_press, var);
	mlx_mouse_hook(var->win, &mouse_hook, var);
	mlx_hook(var->win, 17, 0L, handle_close, var);
	mlx_hook(var->win, KeyRelease, KeyReleaseMask, handle_key_release, var);
	mlx_loop_hook(var->mlx, loop_hook, var);
	mlx_loop(var->mlx);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
}
