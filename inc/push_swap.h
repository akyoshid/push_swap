/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:10:56 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/21 00:39:58 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_node
{
	int				num;
	int				index;
	bool			above_mid;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
	int				push_cost;
}	t_node;

void	ft_push_swap(int argc, char *argv[], t_node **ap, t_node **bp);

// free_func.c
void	free_stack(t_node **sp);
void	free_2d_array(char **str, int argc);
// ft_atol.c
long	ft_atol(const char *str);
// init_stack_a.c
void	at_error(t_node **sp, char **numstr, int argc);
int		check_format(char *str);
int		check_dupulicate(t_node **sp, int temp_num);
int		append_node(t_node **sp, int temp_num);
void	init_stack_a(t_node **sp, char **numstr, int argc);
// mandatory.c
char	**proc_arg(int argc, char *argv[]);

#endif
