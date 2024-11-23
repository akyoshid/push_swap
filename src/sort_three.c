/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:39:20 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/23 15:10:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_node **ap)
{
	t_node	*biggest;

	biggest = stack_find_max(*ap);
	if (biggest == *ap)
		ra(ap, 1);
	else if (biggest == (*ap)->next)
		rra(ap, 1);
	if ((*ap)->num > (*ap)->next->num)
		sa(ap, 1);
}
