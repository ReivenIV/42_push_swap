/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:26:53 by rita              #+#    #+#             */
/*   Updated: 2025/02/11 13:53:15 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate ex : stack = "1,2,3" => swap_stack(stack) => "2,1,3"
static void	swap_stack(t_stack **stack)
{
	int		len_stack;
	t_stack	*old_first_node;
	t_stack	*old_second_node;

	len_stack = get_stack_len(*stack);
	old_first_node = (*stack);
	old_second_node = (*stack)->next;
	if (*stack == NULL || stack == NULL || len_stack == 1)
		return ;
	*stack = old_second_node;
	old_first_node->next = old_second_node->next;
	old_first_node->prev = old_second_node;
	if (old_second_node->next)
		old_second_node->next->prev = old_first_node;
	old_second_node->next = old_first_node;
	old_second_node->prev = NULL;
}

void	sa(t_stack **a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}
