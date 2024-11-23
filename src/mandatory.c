/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/23 17:34:26 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/////////////////////////////////////////
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

/////////////////////////////////////////

void	at_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

// void	bring_min_2_head(t_node **ap, bool print)
// {

// }

void	sort_gt_three(t_node **ap, t_node **bp, int stack_a_len)
{
	int		i;
	t_node	*best_node;

	pb(bp, ap, 1);
	if (stack_a_len - 1 > 3)
		pb(bp, ap, 1);
	i = 2;
	while (stack_a_len - i > 3)
	{
		opss_prep(*ap, *bp, 0);
			best_node = get_best_node(*ap);
			print_stack_with_info(*ap, 1);
			print_stack_with_info(*bp, 0);
			print_best_node(best_node);
		opss_exec(ap, bp, 0);
		i++;
	}
	sort_three(ap);
	while (i > 0)
	{
		opss_prep(*ap, *bp, 1);
			best_node = get_best_node(*bp);
			print_stack_with_info(*ap, 0);
			print_stack_with_info(*bp, 1);
			print_best_node(best_node);
		opss_exec(ap, bp, 1);
		i--;
	}
	// bring_min_2_head(ap, print);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**numstr;
	int		stack_a_len;

	stack_a = NULL;
	stack_b = NULL;
	numstr = proc_arg(argc, argv);
	init_stack_a(&stack_a, numstr, argc);
		print_stack(stack_a);
		ft_printf("==========================\n");
	stack_a_len = stack_len(stack_a);
	if (stack_check_sorted(stack_a) == 1)
	{
		if (stack_a_len == 2)
			sa(&stack_a, 1);
		if (stack_a_len == 3)
			sort_three(&stack_a);
		if (stack_a_len > 3)
			sort_gt_three(&stack_a, &stack_b, stack_a_len);
	}
		ft_printf("==========================\n");
		ft_printf("stack_a\n");
		print_stack(stack_a);
		ft_printf("stack_b\n");
		print_stack(stack_b);
	free_stack(&stack_a);
	return (0);
}
