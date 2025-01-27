/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:28:04 by rita              #+#    #+#             */
/*   Updated: 2025/01/27 14:28:04 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//* Will check src is a (char*)number. 
// if valid, TRUE/1
// if not valid, FALSE/0
int	check_syntax(char* src) // error_syntax 
{
	int i;
	
	i = 0;
	if (src == NULL)
		return (0);
	if (!(src[0] == '+' || src[0] == '-' || (src[0] >= '0' && src[0] <= '9'))) 		// if first char is not +/-/nb => 0
		return (0);
	if ((src[0] == '+' ||  src[0] == '-') && !(src[1] >= '0' && src[1] <= '9'))		// if first char is +/- & second not nb => 0
		return (0);
	if ((src[0] == '+' ||  src[0] == '-') && (src[1] >= '0' && src[1] <= '9'))		// if first char is +/- & second nb => i+1 otherwise the loop will not like it.
		i++;
	while (src[i] != '\0')															// loop src
	{
		if (!(src[i] >= '0' && src[i] <= '9'))										// if its not nb => 0
			return (0);
		i++;
	}
	return (1);																		// if all the checks are false then. TRUE baby !!
}

//* test syntax_check
// // int main(void)
// // {
// //     char *test1 = "123";
// //     char *test2 = "+123";
// //     char *test3 = "-123";
// //     char *test4 = "12a3";
// //     char *test5 = "+-123";
// //     char *test6 = "";
// //     char *test7 = NULL;

// //     printf("Test 1: %s -> %d\n", test1, syntax_check(test1)); // Expected: 1
// //     printf("Test 2: %s -> %d\n", test2, syntax_check(test2)); // Expected: 1
// //     printf("Test 3: %s -> %d\n", test3, syntax_check(test3)); // Expected: 1
// //     printf("Test 4: %s -> %d\n", test4, syntax_check(test4)); // Expected: 0
// //     printf("Test 5: %s -> %d\n", test5, syntax_check(test5)); // Expected: 0
// //     printf("Test 6: %s -> %d\n", test6, syntax_check(test6)); // Expected: 0
// //     printf("Test 7: %s -> %d\n", test7, syntax_check(test7)); // Expected: 0

// //     return 0;
// // }

// Function to free the stack
void	free_stack(t_stack **stack)
{
	t_stack	*tmp_node;
	t_stack *current_node;

	if (stack == NULL)
		return ;
	current_node = *stack;
	while (current_node)
	{
		tmp_node = current_node->next;
		free(current_node);
		current_node = tmp_node;
	}
	*stack = NULL;
	return ;
}

// TODO		 int	check_repetitions()
int	check_repetitions(t_stack *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

//----------------------------------------------------
//------------------Testing functions ----------------
//----------------------------------------------------

// Function to print all elements in the stack
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


// Function to create a new stack node
t_stack *new_node(int value)
{
    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

// Function to add a node to the stack
void push(t_stack **stack, int value)
{
    t_stack *node = new_node(value);
    if (!node)
        return;
    node->next = *stack;
    if (*stack)
        (*stack)->previous = node;
    *stack = node;
}



int main(void)
{
    t_stack *stack = NULL;

    // Create a stack with some values
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);
    push(&stack, 2); // Duplicate value

    printf("Stack values: ");
    print_stack(stack);
    printf("\n");

    // Test check_repetitions function
    printf("Test 1: %i -> %i\n", 1, check_repetitions(stack, 1)); // Expected: 0 (repetition found)
    printf("Test 2: %i -> %i\n", 2, check_repetitions(stack, 2)); // Expected: 0 (repetition found)
    printf("Test 3: %i -> %i\n", 3, check_repetitions(stack, 3)); // Expected: 1 (no repetition)
    printf("Test 4: %i -> %i\n", 4, check_repetitions(stack, 4)); // Expected: 1 (no repetition)

    // Free the stack
    free_stack(&stack);

    return 0;
}
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------


//* Will free all elements in argv
void	free_argv(char **argv)			// free_matrix
{
	int i;

	//i = -1;							//!	not sure why -1
	i = 0;								//!	updated to 0
	while(argv[i])
	{
		free(argv[i]);
		i++;
	}
	// free(argv - 1);					//! not sure why (argv - 1)
	free(argv);
}

//* will free a stack of nodes. 


void	free_handler(t_stack **a_or_b, char **argv, bool flag_argc_2) //  error_free
{
	free_stack(a_or_b);
	if (flag_argc_2)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}