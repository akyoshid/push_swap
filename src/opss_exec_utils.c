/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opss_exec_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:33:53 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/23 17:35:04 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*get_best_node(t_node *from)
{
	t_node	*best_node;

	best_node = NULL;
	while (from != NULL)
	{
		if (best_node == NULL
			|| from->best_push_cost < best_node->best_push_cost)
			best_node = from;
		from = from->next;
	}
	return (best_node);
}

void	rotate_its_stack(t_node **ap, t_node **bp, bool do_pa)
{
	if (do_pa == 1)
		rb(bp, 1);
	else
		ra(ap, 1);
}

void	rvs_rotate_its_stack(t_node **ap, t_node **bp, bool do_pa)
{
	if (do_pa == 1)
		rrb(bp, 1);
	else
		rra(ap, 1);
}

void	rotate_target_stack(t_node **ap, t_node **bp, bool do_pa)
{
	if (do_pa == 1)
		ra(ap, 1);
	else
		rb(bp, 1);
}

void	rvs_rotate_target_stack(t_node **ap, t_node **bp, bool do_pa)
{
	if (do_pa == 1)
		rra(ap, 1);
	else
		rrb(bp, 1);
}
