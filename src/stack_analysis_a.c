#include "push_swap.h"

static void		set_target_nodes_a(t_sort_unit *a, t_sort_unit *b)
{
	t_sort_unit		*current_b;
	t_sort_unit		*target_node;
	long			best_match_value;

	while (a != NULL)
	{
		best_match_value = LONG_MIN;
		current_b = b;
		target_node = NULL;

		while (current_b != NULL)
		{
			if (current_b->value < a->value && current->value > best_match_value)
			{
				best_match_value = current_b->value;
				target_node = currrent_b;
			}
			current_b = current_b->next;
		}

		if (best_match_value == LONG_MIN)
			a->target_node = find_largest_value(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	analyze_stack_a(t_sort_unit *a, t_sort_unit *b)
{
	update_position_index(a);
	update_position_index(b);
	set_target_nodes_a(a, b);
	calculate_move_costs(a, b);
	mark_optimal_nodes(a);
}
