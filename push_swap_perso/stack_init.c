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


void	stack_init(t_stack **stack_a, char **argv, bool is_argc_2)
{
	long	l_nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!is_syntax_correct(argv[i]))
			free_handler(stack_a, argv, is_argc_2);
		l_nbr = ft_atol(argv[i]);
		if (l_nbr > INT_MAX || l_nbr < INT_MIN)
			free_handler(stack_a, argv, is_argc_2);
		if (is_nb_in_stack(*stack_a, (int)l_nbr))
		{
			free_handler(stack_a, argv, is_argc_2);
		}
		push_to_bottom_node(stack_a, (int)l_nbr);
		i++;
	}
	if (is_argc_2)
		free_argv(argv);
}


//   ---------------------
//   ::  test it dear   :: 
//   ---------------------

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