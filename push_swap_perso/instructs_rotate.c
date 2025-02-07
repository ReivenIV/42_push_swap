/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:26:38 by rita              #+#    #+#             */
/*   Updated: 2025/01/29 18:26:38 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// to visualize the instructions i recomend these article: 
// https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
/*
	Notes:
		**stack 				:: is stack_a or stack_b completly.
		(*stack)				:: is the first node dereferenced.
		(*stack)->next			:: the second node dereferenced.
		(*stack)->next->next	:: the thirth node dereferenced.
*/

// rotate ex : stack = "1,2,3" => rotate_stack(stack) => "2,3,1"
// remember the instructions are mainly aimed to handlefor 3 nodes.
static	void rotate_stack(t_stack **stack)
{
	t_stack	*old_first_node;
	t_stack	*old_last_node;
	int		stack_len;

	stack_len = get_stack_len(*stack);
	if (stack == NULL || *stack == NULL || stack_len == 1) // If the stack is empty, has one element, or is NULL, return
		return ;

	old_first_node = (*stack);
	old_last_node = get_last_node(*stack);
	
	old_last_node->next = old_first_node;			// we point the last node to the old-first-node

	(*stack) = (*stack)->next;						// refresh/update stack. Second node now is the first one.
	(*stack)->prev = NULL;							// the old-second newly the first one now. We refresh/update prev data to NULL because now is the new head of the stack.
	
	old_first_node->prev = old_last_node;			// old-first-node now next point to old-last-node
	old_first_node->next = NULL;					// old-first-node 
}
// ..testing_mode.. : if we are testing the P.S. algo we can aboid printing 
// every comand. it's a way to reduce noise in the terminal.
void	ra(t_stack **a, bool testing_mode)
{
	rotate_stack(a);
	if (!testing_mode)
		write(1, "ra\n", 3);
}
void	rb(t_stack **b, bool testing_mode)
{
	rotate_stack(b);
	if (!testing_mode)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool testing_mode)
{
	rotate_stack(a);
	rotate_stack(b);
	if (!testing_mode)
		write(1, "rr\n", 3);
}

//*   ---------------------
//*   ::  test it dear   ::
//*  ----------------------
// int main(void)
// {
//     t_stack *stack = NULL;
//     // Add some nodes to the stack
//     push_to_bottom_node(&stack, 1);
//     push_to_bottom_node(&stack, 2);
//     push_to_bottom_node(&stack, 3);
//     push_to_bottom_node(&stack, 4);
//     push_to_bottom_node(&stack, 5);
//     push_to_bottom_node(&stack, 6);
//     push_to_bottom_node(&stack, 7);
//     // Print the stack before rotation
//     printf("Stack before rotation: ");
//     print_stack(stack);
//     // Rotate the stack
//     rotate_stack(&stack);
//     // Print the stack after rotation
//     printf("Stack after rotation: ");
//     print_stack(stack);
//     // Free the stack (for good practice)
//     t_stack *current = stack;
//     t_stack *next;
//     while (current)
//     {
//         next = current->next;
//         free(current);
//         current = next;
//     }
//     return 0;
// }