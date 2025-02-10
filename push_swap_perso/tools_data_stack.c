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

// Will update all the "id" or current_index & "is_above_median"(1/0) in given stack.
// "id" :: is the current position of the node in the stack
// "aprox_middle" :: we will calculate an ""average or aproximative middle"" value in the given stack. And then we compare every id to the aprox_middle. If 'id' lower than 'aprox_middle' then "is_above_median"=TRUE else "is_above_median"=FALSE
void	refresh_ids(t_stack	*stack)												//* set_id
{
	int i;
	int	aprox_middle;

	if (stack == NULL)
		return ;
	i = 0;
	aprox_middle = get_stack_len(stack) / 2;					// we calculate in the given stack un aprox middle
	while (stack)
	{
		stack->id = i;											// we asigne an id to each node in the stack
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
void	refresh_targets_node(t_stack *stack_a, t_stack *stack_b)				//* set_target_node
{
	t_stack	*current_a;
	t_stack	*best_possible_taget_node;
	long	best_match_value;

	while (stack_b)
	{
		best_match_value = LONG_MAX;							// restart b.m.v
		current_a = stack_a;									// restart currect_a to the head of stack_a;
		while (current_a)
		{
			if (stack_b->value < current_a->value				// we look for the **smallest-bigger** number than current node in stack_b pointing to stack_a
				&& current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				best_possible_taget_node = current_a;
			}
			current_a = current_a->next;						// stack_A node ++
		}
		if (best_match_value == LONG_MAX)						// If we have one of the biggest numbers the b.m.v will not change. in these case "target_node" == to the smallest node in stack_A
			stack_b->target_node = get_s_node(stack_a);			// ""current node in stack_B""->target_node === get smallest node in stack_A
		else
			stack_b->target_node = best_possible_taget_node;	// if b.m.v is changed then ""current node in stack_B""->target_node === best_possible_taget_node in stack_A
		stack_b = stack_b->next;								// stack_B node ++
	}
}
// Prices to push from b -> a. 
// price = len_stack - current id;
void	set_prices(t_stack *a, t_stack *b)										//* set_price
{
	int	len_a;
	int	len_b;

	if (a == NULL || b == NULL)
		return ;
	
	len_a = get_stack_len(a);
	len_b = get_stack_len(b);
	while(b)
	{
		b->push_price = b->id;									// We init the price to its current id.

		if (b->is_above_median == false)
			b->push_price = len_b - b->id;

		if (b->target_node->is_above_median == true)
			b->push_price += b->target_node->id;
		else
			b->push_price += len_a - b->target_node->id;
		b = b->next;
	}
}

// flag the cheapest node in the stack_b to push into de stack_A
void	flag_cheapest(t_stack *stack_b)											//* set_cheapest
{
	long	best_match_value;
	t_stack	*best_node;

	if (stack_b == NULL)
		return ;
	best_match_value = LONG_MAX;								// We init best_match_value to LONG_MAX
	while (stack_b)
	{
		if (stack_b->push_price < best_match_value)				// every time we found a node->price smaller to b.m.v
		{
			best_match_value = stack_b->push_price;				// we update b.m.v value to the current node
			best_node = stack_b;								// we update our best possible node with the current smaller price value
		}
		stack_b = stack_b->next;
	}
	best_node->is_cheapest = true;								// When we loop over all the stack_B and we already found the node with the cheapest price. We flag it.
}

// Will update all nodes data related to a stack related to its opositve stack.
void	refresh_nodes_data(t_stack *a, t_stack *b)								//* init_nodes
{
	refresh_ids(a);
	refresh_ids(b);
	refresh_targets_node(a, b);
	set_prices(a, b);
	flag_cheapest(b);
}
