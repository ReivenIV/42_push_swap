/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_push_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:53:15 by rita              #+#    #+#             */
/*   Updated: 2025/02/06 15:53:15 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Add a new_node on top of the stack. 
// ex: Stack : (1,2,3)   to add : 40  ==>  Stack : (40,1,2,3)
void push_to_top_node(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = create_new_node(value);
	if (new_node == NULL)
		return ;
	t_stack *top_node = *stack;
	new_node->next = top_node;
	if (top_node)
		top_node->prev = new_node;
	*stack = new_node;
}

// Add a new_node to the bottom of the stack. 
// ex: Stack : (1,2,3)   to add : 40  ==>  Stack : (1,2,3,40)
void	push_to_bottom_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*old_last_node;

	if (stack == NULL)
		return ;
	new_node = create_new_node(value);
	if (new_node == NULL)
		return ;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		old_last_node = get_last_node(*stack);
		old_last_node->next = new_node;
		new_node->prev = old_last_node;
	}
}
