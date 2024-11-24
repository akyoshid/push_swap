/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_gt_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:09:10 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 21:30:06 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	bring_min_2_head(t_node **ap, int stack_a_len)
{
	t_node	*min_node;
	int		i;

	index_stack(*ap);
	min_node = stack_find_min(*ap);
	i = 0;
	if (min_node->index <= stack_a_len / 2)
	{
		while (i < min_node->index)
		{
			ra(ap, 1);
			i++;
		}
	}
	else
	{
		while (i < stack_a_len - min_node->index)
		{
			rra(ap, 1);
			i++;
		}
	}
}

void	sort_gt_three(t_node **ap, t_node **bp, int stack_a_len)
{
	int		i;

	pb(bp, ap, 1);
	i = 1;
	if (stack_a_len - 1 > 3)
	{
		pb(bp, ap, 1);
		i = 2;
	}
	while (stack_a_len - i > 3)
	{
		opss_prep(*ap, *bp, 0);
		opss_exec(ap, bp, 0);
		i++;
	}
	sort_three(ap);
	while (i > 0)
	{
		opss_prep(*ap, *bp, 1);
		opss_exec(ap, bp, 1);
		i--;
	}
	bring_min_2_head(ap, stack_a_len);
}
