/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:21:12 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 13:43:55 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_node *stack)
{
	int	i;

	if (stack == NULL)
		at_error();
	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	stack_check_sorted(t_node *stack)
{
	if (stack == NULL)
		at_error();
	while (stack->next != NULL)
	{
		if (stack->num >= stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	index_stack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}
