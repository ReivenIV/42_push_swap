/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_random_amount.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:20:30 by rita              #+#    #+#             */
/*   Updated: 2025/02/07 17:20:30 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Algo that will sort when the input has more than 5 values. 
void	sort_random_amount(t_stack **stack_a, t_stack **stack_b, int len_a)
{
	t_stack	*min_value_a;

	while (len_a > 3)
	{
		pb(stack_a, stack_b, false);
		len_a--;
	}
	sort_three_nbs(stack_a);
	refresh_nodes_data(*stack_a, *stack_b);
	while (*stack_b)
	{
		refresh_nodes_data(*stack_a, *stack_b);
		move_cheapest(stack_a, stack_b);
	}
	refresh_ids(*stack_a);
	min_value_a = get_s_node(*stack_a);
	move_t_to_top(stack_a, min_value_a, 'a');
}
