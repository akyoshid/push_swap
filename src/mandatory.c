/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/23 02:59:05 by akyoshid         ###   ########.fr       */
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
		// ft_printf("%d: %d: %d\n", i, stack->index, stack->num);
		ft_printf("%d: %d: %d: ", i, stack->index, stack->num);
		if (stack->target != NULL)
			ft_printf("%d\n", stack->target->num);
		else
			ft_printf("\n");
		stack = stack->next;
		i++;
	}
}

void	print_stack_with_info(t_node *stack, bool target)
{

	while (stack != NULL)
	{
		if (target == 1)
		{
			ft_printf("num:%d, index:[%d], target_index:[%d], push_cost[0]:%d, push_cost[1]:%d, push_cost[2]:%d, push_cost[3]:%d, best_push_cost:%d, best_ops_code:%d\n",
				stack->num, stack->index, stack->target->index, stack->push_cost[0], stack->push_cost[1], stack->push_cost[2], stack->push_cost[3], stack->best_push_cost, stack->best_ops_code);
		}
		else
			ft_printf("num:%d, index:[%d]\n", stack->num, stack->index);
		stack = stack->next;
	}
}

void	print_best_node(t_node *node)
{
	ft_printf("=== best_node ===\n");
		ft_printf("num:%d, index:[%d], target_index:[%d], push_cost[0]:%d, push_cost[1]:%d, push_cost[2]:%d, push_cost[3]:%d, best_push_cost:%d, best_ops_code:%d\n",
			node->num, node->index, node->target->index, node->push_cost[0], node->push_cost[1], node->push_cost[2], node->push_cost[3], node->best_push_cost, node->best_ops_code);
	ft_printf("=============\n");
}

/////////////////////////////////////////

void	at_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
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

void	get_target_node_desc(t_node *dest, t_node *from)
{
	t_node	*curr_dest;
	t_node	*curr_from;

	curr_from = from;
	while (curr_from != NULL)
	{
		curr_from->target = NULL;
		curr_dest = dest;
		while (curr_dest != NULL)
		{
			if (curr_from->num > curr_dest->num)
			{
				if (curr_from->target == NULL)
					curr_from->target = curr_dest;
				else if (curr_dest->num > curr_from->target->num)
					curr_from->target = curr_dest;
			}
			curr_dest = curr_dest->next;
		}
		if (curr_from->target == NULL)
			curr_from->target = stack_find_max(dest);
		curr_from = curr_from->next;
	}
}

void	get_target_node_asc(t_node *dest, t_node *from)
{
	t_node	*curr_dest;
	t_node	*curr_from;

	curr_from = from;
	while (curr_from != NULL)
	{
		curr_from->target = NULL;
		curr_dest = dest;
		while (curr_dest != NULL)
		{
			if (curr_from->num < curr_dest->num)
			{
				curr_from->target = curr_dest;
				break ;
			}
			curr_dest = curr_dest->next;
		}
		if (curr_from->target == NULL)
			curr_from->target = stack_find_min(dest);
		curr_from = curr_from->next;
	}
}

void	get_best_push_cost_ops(t_node *node)
{
	int	i;

	if (node == NULL)
		return ;
	i = 0;
	while (i < 4)
	{
		if (i == 0 || node->push_cost[i] <= node->best_push_cost)
		{
			node->best_push_cost = node->push_cost[i];
			node->best_ops_code = i;
		}
		i++;
	}
}

void	calc_push_cost(t_node *from, int dest_len, int from_len)
{
	while (from != NULL)
	{
		from->r_cost = from->index;
		from->rr_cost = from_len - from->index;
		from->target->r_cost = from->target->index;
		from->target->rr_cost = dest_len - from->target->index;
		if (from->r_cost >= from->target->r_cost)
			from->push_cost[0] = from->r_cost;
		else
			from->push_cost[0] = from->target->r_cost;
		if (from->rr_cost >= from->target->rr_cost)
			from->push_cost[3] = from->rr_cost;
		else
			from->push_cost[3] = from->target->rr_cost;
		from->push_cost[1] = from->r_cost + from->target->rr_cost;
		from->push_cost[2] = from->rr_cost + from->target->r_cost;
		get_best_push_cost_ops(from);
		from = from->next;
	}
}

t_node	*get_best_node(t_node *dest, t_node *from, bool asc)
{
	t_node	*best_node;

	index_stack(from);
	index_stack(dest);
	if (asc == 1)
		get_target_node_asc(dest, from);
	else
		get_target_node_desc(dest, from);
	calc_push_cost(from, stack_len(dest), stack_len(from));
	best_node = NULL;
	while (from != NULL)
	{
		if (best_node == NULL
			|| from->best_push_cost < best_node->best_push_cost)
			best_node = from;
		from = from->next;
	}
	return (best_node);
}

// void	do_operation(t_node **dest, t_node **from, bool print)
// {

// }

// void	bring_min_2_head(t_node **ap, bool print)
// {

// }

void	sort_gt_three(t_node **ap, t_node **bp, int stack_a_len, bool print)
{
	int		i;
	t_node	*best_node;

	pb(bp, ap, print);
	if (stack_a_len - 1 > 3)
		pb(bp, ap, print);
	i = 2;
	while (stack_a_len - i > 3)
	{
		best_node = get_best_node(*bp, *ap, 0);
			print_stack_with_info(*ap, 1);
			print_stack_with_info(*bp, 0);
			print_best_node(best_node);
			pb(bp, ap, 0);
		// do_operation(bp, ap, print);
		i++;
	}
	// sort_three(ap, print);
	// while (i > 0)
	// {
	// 	best_node = get_best_node(*ap, *bp, 1);
	// 	do_operation(ap, bp, print);
	// 	i--;
	// }
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
			sort_three(&stack_a, 1);
		if (stack_a_len > 3)
			sort_gt_three(&stack_a, &stack_b, stack_a_len, 1);
	}
		// ft_printf("==========================\n");
		// ft_printf("stack_a\n");
		// print_stack(stack_a);
		// ft_printf("stack_b\n");
		// print_stack(stack_b);
	free_stack(&stack_a);
	return (0);
}
