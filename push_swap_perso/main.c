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

void print_argv(char **av)
{
    int i = 0;
    while (av[i] != NULL)
    {
        printf("argv[%d]: %s\n", i, av[i]);
        i++;
    }
}

// int	main(int ac, char **av)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (ac == 1 || (ac == 2 && !av[1][0]))				// if ac doesn't have arguments or If ac has arguments but av[1] is empty
// 		return (1);
// 	else if (ac == 2)
// 	{
// 		av = ft_split(av[1]);
// 		stack_init(&a, av, true);
// 	}
// 	else
// 		stack_init(&a, av + 1, false); 					// av + 1 ?
// 	if (!is_stack_sorted(a))
// 	{
// 		if (get_stack_len(a) == 2)
// 			sa(&a, false);
// 		else if (get_stack_len(a) == 3)
// 			sort_three_nbs(&a);
// 		//else if (get_stack_len(a) > 3)
// 			//push_swap algo and we handle 4 & 5 and infinit inside 
// 	}
// 	free_stack(&a);
// }
