/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:23:34 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/21 18:51:06 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ops_swap(t_node **sp)
{
	t_node	*head;
	t_node	*second;
	t_node	*third;

	if (*sp == NULL || (*sp)->next == NULL)
		return ;
	head = *sp;
	second = (*sp)->next;
	third = (*sp)->next->next;
	head->prev = second;
	head->next = third;
	second->prev = NULL;
	second->next = head;
	if (third != NULL)
		third->prev = head;
	*sp = second;
}

void	sa(t_node **ap)
{
	ops_swap(ap);
}

void	sb(t_node **bp)
{
	ops_swap(bp);
}

void	ss(t_node **ap, t_node **bp)
{
	ops_swap(ap);
	ops_swap(bp);
}
