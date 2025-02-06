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

// will return the cheapest node in a given stack.
t_stack	*get_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)										// loop till the end.
	{
		if (stack->is_cheapest == true)					// If we find the node flagged to is_cheapest == TRUE return it.
			return (stack);
		stack = stack->next;
	}
	return (NULL);										// if not then return NULL my dear.
}

// Will return the node of a given stack with the smallest value.
t_stack *get_smallest(t_stack *stack)
{
	long	smallest_value;
	t_stack	*xs_node;

	xs_node = NULL;
	if (stack == NULL)
		return (NULL);
	smallest_value = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest_value)
		{
			smallest_value = stack->value;
			xs_node = stack;
		}
		stack = stack->next;
	}
	return (xs_node);
}

//* test test_get_smallest:
// // #include <assert.h>  
// // void test_get_smallest() {
// //     // Create sample stack
// //     t_stack *stack = create_new_node(10);
// //     stack->next = create_new_node(5);
// //     stack->next->prev = stack;
// //     stack->next->next = create_new_node(20);
// //     stack->next->next->prev = stack->next;
// //     // Call get_smallest
// //     t_stack *smallest_node = get_smallest(stack);
// //     // Verify the smallest node
// //     assert(smallest_node->value == 5);
// //     // Free the stack
// //     free_stack(&stack);
// // }
// // int main() {
// //     test_get_smallest();
// //     printf("All tests passed!\n");
// //     return 0;
// // }