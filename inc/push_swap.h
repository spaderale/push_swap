/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:07:21 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:00:40 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

//---------------STRUCTS---------------//

typedef struct	s_node
{
	int				value;
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

//-------------STACK INIT / PARSE -------//
int		init_stack(t_stack **stack);
int		add_to_stack(t_stack *stack, int value);
int		parse_args(int argc, char **argv, t_stack *stack_a);
int		parse_and_fill_stack(int argc, char **argv, t_stack *stack_a);
void	assign_index(t_stack *stack_a);

//-------------STACK UTILS----------------//
int		is_sorted(t_stack *stack);
int		has_duplicate(t_stack *stack, int num);
int		get_stack_size(t_stack *stack);
int		get_min_index_position(t_stack *stack);
int		get_max_index_position(t_stack *stack);
int		abs(int n);
void	free_stack(t_stack *stack);

//----------NODE OPERATIONS------------------//

t_node	*create_node(int value);
void	add_node_bottom(t_stack *stack, t_node *new_node);
void	add_node_top(t_stack *stack, t_node *new_node);
t_node	*pop_node_top(t_stack *stack);

//----------PUSH SWAP CORE--------------------//

void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_large(t_stack *stack_a, t_stack *stack_b);

//-----------COST CALCULATIONS----------------//

void	get_positions(t_stack *stack);
void	get_target_position(t_stack *stack_a, t_stack *stack_b);
void	calculate_cost(t_stack *stack_a, t_stack *stack_b);
void	execute_cheapest_move(t_stack *stack_a, t_stack *stack_b);
t_node	*find_cheapest_node(t_stack *stack_b);
void	do_combined_rotations(t_stack *stack_a, t_stack *stack_b, 
			int	*cost_a, int *cost_b);
void	do_remaining_rotations(t_stack *stack, int *cost, char stack_name);

//--------STACK OPERATIONS---------------------//

void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);
void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pb(t_stack *stack_a, t_stack *stack_b, int print);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);
void	reverse_rotate(t_stack *stack);

//-----------INPUT CHECK---------------------------//
int		is_number(char *str);
long	atol(const char  *str);
int		is_valid_int(const char *str);

//------------SPLIT UTILS------------------------//
char	**split_string(const char *str, int *count);
void	free_split_result(char **tokens, int count);
char	**handle_split_error(char **result, int count);
char	**add_token_to_result(char **tokens, char *new_token, int *count);
int		init_split(const char *str, const char *delim, char **s, char ***result);

//-----------ERROR HANDLING---------------------//
void	exit_eror(t_stack *stack_a, t_stack *stack_b);


#endif
