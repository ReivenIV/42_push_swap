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

//* Will check src is a (char*)numbers. 
// if valid, TRUE/1
// if not valid, FALSE/0
int	is_syntax_correct(char* src) // error_syntax 
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


int	is_nb_in_stack(t_stack *a, int nb)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

//! ---------------------------------------------------
//! -------------  Testing functions  -----------------
//! ---------------------------------------------------




//* test :: is_nb_in_stack
// // int main(void)
// // {
// //     t_stack *stack = NULL;
// //     // Create a stack with some values
// //     push_node(&stack, 3);
// //     push_node(&stack, 2);
// //     push_node(&stack, 1);
// //     push_node(&stack, 2); // Duplicate value
// //     printf("Stack values: ");
// //     print_stack(stack);
// //     printf("\n");
// //     // Test is_nb_in_stack function
// //     printf("Test 1: %i -> %i\n", 1, is_nb_in_stack(stack, 1)); // Expected: 0 (no repetition)
// //     printf("Test 2: %i -> %i\n", 2, is_nb_in_stack(stack, 2)); // Expected: 0 (no repetition)
// //     printf("Test 3: %i -> %i\n", 3, is_nb_in_stack(stack, 3)); // Expected: 0 (no repetition)
// //     printf("Test 4: %i -> %i\n", 4, is_nb_in_stack(stack, 4)); // Expected: 1 (repetition found)
// //     // Free the stack
// //     free_stack(&stack);
// //     return 0;
// // }
//! ---------------------------------------------------
//! ---------------------------------------------------
//! ---------------------------------------------------

//* will free a stack of nodes.
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

//* Test function for free_stack
// // void test_free_stack()
// // {
// // 	t_stack *stack = NULL;
// // 	// Create a stack with some values
// // 	push_node(&stack, 3);
// // 	push_node(&stack, 2);
// // 	push_node(&stack, 1);
// // 	// Print the stack before freeing
// // 	printf("Stack before freeing: ");
// // 	print_stack(stack);
// // 	// Free the stack
// // 	free_stack(&stack);
// // 	// Check if the stack is NULL after freeing
// // 	if (stack == NULL)
// // 		printf("Stack successfully freed.\n");
// // 	else
// // 		printf("Stack not freed properly.\n");
// // }
// // int main(void)
// // {
// // 	test_free_stack();
// // 	return 0;
// // }

//* Will free all elements in argv and argv itself
void	free_argv(char **av, bool is_ac_2)			// free_matrix argv
{
	int i;

	i = 0;
	while(av[i])									// Will free each string inside of argv but will not free argv it self
	{
		free(av[i]);
		i++;
	}
	if (is_ac_2 == true)							// in case argc was only 2 (meaning a long string at argv[1]) after freeing each element in argv we free argv
		free(av);
}

//* test free_argv (you will need to test it with valgrind)
// int main()
// {
//     // Allocate memory for argv
//     char **argv = (char **)malloc(4 * sizeof(char *));
//     if (!argv)
//         return 1;
//     // Allocate memory for each argument
//     argv[0] = malloc(10 * sizeof(char));
//     argv[1] = malloc(10 * sizeof(char));
//     argv[2] = malloc(10 * sizeof(char));
//     argv[3] = NULL; // Null-terminate the array
//     // Assign values to each argument
//     snprintf(argv[0], 10, "arg1");
//     snprintf(argv[1], 10, "arg2");
//     snprintf(argv[2], 10, "arg3");
//     // Print the arguments
//     for (int i = 0; argv[i] != NULL; i++)
//     {
//         printf("argv[%d] = %s\n", i, argv[i]);
//     }
//     // Free the memory allocated for argv
//     free_argv(argv);
//     return 0;
// }

// Will free all the stack and if argc was only 2 (known by 1/0 TRUE/FALSE) will free all argv aswell
void	free_handler(t_stack **a_or_b, char **argv, bool flag_argc_2) //  error_free
{
	free_stack(a_or_b);

	if (flag_argc_2)
		free_argv(argv, true);
	write(2, "Error\n", 6);
	exit(1);
}

//* Test free_handler
// // #include <string.h>
// // int main(void)
// // {
// //     // Create a simple stack for testing
// //     t_stack *stack = malloc(sizeof(t_stack));
// //     stack->value = 1;
// //     stack->current_position = 0;
// //     stack->previous = NULL;
// //     stack->next = malloc(sizeof(t_stack));
// //     stack->next->value = 2;
// //     stack->next->current_position = 1;
// //     stack->next->previous = stack;
// //     stack->next->next = NULL;
// //     // Create a simple argv array for testing
// //     char **argv = malloc(3 * sizeof(char *));
// //     argv[0] = strdup("arg1");
// //     argv[1] = strdup("arg2");
// //     argv[2] = NULL;
// //     // Call the free_handler function
// //     free_handler(&stack, argv, true);
// //     return 0;
// // }