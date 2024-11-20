/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/20 16:32:42 by akyoshid         ###   ########.fr       */
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

void	ft_push_swap(int argc, char *argv[], t_node **ap, t_node **bp)
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
	print_2d_array(numstr);
	(void)ap;
	(void)bp;
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_push_swap(argc, argv, &stack_a, &stack_b);
	// free_stack(&stack_a);
	return (0);
}
