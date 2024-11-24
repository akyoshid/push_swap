/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:34:20 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 14:37:06 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	at_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	at_error_init(t_node **sp, char **numstr, int argc)
{
	free_stack(sp);
	free_2d_array(numstr, argc);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	at_success_checker(t_node **ap)
{
	free_stack(ap);
	ft_printf("OK\n");
	exit(EXIT_SUCCESS);
}

void	at_ko_checker(t_node **ap, t_node **bp)
{
	free_stack(ap);
	free_stack(bp);
	ft_printf("KO\n");
	exit(EXIT_FAILURE);
}

void	at_error_checker(t_node **ap, t_ops_node **olp)
{
	free_stack(ap);
	free_ops_list(olp);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
