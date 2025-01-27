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

//* Function to print all elements in the stack
void print_stack(t_stack *stack)
{
    t_stack *current = stack;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}


//* creates new node
t_stack *new_node(int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

//* Function to add a node to the stack
void push_node(t_stack **stack, int value)
{
    t_stack *node = new_node(value);
    if (!node)
        return;
    node->next = *stack;
    if (*stack)
        (*stack)->previous = node;
    *stack = node;
}