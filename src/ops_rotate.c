/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:25:12 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/22 01:08:48 by akyoshid         ###   ########.fr       */
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

void	ra(t_node **ap, bool print)
{
	ops_rotate(ap);
	if (print == 1)
		ft_printf("ra\n");
}

void	rb(t_node **bp, bool print)
{
	ops_rotate(bp);
	if (print == 1)
		ft_printf("rb\n");
}

void	rr(t_node **ap, t_node **bp, bool print)
{
	ops_rotate(ap);
	ops_rotate(bp);
	if (print == 1)
		ft_printf("rr\n");
}
