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

//*   ---------------------
//*   ::  test it dear   ::
//*  ----------------------
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