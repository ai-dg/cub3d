/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:35:53 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/02 10:36:55 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	init_bonus_part(t_params *var, char *line)
{
	if (ft_strstr(line, "SPRITE") != NULL)
		var->bonus_map = true;
}
