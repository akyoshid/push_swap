/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rvs_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:25:15 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/21 23:59:13 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ops_rvs_rotate(t_node **sp)
{
	t_node	*head;
	t_node	*second2last;
	t_node	*last;

	if (*sp == NULL || (*sp)->next == NULL)
		return ;
	head = *sp;
	last = stack_find_last(*sp);
	second2last = last->prev;
	head->prev = last;
	last->prev = NULL;
	last->next = head;
	second2last->next = NULL;
	*sp = last;
}

void	rra(t_node **ap)
{
	ops_rvs_rotate(ap);
}

void	rrb(t_node **bp)
{
	ops_rvs_rotate(bp);
}

void	rrr(t_node **ap, t_node **bp)
{
	rra(ap);
	rrb(bp);
}
