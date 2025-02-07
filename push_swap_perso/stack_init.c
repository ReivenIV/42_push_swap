/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:02:41 by rita              #+#    #+#             */
/*   Updated: 2025/01/28 17:02:41 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Parsing part. Will check if: 
		- int MIN / MAX overflows
		- only 0/9 (char)ints in argv.
		- duplicated
	In case all check are passed: 
		- we create stack A with all the numbers using push_to_bottom_node
			- ex push_to_bottom_node: Stack : (1,2,3)   to_add : 40  ==>  Stack : (1,2,3,40)

		- if (argc == 2) == TRUE then free argv.
*/

void	stack_init(t_stack **stack_a, char **av, bool is_argc_2)
{
	long	l_nbr;
	int		i;

	i = 0;
	while (av[i] != NULL)
	{
		if (!is_syntax_correct(av[i]))								// Do we have only nbrs ?
			free_handler(stack_a, av, is_argc_2);
		l_nbr = ft_atol(av[i]);										// Because we have only numbers atol every single s***
		if (l_nbr > INT_MAX || l_nbr < INT_MIN)						// check if we have bigger or smaller than INT_MIN/MAX
			free_handler(stack_a, av, is_argc_2);

		if (is_nb_in_stack(*stack_a, (int)l_nbr))					// check repetitions. Remember these will check every time we add want to add a number. Is not checkin all the existing stack
			free_handler(stack_a, av, is_argc_2);					
		push_to_bottom_node(stack_a, (int)l_nbr);					// if all checks are passed. We add a new node to the end of the stack. (remember the stack is under construction)
		i++;
	}
	if (is_argc_2 == true)											// in case if is_argc_2 == TRUE(1) we free av to avoid leaks.
		free_argv(av, true);
}																	// Rock it baby

//*   ---------------------
//*   ::  test it dear   ::
//*  ----------------------
// // int main(int argc, char **argv)
// // {
// //     t_stack *stack_a = NULL;
// //     bool is_argc_2 = false;
// //     if (argc < 2)
// //     {
// //         printf("Usage: %s <numbers>\n", argv[0]);
// //         return 1;
// //     }
// //     if (argc == 2)
// //     {
// //         argv = ft_split(argv[1]);
// //         is_argc_2 = true;
// //     }
// //     else
// //     {
// //         argv++; // Skip the program name
// //     }
// //     stack_init(&stack_a, argv, is_argc_2);
// //     // Print the stack to verify
// //     printf("Stack elements: ");
// //     print_stack(stack_a);
// //     // Free the stack
// //     free_stack(&stack_a);
// //     return 0;
// // }