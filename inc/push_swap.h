/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:07:21 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:00:40 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_sort_unit {
	int						value;
	int						current_index;
	int						push_cost;
	bool					is_above_median;
	bool					is_cheapest;
	struct s_sort_unit		*target_node;
	struct s_sort_unit		*next;
	struct s_sort_unit		*prev;
} t_sort_unit;

//Stack operations
void		sa(t_sort_unit **a, bool print);
void		sb(t_sort_unit **b, bool print);
void		ss(t_sort_unit **a, t_sort_unit **b, bool print);
void		pa(t_sort_unit **a, t_sort_unit **b, bool print);
void		pb(t_sort_unit **b, t_sort_unit **a, bool print);
void		ra(t_sort_unit **a, bool print);
void		rb(t_sort_unit **b, bool print);
void		rr(t_sort_unit **a, t_sort_unit **b, bool print);
void		rra(t_sort_unit **a, bool print);
void		rrb(t_sort_unit **b, bool print);
void		rrr(t_sort_unit **a, t_sort_unit **b, bool print);

//Stack utils
void			display_stack_content(t_sort_unit *stack);
int				stack_len(t_sort_unit *stack);
bool			is_stack_sorted(t_sort_unit *stack);
void			update_node(t_sort_unit *stack);
t_sort_unit		*get_last_node(t_sort_unit *stack);
t_sort_unit		*find_smallest_value(t_sort_unit *stack);
t_sort_unit		*find_largest_value(t_sort_unit *stack);

//Stack init
void			initialize_stack_a(t_sort_unit **stack_a, char **input_value);
void	prepare_for_push(t_sort_unit **stack, t_sort_unit *top_node, char stack_name);
t_sort_unit		*get_cheapest_node(t_sort_unit *stack);

//Move operations
void		prepare_stack_a(t_sort_unit *stack_a, t_sort_unit *stack_b);
void		prepare_stack_b(t_sort_unit *stack_a, t_sort_unit *stack_b);
void		move_a_to_b(t_sort_unit **a, t_sort_unit **b);
void		move_b_to_a(t_sort_unit **a, t_sort_unit **b);

//Sort algorithms
void		sort_three(t_sort_unit **stack);
void		sort_stacks(t_sort_unit **a, t_sort_unit **b);

//Error handling
int			validate_number_format(char *strnbr);
int			check_duplicate_number(t_sort_unit *stack, int num);
void		free_stack_memory(t_sort_unit **stack);
void		handle_errors(t_sort_unit **stack);

char		**split(char *str, char delimiter);

#endif
