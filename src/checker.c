/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:01:43 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 14:34:33 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node		*stack_a;
	// t_node		*stack_b;
	char		**numstr;
	t_ops_node	*ops_list;

	stack_a = NULL;
	// stack_b = NULL;
	numstr = proc_arg(argc, argv);
	init_stack_a(&stack_a, numstr, argc);

	ops_list = create_ops_list(&stack_a);
	print_ops_list(ops_list);
	free_ops_list(&ops_list);

	free_stack(&stack_a);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;
// 	char	**numstr;
// 	char	*ops;
// 	int		error_code;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	numstr = proc_arg(argc, argv);
// 	init_stack_a(&stack_a, numstr, argc);
// 	// stack_a_len = stack_len(stack_a);
// 	// if (stack_check_sorted(stack_a) == 1)
// 	// {
// 	// 	if (stack_a_len == 2)
// 	// 		sa(&stack_a, 1);
// 	// 	if (stack_a_len == 3)
// 	// 		sort_three(&stack_a);
// 	// 	if (stack_a_len > 3)
// 	// 		sort_gt_three(&stack_a, &stack_b, stack_a_len);
// 	// }
// 	error_code = 0;
// 	while (1)
// 	{
// 		if (stack_check_sorted(stack_a) && stack_b == NULL)
// 			at_success_checker(&stack_a);
// 		ops = get_next_line(0, &error_code);
// 		if (ops == NULL && error_code == 2)
// 			at_ko_checker(&stack_a, &stack_b);
// 		if (ops == NULL && error_code != 2)
// 			at_error_checker(&stack_a, &stack_b);
		
		
// 	}
// 	free_stack(&stack_a);
// 	return (0);
// }
