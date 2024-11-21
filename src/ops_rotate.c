/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:25:12 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/22 00:01:13 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ops_rotate(t_node **sp)
{
	t_node	*head;
	t_node	*second;
	t_node	*last;

	if (*sp == NULL || (*sp)->next == NULL)
		return ;
	head = *sp;
	second = head->next;
	last = stack_find_last(*sp);
	second->prev = NULL;
	head->prev = last;
	head->next = NULL;
	last->next = head;
	*sp = second;
}

void	ra(t_node **ap)
{
	ops_rotate(ap);
}

void	rb(t_node **bp)
{
	ops_rotate(bp);
}

void	rr(t_node **ap, t_node **bp)
{
	ra(ap);
	rb(bp);
}
