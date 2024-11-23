/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opss_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 03:11:44 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/23 14:43:12 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_target_node_asc(t_node *dest, t_node *from)
{
	t_node	*curr_dest;
	t_node	*curr_from;

	curr_from = from;
	while (curr_from != NULL)
	{
		curr_from->target = NULL;
		curr_dest = dest;
		while (curr_dest != NULL)
		{
			if (curr_from->num < curr_dest->num)
			{
				curr_from->target = curr_dest;
				break ;
			}
			curr_dest = curr_dest->next;
		}
		if (curr_from->target == NULL)
			curr_from->target = stack_find_min(dest);
		curr_from = curr_from->next;
	}
}

void	get_target_node_desc(t_node *dest, t_node *from)
{
	t_node	*curr_dest;
	t_node	*curr_from;

	curr_from = from;
	while (curr_from != NULL)
	{
		curr_from->target = NULL;
		curr_dest = dest;
		while (curr_dest != NULL)
		{
			if (curr_from->num > curr_dest->num)
			{
				if (curr_from->target == NULL)
					curr_from->target = curr_dest;
				else if (curr_dest->num > curr_from->target->num)
					curr_from->target = curr_dest;
			}
			curr_dest = curr_dest->next;
		}
		if (curr_from->target == NULL)
			curr_from->target = stack_find_max(dest);
		curr_from = curr_from->next;
	}
}

void	get_best_push_cost_opss(t_node *node)
{
	int	i;

	if (node == NULL)
		return ;
	i = 0;
	while (i < 4)
	{
		if (i == 0 || node->push_cost[i] < node->best_push_cost)
		{
			node->best_push_cost = node->push_cost[i];
			node->best_opss_code = i;
		}
		i++;
	}
}

void	calc_push_cost(t_node *from, int dest_len, int from_len)
{
	while (from != NULL)
	{
		from->r_cost[0] = from->index;
		from->r_cost[1] = from_len - from->index;
		from->r_cost[2] = from->target->index;
		from->r_cost[3] = dest_len - from->target->index;
		if (from->r_cost[0] >= from->r_cost[2])
			from->push_cost[0] = from->r_cost[0];
		else
			from->push_cost[0] = from->r_cost[2];
		if (from->r_cost[1] >= from->r_cost[3])
			from->push_cost[3] = from->r_cost[1];
		else
			from->push_cost[3] = from->r_cost[3];
		from->push_cost[1] = from->r_cost[0] + from->r_cost[3];
		from->push_cost[2] = from->r_cost[1] + from->r_cost[2];
		get_best_push_cost_opss(from);
		from = from->next;
	}
}

void	opss_prep(t_node *stack_a, t_node *stack_b, bool pa)
{
	index_stack(stack_a);
	index_stack(stack_b);
	if (pa == 1)
	{
		get_target_node_asc(stack_a, stack_b);
		calc_push_cost(stack_b, stack_len(stack_a), stack_len(stack_b));
	}
	else
	{
		get_target_node_desc(stack_b, stack_a);
		calc_push_cost(stack_a, stack_len(stack_b), stack_len(stack_a));
	}
}
