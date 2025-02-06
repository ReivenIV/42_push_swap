/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:35:08 by rita              #+#    #+#             */
/*   Updated: 2025/01/27 18:35:08 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	::  Gentle reminder  :: 
	- *stack			 :: is a pointer to the top node of the stack.
	- (*stack)			 :: dereferences this pointer to access the actual node.
	- (*stack)->previous :: accesses the previous pointer of this node.
*/

//* creates new node
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
    return node;
}

//* Will run throught all the stack and check the if the stack is in ascending order.
// output TRUE(1) / FALSE(0).
int	is_stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)				// if current_node is bigger to the next node. then we are not in an ascending stack.
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Test function for is_stack_sorted
// // int main(void) {
// //     t_stack *stack = NULL;
// //     // Create a sorted stack
// //     push_to_bottom_node(&stack, 1);
// //     push_to_bottom_node(&stack, 2000);
// //     push_to_bottom_node(&stack, 3);
// //     if (is_stack_sorted(stack)) {
// //         printf("Test 1 :: Stack is sorted.\n");
// //     } else {
// //         printf("Test 1 :: Stack is not sorted.\n");
// //     }
// //     // Free the stack
// //     free_stack(&stack);
// //     // Create an unsorted stack
// //     stack = NULL;
// //     push_to_bottom_node(&stack, 3000);
// //     push_to_bottom_node(&stack, 40000);
// //     push_to_bottom_node(&stack, 666666);
// //     if (!is_stack_sorted(stack)) {
// //         printf("Test 2 :: Stack is not sorted.\n");
// //     } else {
// //         printf("Test 2 :: Stack is sorted.\n");
// //     }
// //     // Free the stack
// //     free_stack(&stack);
// //     return 0;
// // }
