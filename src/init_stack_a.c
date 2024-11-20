/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:33:17 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/21 00:35:21 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	at_error(t_node **sp, char **numstr, int argc)
{
	free_stack(sp);
	free_2d_array(numstr, argc);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	check_format(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (1);
	}
	return (0);
}

int	check_dupulicate(t_node **sp, int temp_num)
{
	t_node	*current_node;

	current_node = *sp;
	while (current_node != NULL)
	{
		if (current_node->num == temp_num)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}

int	append_node(t_node **sp, int temp_num)
{
	t_node			*new;
	static t_node	*last;

	new = (t_node *)malloc(sizeof(t_node) * 1);
	if (new == NULL)
		return (1);
	new->num = temp_num;
	new->index = 0;
	new->above_mid = 0;
	new->next = NULL;
	new->target = NULL;
	new->push_cost = 0;
	if (*sp == NULL)
	{
		*sp = new;
		new->prev = NULL;
	}
	else
	{
		new->prev = last;
		last->next = new;
	}
	last = new;
	return (0);
}

void	init_stack_a(t_node **sp, char **numstr, int argc)
{
	int		i;
	long	temp_num;

	i = 0;
	while (numstr[i] != NULL)
	{
		if (check_format(numstr[i]) == 1)
			at_error(sp, numstr, argc);
		temp_num = ft_atol(numstr[i]);
		if (temp_num > INT_MAX || temp_num < INT_MIN)
			at_error(sp, numstr, argc);
		if (check_dupulicate(sp, temp_num) == 1)
			at_error(sp, numstr, argc);
		if (append_node(sp, temp_num) == 1)
			at_error(sp, numstr, argc);
		i++;
	}
	free_2d_array(numstr, argc);
}
