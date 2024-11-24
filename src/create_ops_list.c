/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ops_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:27:39 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 14:28:26 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
