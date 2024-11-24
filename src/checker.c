/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:01:43 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 14:03:45 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	at_success_checker(t_node **ap)
{
	free_stack(ap);
	ft_printf("OK\n");
	exit(EXIT_SUCCESS);
}

void	at_ko_checker(t_node **ap, t_node **bp)
{
	free_stack(ap);
	free_stack(bp);
	ft_printf("KO\n");
	exit(EXIT_FAILURE);
}

void	free_ops_list(t_ops_node **olp)
{
	t_ops_node	*current_node;
	t_ops_node	*next_node;

	if (olp == NULL || *olp == NULL)
		return ;
	current_node = *olp;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*olp = NULL;
}

void	at_error_checker(t_node **ap, t_ops_node **olp)
{
	free_stack(ap);
	free_ops_list(olp);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	convert_ops_code(char *ops_str)
{
	if (ops_str == NULL)
		return (-1);
	else if (ft_strncmp(ops_str, "sa\n", 3) == 0)
		return (0);
	else if (ft_strncmp(ops_str, "sb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(ops_str, "ss\n", 3) == 0)
		return (2);
	else if (ft_strncmp(ops_str, "pa\n", 3) == 0)
		return (3);
	else if (ft_strncmp(ops_str, "pb\n", 3) == 0)
		return (4);
	else if (ft_strncmp(ops_str, "ra\n", 3) == 0)
		return (5);
	else if (ft_strncmp(ops_str, "rb\n", 3) == 0)
		return (6);
	else if (ft_strncmp(ops_str, "rr\n", 3) == 0)
		return (7);
	else if (ft_strncmp(ops_str, "rra\n", 4) == 0)
		return (8);
	else if (ft_strncmp(ops_str, "rrb\n", 4) == 0)
		return (9);
	else if (ft_strncmp(ops_str, "rrr\n", 4) == 0)
		return (10);
	return (-1);
}

t_ops_node	*create_ops_node(t_ops_node **olp, t_ops_node *last,
									char *ops_str, t_node **ap)
{
	t_ops_node	*temp;

	if (olp == NULL)
		return (NULL);
	temp = (t_ops_node *)malloc(sizeof(t_ops_node) * 1);
	if (temp == NULL)
	{
		free(ops_str);
		at_error_checker(ap, olp);
	}
	if (*olp == NULL)
		*olp = temp;
	else
		last->next = temp;
	temp->next = NULL;
	return (temp);
}

t_ops_node	*create_ops_list(t_node **ap)
{
	t_ops_node	*head;
	t_ops_node	*last;
	char		*ops_str;
	int			gnl_error_code;

	head = NULL;
	while (1)
	{
		ops_str = get_next_line(0, &gnl_error_code);
		if (ops_str == NULL && gnl_error_code == 2)
			return (head);
		if (ops_str == NULL && gnl_error_code != 2)
			at_error_checker(ap, &head);
		last = create_ops_node(&head, last, ops_str, ap);
		last->ops_code = convert_ops_code(ops_str);
		free(ops_str);
		if (last->ops_code == -1)
			at_error_checker(ap, &head);
	}
}

void	print_ops_list(t_ops_node *ops_list)
{
	while (ops_list != NULL)
	{
		if (ops_list->ops_code == 0)
			ft_printf("sa\n");
		else if (ops_list->ops_code == 1)
			ft_printf("sb\n");
		else if (ops_list->ops_code == 2)
			ft_printf("ss\n");
		else if (ops_list->ops_code == 3)
			ft_printf("pa\n");
		else if (ops_list->ops_code == 4)
			ft_printf("pb\n");
		else if (ops_list->ops_code == 5)
			ft_printf("ra\n");
		else if (ops_list->ops_code == 6)
			ft_printf("rb\n");
		else if (ops_list->ops_code == 7)
			ft_printf("rr\n");
		else if (ops_list->ops_code == 8)
			ft_printf("rra\n");
		else if (ops_list->ops_code == 9)
			ft_printf("rrb\n");
		else if (ops_list->ops_code == 10)
			ft_printf("rrr\n");
		else
		{
			ft_printf("Invaild operation code\n");
			return ;
		}
		ops_list = ops_list->next;
	}
}

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
