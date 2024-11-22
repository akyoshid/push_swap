/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 03:11:44 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/23 03:15:21 by akyoshid         ###   ########.fr       */
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

void	get_best_push_cost_ops(t_node *node)
{
	int	i;

	if (node == NULL)
		return ;
	i = 0;
	while (i < 4)
	{
		if (i == 0 || node->push_cost[i] <= node->best_push_cost)
		{
			node->best_push_cost = node->push_cost[i];
			node->best_ops_code = i;
		}
		i++;
	}
}

void	calc_push_cost(t_node *from, int dest_len, int from_len)
{
	while (from != NULL)
	{
		from->r_cost = from->index;
		from->rr_cost = from_len - from->index;
		from->target->r_cost = from->target->index;
		from->target->rr_cost = dest_len - from->target->index;
		if (from->r_cost >= from->target->r_cost)
			from->push_cost[0] = from->r_cost;
		else
			from->push_cost[0] = from->target->r_cost;
		if (from->rr_cost >= from->target->rr_cost)
			from->push_cost[3] = from->rr_cost;
		else
			from->push_cost[3] = from->target->rr_cost;
		from->push_cost[1] = from->r_cost + from->target->rr_cost;
		from->push_cost[2] = from->rr_cost + from->target->r_cost;
		get_best_push_cost_ops(from);
		from = from->next;
	}
}

t_node	*get_best_node(t_node *dest, t_node *from, bool asc)
{
	t_node	*best_node;

	index_stack(from);
	index_stack(dest);
	if (asc == 1)
		get_target_node_asc(dest, from);
	else
		get_target_node_desc(dest, from);
	calc_push_cost(from, stack_len(dest), stack_len(from));
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
