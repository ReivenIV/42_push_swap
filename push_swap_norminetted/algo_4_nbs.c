/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4_nbs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:47:28 by rita              #+#    #+#             */
/*   Updated: 2025/02/06 16:47:28 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_nbs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;

	smallest_node = NULL;
	if (stack_a == NULL)
		return ;
	refresh_ids(*stack_a);
	smallest_node = get_smallest(*stack_a);
	move_t_to_top (stack_a, smallest_node, 'a');
	pb(stack_a, stack_b, false);
	sort_three_nbs(stack_a);
	pa(stack_b, stack_a, false);
}
