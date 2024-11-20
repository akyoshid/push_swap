/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:47 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/20 20:27:37 by akyoshid         ###   ########.fr       */
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

// void	free_2d_array(char **str, int argc)
// {
// 	int	i;

// 	if (argc == 2)
// 	{
// 		i = 0;
// 		while (str[i] != NULL)
// 		{
// 			free(str[i]);
// 			str[i] = NULL;
// 			i++;
// 		}
// 		free(str);
// 	}
// }

// void	append_node(t_node **ap, int num)
// {

// }

// int	ft_atol(const char *str)
// {
// 	long	num;
// 	int		sign;

// 	while (*str == '\t' || *str == '\n' || *str == '\v'
// 		|| *str == '\f' || *str == '\r' || *str == ' ')
// 		str++;
// 	sign = 1;
// 	if (*str == '-')
// 		sign = -1;
// 	if (*str == '+' || *str == '-')
// 		str++;
// 	num = 0;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		if (sign == 1
// 			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str >= '7')))
// 			return (LONG_MAX);
// 		if (sign == -1
// 			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str >= '8')))
// 			return (LONG_MIN);
// 		num = num * 10 + (*str - '0');
// 		str++;
// 	}
// 	return (num * sign);
// }

// void	at_error(t_node **sp, )
// {
// 	free_stack(ap);
// 	free_2d_array(numstr, argc);
// 	ft_printf("Error\n");
// 	exit(EXIT_FAILURE);
// }

// void	init_stack_a(int argc, char **numstr, t_node **ap)
// {
// 	t_node	*last;
// 	long	temp_num;
// 	t_node	*new;

// 	while (*numstr != NULL)
// 	{
// 		// 数字なん？ 空の文字列も弾く 空白と数字以外全部弾く
// 		// temp_num = ft_atol(*numstr);
// 		// if (temp_num > INT_MAX || temp_num < INT_MIN)
// 		// {
// 		// 	free_stack(ap);
// 		// 	free_2d_array(numstr, argc);
// 		// 	ft_printf("Error\n");
// 		// 	exit(EXIT_FAILURE);
// 		// }
// 		// 同じ数字ない？


// 		new = (t_node *)malloc(sizeof(t_node) * 1);
// 		if (new == NULL)
// 		{
// 			free_stack(ap);
// 			free_2d_array(numstr, argc);
// 			ft_printf("Error\n");
// 			exit(EXIT_FAILURE);
// 		}
// 		new->num = (int)temp_num;
// 		new->next = NULL;
// 		if (*ap == NULL)
// 		{
// 			*ap = new;
// 			new->prev = NULL;
// 		}
// 		else
// 		{
// 			last->next = new;
// 			new->prev = last;
// 		}
// 		last = new;
// 		numstr++;
// 	}
// 	free_2d_array(numstr, argc);
// }

// void	ft_push_swap(int argc, char *argv[], t_node **ap, t_node **bp)
// {
// 	char	**numstr;

// 	if (argc < 2)
// 		exit(EXIT_FAILURE);
// 	else if (argc == 2)
// 	{
// 		numstr = ft_split(argv[1], ' ');
// 		if (numstr == NULL)
// 			exit(EXIT_FAILURE);
// 	}
// 	else
// 		numstr = argv + 1;
// 	init_stack_a(argc, numstr, ap);
// 	// print_2d_array(numstr);
// 	// (void)ap;
// 	(void)bp;
// }

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
	free_stack(&stack_a);
	return (0);
}
