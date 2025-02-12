/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_rotate_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:05 by rita              #+#    #+#             */
/*   Updated: 2025/02/11 13:53:10 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// rotate ex : stack = "1,2,3,4,5" => rotate_stack(stack) => "5,1,2,3,4"
static void	rotate_reverse_stack(t_stack **stack)
{
	t_stack	*current_node;
	int		stack_len;

	stack_len = get_stack_len(*stack);
	if (*stack == NULL || stack == NULL || stack_len == 1)
		return ;
	current_node = get_last_node(*stack);
	current_node->prev->next = NULL;
	current_node->next = (*stack);
	current_node->prev = NULL;
	(*stack) = current_node;
	current_node->next->prev = current_node;
}

void	rra(t_stack **a)
{
	rotate_reverse_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rotate_reverse_stack(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate_reverse_stack(a);
	rotate_reverse_stack(b);
	write(1, "rrr\n", 4);
}

void	rrr_till_cheapest(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b);
	refresh_ids(*a);
	refresh_ids(*b);
}
