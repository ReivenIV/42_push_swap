/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:26:38 by rita              #+#    #+#             */
/*   Updated: 2025/02/11 13:53:13 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate ex : stack = "1,2,3" => rotate_stack(stack) => "2,3,1"
// remember the instructions are mainly aimed to handlefor 3 nodes.
static void	rotate_stack(t_stack **stack)
{
	t_stack	*old_first_node;
	t_stack	*old_last_node;
	int		stack_len;

	stack_len = get_stack_len(*stack);
	if (stack == NULL || *stack == NULL || stack_len == 1)
		return ;
	old_first_node = (*stack);
	old_last_node = get_last_node(*stack);
	old_last_node->next = old_first_node;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	old_first_node->prev = old_last_node;
	old_first_node->next = NULL;
}

// every comand. it's a way to reduce noise in the terminal.
void	ra(t_stack **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}

void	rr_till_cheapest(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b);
	refresh_ids(*a);
	refresh_ids(*b);
}
