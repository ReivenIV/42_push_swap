/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_misc_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:35:08 by rita              #+#    #+#             */
/*   Updated: 2025/02/10 14:14:57 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_new_node(int value)
{
    t_stack *node;

	node = malloc(sizeof(t_stack));
    if (node == NULL)
        return NULL;
    node->value = value;
	node->id = -1;
	node->is_above_median = NULL;
	node->push_price = -1;
	node->is_cheapest = NULL;
	node->target_node = NULL;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

//* Will run throught all the stack and check the if the stack is in ascending order.
// output TRUE(1) / FALSE(0).
int	is_stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
