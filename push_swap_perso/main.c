/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:53:39 by rita              #+#    #+#             */
/*   Updated: 2025/01/23 15:53:39 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (ac == 1 || (ac == 2 && !av[1][0]))				// if ac doesn't have arguments or If ac has arguments but av[1] is empty
// 		return (1);
// 	else if (ac == 2)
// 	{
// 		av = ft_split(av[1]);
// 		stack_init(&stack_a, av, true);
// 	}
// 	else
// 		stack_init(&stack_a, av + 1, false); 					// av + 1 ?
// 	if (!is_stack_sorted(stack_a))
// 		algo_handler(&stack_a, &stack_b);

// 	printf("----------------------");	
// 	print_stack_json(stack_a, 'a');
// 	print_stack_json(stack_b, 'b');
// 	free_stack(&stack_a);
// }