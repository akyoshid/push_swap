/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:01:43 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 15:32:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node		*stack_a;
	t_node		*stack_b;
	char		**numstr;
	t_ops_node	*ops_list;

	stack_a = NULL;
	stack_b = NULL;
	numstr = proc_arg(argc, argv);
	init_stack_a(&stack_a, numstr, argc);
	ops_list = create_ops_list(&stack_a);
	exec_ops_list(&stack_a, &stack_b, ops_list);
	free_ops_list(&ops_list);
	if (stack_b == NULL && stack_check_sorted(stack_a) == 0)
		at_success_checker(&stack_a);
	else
		at_ko_checker(&stack_a, &stack_b);
	return (0);
}
