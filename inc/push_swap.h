/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:10:56 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/22 19:08:02 by akyoshid         ###   ########.fr       */
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

// free_func.c
void	free_stack(t_node **sp);
void	free_2d_array(char **str, int argc);
// ft_atol.c
long	ft_atol(const char *str);
// init_stack_a.c
void	at_error_init(t_node **sp, char **numstr, int argc);
int		check_format(char *str);
int		check_dupulicate(t_node **sp, int temp_num);
int		append_node(t_node **sp, int temp_num);
void	init_stack_a(t_node **sp, char **numstr, int argc);
// mandatory.c
void	at_error(void);
// ops_push.c
void	ops_push(t_node **dest, t_node **from);
void	pa(t_node **ap, t_node **bp, bool print);
void	pb(t_node **bp, t_node **ap, bool print);
// ops_rotate.c
void	ops_rotate(t_node **sp);
void	ra(t_node **ap, bool print);
void	rb(t_node **bp, bool print);
void	rr(t_node **ap, t_node **bp, bool print);
// ops_rvs_rotate.c
void	ops_rvs_rotate(t_node **sp);
void	rra(t_node **ap, bool print);
void	rrb(t_node **bp, bool print);
void	rrr(t_node **ap, t_node **bp, bool print);
// ops_swap.c
void	ops_swap(t_node **sp);
void	sa(t_node **ap, bool print);
void	sb(t_node **bp, bool print);
void	ss(t_node **ap, t_node **bp, bool print);
// proc_arg.c
char	**proc_arg(int argc, char *argv[]);
// sort_three.c
void	sort_three(t_node **ap, bool print);
// stack_utils.c
int		stack_len(t_node *stack);
t_node	*stack_find_last(t_node *stack);
int		stack_check_sorted(t_node *stack);
t_node	*stack_find_max(t_node *stack);

#endif
