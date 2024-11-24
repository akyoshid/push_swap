/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opss_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:30:57 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 13:44:48 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	opss0(t_node **ap, t_node **bp, bool do_pa, t_node *best_node)
{
	int	i;

	i = 0;
	while (i < best_node->r_cost[0] && i < best_node->r_cost[2])
	{
		rr(ap, bp, 1);
		i++;
	}
	while (i < best_node->r_cost[0])
	{
		rotate_its_stack(ap, bp, do_pa);
		i++;
	}
	while (i < best_node->r_cost[2])
	{
		rotate_target_stack(ap, bp, do_pa);
		i++;
	}
	if (do_pa == 1)
		pa(ap, bp, 1);
	else
		pb(bp, ap, 1);
}

void	opss1(t_node **ap, t_node **bp, bool do_pa, t_node *best_node)
{
	int	i;

	i = 0;
	while (i < best_node->r_cost[0])
	{
		rotate_its_stack(ap, bp, do_pa);
		i++;
	}
	i = 0;
	while (i < best_node->r_cost[3])
	{
		rvs_rotate_target_stack(ap, bp, do_pa);
		i++;
	}
	if (do_pa == 1)
		pa(ap, bp, 1);
	else
		pb(bp, ap, 1);
}

void	opss2(t_node **ap, t_node **bp, bool do_pa, t_node *best_node)
{
	int	i;

	i = 0;
	while (i < best_node->r_cost[1])
	{
		rvs_rotate_its_stack(ap, bp, do_pa);
		i++;
	}
	i = 0;
	while (i < best_node->r_cost[2])
	{
		rotate_target_stack(ap, bp, do_pa);
		i++;
	}
	if (do_pa == 1)
		pa(ap, bp, 1);
	else
		pb(bp, ap, 1);
}

void	opss3(t_node **ap, t_node **bp, bool do_pa, t_node *best_node)
{
	int	i;

	i = 0;
	while (i < best_node->r_cost[1] && i < best_node->r_cost[3])
	{
		rrr(ap, bp, 1);
		i++;
	}
	while (i < best_node->r_cost[1])
	{
		rvs_rotate_its_stack(ap, bp, do_pa);
		i++;
	}
	while (i < best_node->r_cost[3])
	{
		rvs_rotate_target_stack(ap, bp, do_pa);
		i++;
	}
	if (do_pa == 1)
		pa(ap, bp, 1);
	else
		pb(bp, ap, 1);
}

void	opss_exec(t_node **ap, t_node **bp, bool do_pa)
{
	t_node	*best_node;

	if (do_pa == 1)
		best_node = get_best_node(*bp);
	else
		best_node = get_best_node(*ap);
	if (best_node->best_opss_code == 0)
		opss0(ap, bp, do_pa, best_node);
	else if (best_node->best_opss_code == 1)
		opss1(ap, bp, do_pa, best_node);
	else if (best_node->best_opss_code == 2)
		opss2(ap, bp, do_pa, best_node);
	else if (best_node->best_opss_code == 3)
		opss3(ap, bp, do_pa, best_node);
}
