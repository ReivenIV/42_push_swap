/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_get_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:49:56 by rita              #+#    #+#             */
/*   Updated: 2025/02/06 15:49:56 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count the amount of nodes that has a stack.
int	get_stack_len(t_stack *stack)
{
	int count;

	count =  0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

//* Find last node in a stack. 
// We don't need the 2 variables created i just add them for comprehention.
t_stack	*get_last_node(t_stack	*head_node)
{
	t_stack	*current_node;
	t_stack	*last_node;

	current_node = head_node;
	if (current_node == NULL)
		return (NULL);
	while (current_node->next)
		current_node = current_node->next;
	last_node = current_node;
	return (last_node);
}