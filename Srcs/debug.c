/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 07:04:53 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/06 00:34:17 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	print_paths(t_params *var)
{
	(void)var;
	ft_printf("%s\n", var->graphics->north_wall_path);
	ft_printf("%s\n", var->graphics->south_wall_path);
	ft_printf("%s\n", var->graphics->west_wall_path);
	ft_printf("%s\n", var->graphics->east_wall_path);
}

static void	print_color(char *label, short array[3])
{
	int	i;

	i = 0;
	ft_printf("%s : [", label);
	while (i < 3)
	{
		ft_printf("%d", array[i]);
		if (i < 2)
			ft_printf(",");
		i++;
	}
	ft_printf("]\n");
}

void	print_colors(t_params *var)
{
	print_color("ceil", var->graphics->ceil_color);
	print_color("floor", var->graphics->floor_color);
}

void	print_datas(t_params *var)
{
	printf("Calc Datas...\n-------------\n");
	printf("map_x : %d, map_y : %d\n", var->player.map_x, var->player.map_y);
	printf("pos_x : %f, pos_y : %f\n", var->player.pos.x, var->player.pos.y);
	printf("x : %d, y : %d\n\n", var->calc.x, var->calc.y);
}

void	print_sprites(t_params *var)
{
	int	i;

	i = 0;
	printf("sprites...\n-------------\n");
	while (i < var->sprites_nbr)
	{
		printf("sprite y : %d , sprite x : %d - type : %d\n", var->sprites[i].y,
			var->sprites[i].x, var->sprites[i].type);
		printf("distance : %f\n", var->sprites[i].distance);
		i++;
	}
	printf("total sprites : %d\n", var->sprites_nbr);
}
