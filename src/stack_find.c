/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 03:08:26 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/23 03:10:36 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*stack_find_last(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_node	*stack_find_max(t_node *stack)
{
	t_node	*temp;

	if (stack == NULL)
		return (NULL);
	temp = NULL;
	while (stack != NULL)
	{
		if (temp == NULL)
			temp = stack;
		else if (temp->num < stack->num)
			temp = stack;
		stack = stack->next;
	}
	return (temp);
}

t_node	*stack_find_min(t_node *stack)
{
	t_node	*temp;

	if (stack == NULL)
		return (NULL);
	temp = NULL;
	while (stack != NULL)
	{
		if (temp == NULL)
			temp = stack;
		else if (temp->num > stack->num)
			temp = stack;
		stack = stack->next;
	}
	return (temp);
}
