/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:53:48 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 14:30:15 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_node **sp)
{
	t_node	*current_node;
	t_node	*next_node;

	if (sp == NULL || *sp == NULL)
		return ;
	current_node = *sp;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*sp = NULL;
}

void	free_2d_array(char **str, int argc)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
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
