/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/21 00:40:15 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//
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
//

char	**proc_arg(int argc, char *argv[])
{
	char	**numstr;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		numstr = ft_split(argv[1], ' ');
		if (numstr == NULL)
			exit(EXIT_FAILURE);
	}
	else
		numstr = argv + 1;
	return(numstr);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	// t_node	*stack_b;
	char	**numstr;

	stack_a = NULL;
	// stack_b = NULL;
	numstr = proc_arg(argc, argv);
	print_2d_array(numstr);
	init_stack_a(&stack_a, numstr, argc);
	print_stack(stack_a);
	free_stack(&stack_a);
	return (0);
}
