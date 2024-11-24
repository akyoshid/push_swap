/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:22:21 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 14:28:54 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_2d_array(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_printf("%d: %s\n", i, str[i]);
		i++;
	}
}

void	print_stack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		ft_printf("%d: %d\n", i, stack->num);
		stack = stack->next;
		i++;
	}
}

void	print_stack_with_info(t_node *stack, bool have_target)
{
	while (stack != NULL)
	{
		if (have_target == 1)
		{
			ft_printf("num:%d, index:[%d], target_index:[%d], push_cost[0]:%d, push_cost[1]:%d, push_cost[2]:%d, push_cost[3]:%d, best_push_cost:%d, best_opss_code:%d\n",
				stack->num, stack->index, stack->target->index, stack->push_cost[0], stack->push_cost[1], stack->push_cost[2], stack->push_cost[3], stack->best_push_cost, stack->best_opss_code);
		}
		else
			ft_printf("num:%d, index:[%d]\n", stack->num, stack->index);
		stack = stack->next;
	}
}

void	print_best_node(t_node *node)
{
	ft_printf("=== best_node ===\n");
	ft_printf("num:%d, index:[%d], target_index:[%d], push_cost[0]:%d, push_cost[1]:%d, push_cost[2]:%d, push_cost[3]:%d, best_push_cost:%d, best_opss_code:%d\n",
		node->num, node->index, node->target->index, node->push_cost[0], node->push_cost[1], node->push_cost[2], node->push_cost[3], node->best_push_cost, node->best_opss_code);
	ft_printf("=============\n");
}

void	print_ops_list(t_ops_node *ops_list)
{
	while (ops_list != NULL)
	{
		if (ops_list->ops_code == 0)
			ft_printf("sa\n");
		else if (ops_list->ops_code == 1)
			ft_printf("sb\n");
		else if (ops_list->ops_code == 2)
			ft_printf("ss\n");
		else if (ops_list->ops_code == 3)
			ft_printf("pa\n");
		else if (ops_list->ops_code == 4)
			ft_printf("pb\n");
		else if (ops_list->ops_code == 5)
			ft_printf("ra\n");
		else if (ops_list->ops_code == 6)
			ft_printf("rb\n");
		else if (ops_list->ops_code == 7)
			ft_printf("rr\n");
		else if (ops_list->ops_code == 8)
			ft_printf("rra\n");
		else if (ops_list->ops_code == 9)
			ft_printf("rrb\n");
		else if (ops_list->ops_code == 10)
			ft_printf("rrr\n");
		else
		{
			ft_printf("Invaild operation code\n");
			return ;
		}
		ops_list = ops_list->next;
	}
}
