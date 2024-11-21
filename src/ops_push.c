/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:25:10 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/22 01:05:44 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ops_push(t_node **dest, t_node **from)
{
	t_node	*dest_head;
	t_node	*from_head;
	t_node	*from_second;

	if (*from == NULL)
		return ;
	dest_head = *dest;
	from_head = *from;
	from_second = (*from)->next;
	if (dest_head != NULL)
		dest_head->prev = from_head;
	*dest = from_head;
	from_head->next = dest_head;
	if (from_second != NULL)
		from_second->prev = NULL;
	*from = from_second;
}

void	pa(t_node **ap, t_node **bp, bool print)
{
	ops_push(ap, bp);
	if (print == 1)
		ft_printf("pa\n");
}

void	pb(t_node **bp, t_node **ap, bool print)
{
	ops_push(bp, ap);
	if (print == 1)
		ft_printf("pb\n");
}
