/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:39:20 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/22 01:42:03 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_node **ap, bool print)
{
	t_node	*biggest;

	biggest = stack_find_biggest(*ap);
	if (biggest == *ap)
		ra(ap, print);
	else if (biggest == (*ap)->next)
		rra(ap, print);
	if ((*ap)->num > (*ap)->next->num)
		sa(ap, print);
}
