/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:10:56 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/24 14:03:00 by akyoshid         ###   ########.fr       */
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
# include "../libft/inc/get_next_line_bonus.h"

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
	int				r_cost[4];
	int				push_cost[4];
	int				best_push_cost;
	int				best_opss_code;
}	t_node;

// r_cost[0]
// - cost to move this node to the top of the stack by “rotate”
// r_cost[1]
// - cost to move this node to the top of the stack by “reverse rotate”
// r_cost[2]
// - cost to move the target node to the top of the stack by “rotate”
// r_cost[3]
// - cost to move the target node to the top of the stack by “reverse rotate”
// opss_code 0:
// - “rotate” both its stack & target stack
// - the larger of r_cost[0] & r_cost[2]
// opss_code 1:
// - “rotate” its stack & “reverse rotate” target stack
// - r_cost[0] + r_cost[3]
// opss_code 2:
// - “reverse rotate” its stack & “rotate” target stack
// - r_cost[1] + r_cost[2]
// opss_code 3:
// - “reverse rotate” both its stack & target stack
// - the larger of r_cost[1] & r_cost[3]
// push_cost[i]:
// - cost to push by the operations assigned opss_code i

typedef struct s_ops_node
{
	int					ops_code;
	struct s_ops_node	*next;
}	t_ops_node;

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
// opss_exec_utils.c
t_node	*get_best_node(t_node* from);
void	rotate_its_stack(t_node **ap, t_node **bp, bool do_pa);
void	rvs_rotate_its_stack(t_node **ap, t_node **bp, bool do_pa);
void	rotate_target_stack(t_node **ap, t_node **bp, bool do_pa);
void	rvs_rotate_target_stack(t_node **ap, t_node **bp, bool do_pa);
// opss_exec.c
void	opss0(t_node **ap, t_node **bp, bool do_pa, t_node *best_node);
void	opss1(t_node **ap, t_node **bp, bool do_pa, t_node *best_node);
void	opss2(t_node **ap, t_node **bp, bool do_pa, t_node *best_node);
void	opss3(t_node **ap, t_node **bp, bool do_pa, t_node *best_node);
void	opss_exec(t_node **ap, t_node **bp, bool do_pa);
// opss_prep.c
void	get_target_node_asc(t_node *dest, t_node* from);
void	get_target_node_desc(t_node *dest, t_node* from);
void	get_best_push_cost_opss(t_node *node);
void	calc_push_cost(t_node *from, int dest_len, int from_len);
void	opss_prep(t_node *stack_a, t_node *stack_b, bool do_pa);
// proc_arg.c
void	at_error(void);
char	**proc_arg(int argc, char *argv[]);
// sort_gt_three.c
void	bring_min_2_head(t_node **ap, int stack_a_len);
void	sort_gt_three(t_node **ap, t_node **bp, int stack_a_len);
// sort_three.c
void	sort_three(t_node **ap);
// stack_find.c
t_node	*stack_find_last(t_node* stack);
t_node	*stack_find_max(t_node* stack);
t_node	*stack_find_min(t_node* stack);
// stack_utils.c
int		stack_len(t_node *stack);
int		stack_check_sorted(t_node *stack);
void	index_stack(t_node *stack);

// debuf_utils.c
void	print_2d_array(char **str);
void	print_stack(t_node *stack);
void	print_stack_with_info(t_node *stack, bool have_target);
void	print_best_node(t_node *node);

#endif
