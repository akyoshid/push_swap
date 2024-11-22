/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/22 19:44:54 by akyoshid         ###   ########.fr       */
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

t_node	*get_best_node(t_node *dest, t_node *from, bool asc)
{
	index_stack(from);
	index_stack(dest);
	if (asc == 1)
		get_target_node_asc(dest, from);
	else
		get_target_node_desc(dest, from);
	return (NULL);
}

// void	do_operation(t_node **dest, t_node **from)
// {

// }

// void	bring_min_2_head(t_node **ap)
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
		(void)best_node;
		// do_operation(bp, ap);
		i++;
	}
	// sort_three(ap, 1);
	// while (i > 0)
	// {
	// 	best_node = get_best_node(*bp, *ap, 1);
	// 	do_operation(ap, bp);
	// 	i--;
	// }
	// bring_min_2_head(ap);
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
		ft_printf("==========================\n");
		ft_printf("stack_a\n");
		print_stack(stack_a);
		ft_printf("stack_b\n");
		print_stack(stack_b);
	free_stack(&stack_a);
	return (0);
}
