/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:02:41 by rita              #+#    #+#             */
/*   Updated: 2025/02/11 13:53:24 by rita             ###   ########.fr       */
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
			- ex push_to_bottom_node: Stack : (1,2,3)   
				to_add : 40  ==>  Stack : (1,2,3,40)

		- if (argc == 2) == TRUE then free argv.
*/
void	stack_init(t_stack **stack_a, char **av, bool is_argc_2)
{
	long	l_nbr;
	int		i;

	i = 0;
	while (av[i] != NULL)
	{
		if (!is_syntax_correct(av[i]))
			free_handler(stack_a, av, is_argc_2);
		l_nbr = ft_atol(av[i]);
		if (l_nbr > INT_MAX || l_nbr < INT_MIN)
			free_handler(stack_a, av, is_argc_2);
		if (is_nb_in_stack(*stack_a, (int)l_nbr))
			free_handler(stack_a, av, is_argc_2);
		push_to_bottom_node(stack_a, (int)l_nbr);
		i++;
	}
	if (is_argc_2 == true)
		free_argv(av, true);
}
