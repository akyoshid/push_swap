/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_list_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:29:54 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 15:32:28 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exec_ops_code(t_node **ap, t_node **bp, int ops_code)
{
	if (ops_code == 0)
		sa(ap, 0);
	else if (ops_code == 1)
		sb(bp, 0);
	else if (ops_code == 2)
		ss(ap, bp, 0);
	else if (ops_code == 3)
		pa(ap, bp, 0);
	else if (ops_code == 4)
		pb(bp, ap, 0);
	else if (ops_code == 5)
		ra(ap, 0);
	else if (ops_code == 6)
		rb(bp, 0);
	else if (ops_code == 7)
		rr(ap, bp, 0);
	else if (ops_code == 8)
		rra(ap, 0);
	else if (ops_code == 9)
		rrb(bp, 0);
	else if (ops_code == 10)
		rrr(ap, bp, 0);
}

void	exec_ops_list(t_node **ap, t_node **bp, t_ops_node *ops_list)
{
	while (ops_list != NULL)
	{
		exec_ops_code(ap, bp, ops_list->ops_code);
		ops_list = ops_list->next;
	}
}
