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

// Add a new_node on top of the stack. 
// ex: Stack : (1,2,3)   to add : 40  ==>  Stack : (40,1,2,3)
void push_to_top_node(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = create_new_node(value);
	if (new_node == NULL)
		return ;
	t_stack *top_node = *stack; 			// get the current head node of the stack.
	new_node->next = top_node;				// set the new node next adrrese to the current top node.
	if (top_node)
		top_node->prev = new_node;			// if the stack is not empty the new secod node now will point to the new node
	*stack = new_node;						// updates the stack top pointer with the current new_node created.
}

// Add a new_node to the bottom of the stack. 
// ex: Stack : (1,2,3)   to add : 40  ==>  Stack : (1,2,3,40)
void	push_to_bottom_node(t_stack **stack, int value)     
{
	t_stack	*new_node;
	t_stack	*old_last_node;

	if (stack == NULL)
		return ;
	new_node = create_new_node(value);						// We don't need to update new_node->next/prev create_new_node set them to NULL 
	if (new_node == NULL)
		return ;
	if (*stack == NULL)
		*stack = new_node;									// If the stack is null we add our new node on top.
	else
	{
		old_last_node = get_last_node(*stack);				
		old_last_node->next = new_node;
		new_node->prev = old_last_node;
	}
}

//* test | get_last_node | push_to_bottom_node | push_to_top_node | to tests.
// // int main()
// // {
// //     t_stack *stack = NULL;
// //     // Add some nodes to the stack using push_to_top_node or push_to_bottom_node to test. 
// //     push_to_bottom_node(&stack, 1);
// //     push_to_bottom_node(&stack, 2);
// //     push_to_bottom_node(&stack, 3);
// //     push_to_bottom_node(&stack, 4);
// //     push_to_bottom_node(&stack, 500);
// //     // Print the stack
// //     printf("Stack elements: ");
// //     print_stack(stack);
// //     // Get the last node
// //     t_stack *last_node = get_last_node(stack);
// //     // Print the value of the last node
// //     if (last_node)
// //         printf("The last node value is: %d\n", last_node->value);
// //     else
// //         printf("The stack is empty.\n");
// //     // Free the stack (for good practice)
// //     t_stack *current = stack;
// //     t_stack *next;
// //     while (current)
// //     {
// //         next = current->next;
// //         free(current);
// //         current = next;
// //     }
// //     return 0;
// // }

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



// TODO : refresh_nodes_data
