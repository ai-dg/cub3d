/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:45:48 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/05 23:57:01 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	print_score(t_params *var)
{
	char	*score;

	score = ft_itoa(var->score);
	mlx_string_put(var->mlx, var->win, 20, 20, 0xFFFFFF, "Score : ");
	mlx_string_put(var->mlx, var->win, 100, 20, 0xFFFFFF, score);
	free(score);
}
