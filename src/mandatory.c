/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/21 15:28:36 by akyoshid         ###   ########.fr       */
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
/////////////////////////////////////////

void	at_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	// t_node	*stack_b;
	char	**numstr;
	int		stack_a_len;

	stack_a = NULL;
	// stack_b = NULL;
	numstr = proc_arg(argc, argv);
		print_2d_array(numstr);
		ft_printf("==========================\n");
	init_stack_a(&stack_a, numstr, argc);
		print_stack(stack_a);
		ft_printf("==========================\n");
	stack_a_len = stack_len(stack_a);
		ft_printf("%d\n", stack_a_len);
		ft_printf("==========================\n");
	if (stack_check_sorted(stack_a) == 0)
		ft_printf("Sorted!\n");
	else
		ft_printf("Not sorted.\n");
	free_stack(&stack_a);
	return (0);
}
