/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xs_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:09:42 by rita              #+#    #+#             */
/*   Updated: 2025/02/03 17:09:42 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// will output the HIGHEST node in the stack.
t_stack	*get_h_node(t_stack *stack)
{
	int		value_h;
	t_stack	*highest_node;

	if (stack == NULL)
		return (NULL);
	value_h = INT_MIN;
	while (stack)
	{
		if (stack->value > value_h)
		{
			value_h = stack->value; 		// when we found a new highets we update value_h.
			highest_node = stack;			// we save the current highest present in the stack.
		}
		stack = stack->next;
	}
	return (highest_node);
}

// will output the SMALLEST node in the stack.
t_stack	*get_s_node(t_stack *stack)
{
	int		value_s;
	t_stack	*smallest_node;

	if (stack == NULL)
		return (NULL);
	value_s = INT_MAX;
	while (stack)
	{
		if (stack->value < value_s)
		{
			value_s = stack->value; 		// when we found a new smallest we update value_s.
			smallest_node = stack;			// we save the current smallest present in the stack.
		}
		stack = stack->next;
	}
	return (smallest_node);
}