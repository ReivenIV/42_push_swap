/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5_nbs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:35:59 by rita              #+#    #+#             */
/*   Updated: 2025/02/06 18:35:59 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_nbs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;

	smallest_node = NULL;
	if (stack_a == NULL)
		return ;
	refresh_ids(*stack_a);
	smallest_node = get_smallest(*stack_a);
	move_t_to_top(stack_a, smallest_node, 'a');
	pb(stack_a, stack_b, false);

	sort_four_nbs(stack_a, stack_b);
	pa(stack_b, stack_a, false);
	pa(stack_b, stack_a, false);
}
