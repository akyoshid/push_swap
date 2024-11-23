/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:23:37 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/23 20:20:48 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	at_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

char	**proc_arg(int argc, char *argv[])
{
	char	**numstr;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		numstr = ft_split(argv[1], ' ');
		if (numstr == NULL || numstr[0] == NULL)
		{
			free(numstr);
			at_error();
		}
	}
	else
		numstr = argv + 1;
	return(numstr);
}
