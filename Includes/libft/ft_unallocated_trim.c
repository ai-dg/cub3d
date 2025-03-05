/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unallocated_trim.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:16:21 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/06 01:02:42 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

bool	has_white_space(char *prompt)
{
	int	len;

	len = ft_strlen(prompt) - 1;
	return (ft_is_whitespace(prompt[0]) || ft_is_whitespace(prompt[len]));
}

void	ft_unallocated_trim(char *str)
{
	int	start;
	int	end;

	start = 0;
	if (!str)
		return ;
	end = ft_strlen(str);
	if (ft_is_whitespace(str[start]))
	{
		while (str[start] && ft_is_whitespace(str[start]))
			start++;
		ft_memmove(str, &str[start], ft_strlen(&str[start]));
		str[end - start] = 0;
	}
	end = ft_strlen(str) - 1;
	if (end >= 1 && ft_is_whitespace(str[end]))
	{
		while (end >= 1 && str[end - 1] && ft_is_whitespace(str[end - 1]))
			end--;
		str[end] = 0;
	}
}

void	ft_unallocated_trim_once(char *str, char c)
{
	int	start;
	int	end;

	start = 0;
	if (!str)
		return ;
	end = ft_strlen(str);
	if (str[start] == c)
	{
		ft_memmove(str, &str[1], ft_strlen(&str[1]));
		str[end - 1] = 0;
	}
	end = ft_strlen(str) - 1;
	if (end >= 1 && str[end] == c)
	{
		str[end] = 0;
	}
}
