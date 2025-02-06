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