/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_move_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:37:42 by rita              #+#    #+#             */
/*   Updated: 2025/02/11 13:53:34 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Move target to top. In the given stack and target node will rotate
//		till the target node is in the top.
void	move_t_to_top(t_stack **stack, t_stack *target_node, char s_group)
{
	while (*stack != target_node)
	{
		if (s_group == 'a')
		{
			if (target_node->is_above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (s_group == 'b')
		{
			if (target_node->is_above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

// Will bring cheapest in stack_B to the top
void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*b);
	if (cheapest->is_above_median && cheapest->target_node->is_above_median)
		rr_till_cheapest(a, b, cheapest);
	else if (!(cheapest->is_above_median)
		&& !(cheapest->target_node->is_above_median))
		rrr_till_cheapest(a, b, cheapest);
	move_t_to_top(b, cheapest, 'b');
	move_t_to_top(a, cheapest->target_node, 'a');
	pa(b, a);
}
