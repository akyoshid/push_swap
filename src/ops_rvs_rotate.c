/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rvs_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:25:15 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/22 01:10:25 by akyoshid         ###   ########.fr       */
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

void	rra(t_node **ap, bool print)
{
	ops_rvs_rotate(ap);
	if (print == 1)
		ft_printf("rra\n");
}

void	rrb(t_node **bp, bool print)
{
	ops_rvs_rotate(bp);
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_node **ap, t_node **bp, bool print)
{
	ops_rvs_rotate(ap);
	ops_rvs_rotate(bp);
	if (print == 1)
		ft_printf("rrr\n");
}
