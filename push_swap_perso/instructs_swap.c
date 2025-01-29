/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:26:53 by rita              #+#    #+#             */
/*   Updated: 2025/01/29 18:26:53 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate ex : stack = "1,2,3" => swap_stack(stack) => "2,1,3"
static	void swap_stack(t_stack **stack)
{
	int		len_stack;
	t_stack	*old_first_node;
	t_stack	*old_second_node;

	len_stack = get_stack_len(*stack);
	old_first_node = (*stack);
	old_second_node = (*stack)->next;
	if (*stack == NULL || stack == NULL || len_stack == 1)
		return ;
	
	*stack = old_second_node;								// we update head of the stack to the second node.

	old_first_node->next = old_second_node->next;
	old_first_node->prev = old_second_node;

	if (old_second_node->next)								// in case there is a 3th node. We update the previous to the old_first (because the old_second is now first)
		old_second_node->next->prev = old_first_node;

	old_second_node->next = old_first_node;					// update old_second now is head of the stack.
	old_second_node->prev = NULL;
}

void	sa(t_stack **a, bool testing_mode)
{
	swap_stack(a);
	if(!testing_mode)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool testing_mode)
{
	swap_stack(b);
	if(!testing_mode)
		write(1, "sb\n", 3);
}
void	ss(t_stack **a, t_stack **b, bool testing_mode)
{
	swap_stack(a);
	swap_stack(b);
	if(!testing_mode)
		write(1, "ss\n", 3);
}


// // int main(void)
// // {
// //     t_stack *stack = NULL;
// //     // Add some nodes to the stack
// //     push_to_bottom_node(&stack, 1);
// //     push_to_bottom_node(&stack, 2);
// //     push_to_bottom_node(&stack, 3);
// //     // Print the stack before rotation
// //     printf("Stack before rotation: ");
// //     print_stack(stack);
// //     // Rotate the stack
// //     swap_stack(&stack);
// //     // Print the stack after rotation
// //     printf("Stack after rotation : ");
// //     print_stack(stack);
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