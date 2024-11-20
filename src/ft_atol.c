/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:46:00 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/20 21:46:35 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1
			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str >= '7')))
			return (LONG_MAX);
		if (sign == -1
			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str >= '8')))
			return (LONG_MIN);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
