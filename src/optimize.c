/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:00:00 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/15 00:00:00 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void optimize_push_to_b(t_sort_unit **a, t_sort_unit **b)
{
    int size;
    int chunks;
    int i;

    size = stack_len(*a);
    chunks = 5;
    if (size < 100)
        chunks = 3;
    i = 0;
    while (i++ < chunks && size > 3)
    {
        push_smart_chunk(a, b, size, chunks);
        size = stack_len(*a);
    }
}

void push_smart_chunk(t_sort_unit **a, t_sort_unit **b, int size, int chunks)
{
    int chunk_size;
    int median;
    int pushed;

    chunk_size = size / chunks;
    median = find_simple_median(*a, chunk_size);
    pushed = 0;
    while (pushed++ < chunk_size && stack_len(*a) > 3)
    {
        if ((*a)->value <= median)
        {
            pb(b, a, false);
            if ((*b)->next && (*b)->value < (*b)->next->value)
                sb(b, false);
        }
        else
            ra(a, false);
    }
}

int find_simple_median(t_sort_unit *stack, int size)
{
    t_sort_unit *current;
    int smaller_count;
    int target;
    int value;

    current = stack;
    while (current)
    {
        value = current->value;
        smaller_count = count_smaller_values(stack, value);
        if (smaller_count == size / 2)
            return value;
        current = current->next;
    }
    target = find_smallest_value(stack)->value;
    return target;
}

int count_smaller_values(t_sort_unit *stack, int value)
{
    int count;
    
    count = 0;
    while (stack)
    {
        if (stack->value < value)
            count++;
        stack = stack->next;
    }
    return count;
}

void optimize_final_sort(t_sort_unit **a, t_sort_unit **b)
{
    while (*b)
    {
        prepare_stack_b(*a, *b);
        move_b_to_a(a, b);
        if ((*a)->next && (*a)->value > (*a)->next->value)
            sa(a, false);
    }
    min_to_top(a);
}
