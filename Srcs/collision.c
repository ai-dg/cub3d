/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:12:15 by ls                #+#    #+#             */
/*   Updated: 2024/08/05 18:48:45 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

/**
 * @brief Vérifie s'il y a une collision à la nouvelle position (new_x, new_y)
 * Retourne 1 si la position est libre (0 ou 2), sinon 0
 *
 */
int	check_collision(t_params *var, double new_x, double new_y)
{
	return (var->world_map[(int)new_y][(int)new_x] == 0
		|| var->world_map[(int)new_y][(int)new_x] == 2
		|| var->world_map[(int)new_y][(int)new_x] == 9
		|| var->world_map[(int)new_y][(int)new_x] == 7);
}

bool	is_in_map_range(t_params *var, int x, int y)
{
	if (x < 0 || x > var->map_width - 1)
		return (false);
	if (y < 0 || y > var->map_height - 1)
		return (false);
	return (true);
}

int	check_collision_coin(t_params *var, double new_x, double new_y)
{
	return (var->world_map[(int)new_y][(int)new_x] == 3);
}
