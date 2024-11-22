/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/22 16:59:16 by akyoshid         ###   ########.fr       */
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
		ft_printf("%d: %d: %d\n", i, stack->index, stack->num);
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

void	get_best_node(t_node *dest, t_node *from)
{
	index_stack(from);
	index_stack(dest);
	
	
}

// void	do_operation(t_node **dest, t_node **from)
// {

// }

// void	bring_min_2_head(t_node **ap)
// {

// }

void	sort_gt_three(t_node **ap, t_node **bp, int stack_a_len, bool print)
{
	int	i;

	pb(bp, ap, print);
	if (stack_a_len - 1 > 3)
		pb(bp, ap, print);
	i = 2;
	while (stack_a_len - i > 3)
	{
		get_best_node(*bp, *ap);
		// do_operation(bp, ap);
		i++;
	}
	// sort_three(ap, 1);
	// while (i > 0)
	// {
	// 	get_best_node(*ap, *bp);
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
