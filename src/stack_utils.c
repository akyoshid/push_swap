/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:21:12 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/22 19:22:41 by akyoshid         ###   ########.fr       */
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

t_node	*stack_find_last(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	stack_check_sorted(t_node *stack)
{
	if (stack == NULL)
		at_error();
	while (stack->next != NULL)
	{
		if (stack->num >= stack->next->num)
			return(1);
		stack = stack->next;
	}
	return (0);
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
