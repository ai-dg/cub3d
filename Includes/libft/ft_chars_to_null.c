/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_to_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:24:58 by ls                #+#    #+#             */
/*   Updated: 2024/08/06 01:02:22 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_chars_to_null(char **chars, int size)
{
	int	i;

	if (!chars)
		return ;
	i = 0;
	while (i < size)
	{
		chars[i] = NULL;
		i++;
	}
}
