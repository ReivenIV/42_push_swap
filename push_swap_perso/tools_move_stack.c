/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_move_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:37:42 by rita              #+#    #+#             */
/*   Updated: 2025/02/06 16:37:42 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Move target to top. In the given stack and target node will rotate till the target node is in the top.
void	move_t_to_top(t_stack **stack, t_stack *target_node, char s_group)
{
	while (*stack != target_node)
	{
		if (s_group == 'a')
		{
			if (target_node->is_above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (s_group == 'b')
		{
			if (target_node->is_above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
// Will bring cheapest in stack_B to the top
void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*b);														// Find cheapest node in stack_b

	if (cheapest->is_above_median && cheapest->target_node->is_above_median)			// to reduces amount of moves we rr or rrr both stacks to bring the cheapest to the top
		rr_till_cheapest(a, b, cheapest);
	else if (!(cheapest->is_above_median) && !(cheapest->target_node->is_above_median))
		rrr_till_cheapest(a, b, cheapest);
	move_t_to_top(b, cheapest, 'b');													// Then we move individually node in stack_B to the top
	move_t_to_top(a, cheapest->target_node, 'a');										// same we move individually node in stack_A to the top
	pa(b, a, false);																	// at the end when they are alineated we push to stack_A
}