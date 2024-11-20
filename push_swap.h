/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:10:56 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/20 11:53:42 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/inc/libft.h"
# include "libft/inc/ft_printf.h"

typedef struct s_stack_node
{
	int					num;
	int					index;
	bool				above_mid;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*target;
	int					push_cost;
}	t_stack_node;

#endif
