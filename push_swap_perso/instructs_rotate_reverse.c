/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_rotate_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:05 by rita              #+#    #+#             */
/*   Updated: 2025/01/30 15:18:05 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// rotate ex : stack = "1,2,3" => rotate_stack(stack) => "3,2,1"
static void rotate_reverse_stack(t_stack **stack)
{
    t_stack *old_first_node;
    t_stack *second_node;
    t_stack *old_last_node;
    int stack_len;

    stack_len = get_stack_len(*stack);
    if (stack == NULL || *stack == NULL || stack_len == 1)
        return;

    old_first_node = (*stack);
    second_node = (*stack)->next;
    old_last_node = get_last_node(*stack);

    old_first_node->prev = old_last_node; // the last one now points to the first one.
    old_first_node->next = NULL;

    old_last_node->next = second_node;
    old_last_node->prev = NULL;

    second_node->prev = old_last_node;
    second_node->next = old_first_node;

    (*stack) = old_last_node;
}

int main(void)
{
    t_stack *stack = NULL;

    // Add some nodes to the stack for testing
    push_to_bottom_node(&stack, 1);
    push_to_bottom_node(&stack, 2);
    push_to_bottom_node(&stack, 3);
    //push_to_bottom_node(&stack, 4);
    // push_to_bottom_node(&stack, 5);

    // Print the stack before rotation
    printf("Stack before rotation: ");
    print_stack(stack);

    // Call rotate_reverse_stack
    rotate_reverse_stack(&stack);

    // Print the stack after rotation
    printf("Stack after rotation: ");
    print_stack(stack);

    return 0;
}