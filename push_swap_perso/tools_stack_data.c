/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_stack_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:47:05 by rita              #+#    #+#             */
/*   Updated: 2025/02/04 14:47:05 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Will add update all the "id" or current_index & "is_above_median" in given stack.
// "id" : is the current position of the node in the stack
// "is_aprox_middle" : is the current node in the stack at the begining ? is before the middle ?
void	refresh_ids(t_stack	*stack)
{
	int i;
	int	aprox_middle;

	if (stack == NULL)
		return ;
	i = 0;
	aprox_middle = get_stack_len(stack) / 2;
	while (stack)
	{
		stack->id = i;
		if (i <= aprox_middle)
			stack->is_above_median = true;
		else
			stack->is_above_median = false;
		stack = stack->next;
		i++;
	}
}

// we update all targets nodes in stack_b pointing to stack_a. 
// If search the **smallest-bigger** value if not we point it to the smallest 
void	refresh_targets_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*best_possible_taget_node;
	long	best_match_value;

	while (stack_b)
	{
		best_match_value = LONG_MAX;						// restart bmv
		current_a = stack_a;								// restart currect_a to the head of stack_a;
		while (current_a)
		{
			if (stack_b->value < current_a->value			// we look for the **smallest-bigger** number than current node in stack_b pointing to stack_a
				&& current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				best_possible_taget_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == LONG_MAX)					// If we have one of the biggest numbers the best_match_value will not change. That means we update the target node to the smallest node in stack A
			stack_b->target_node = get_s_node(stack_a);		// get smallest node.
		else
			stack_b->target_node = best_possible_taget_node;
		stack_b = stack_b->next;
	}
}
// Prices to push from b -> a. 
// price = len_stack - current id;
void	set_prices(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	if (a == NULL || b == NULL)
		return ;
	len_a = get_stack_len(a);
	len_b = get_stack_len(b);
	while(b)
	{
		b->push_price = b->id;					// We init the price to its current id.
		if (b->is_above_median == false)
			b->push_price = len_b - b->id;
		if (b->target_node->is_above_median == true)
			b->push_price += b->target_node->id;
		else
			b->push_price += len_a - b->target_node->id;
		b = b->next;
	}
}

void	flag_cheapest(t_stack *b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_value = b;
		}
		b = b->next;
	}
	best_match_node->is_cheapest = true;
}

// Will update all nodes data related to a stack related to its opositve stack.
void	refresh_nodes_data(t_stack *a, t_stack *b)
{
	refresh_ids(a);
	refresh_ids(b);
	refresh_targets_node(a, b);
	flag_cheapest(b);
}
