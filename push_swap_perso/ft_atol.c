/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:02:59 by rita              #+#    #+#             */
/*   Updated: 2025/01/24 16:02:59 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *src)
{
	long int	nb;
	int			power;
	int			i;

	nb = 0;
	i = 0;
	power = 1;
	while (src[i] == ' ')
		i++;
	if (src[i] == '+' || src[i] == '-')
	{
		if (src[i] == '-')
			power = power * -1;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		nb = nb * 10 + src[i] - '0';
		i++;
	}
	return (nb * power);
}

//   ---------------------
//   ::  test it dear   :: 
//   ---------------------

// // #include <stdio.h>
// // #include <limits.h>
// // int main(void)
// // {
// //     const char *test1 = "12345";
// //     const char *test2 = "-12345";
// //     const char *test3 = "0";
// //     const char *test4 = "9223372036854775807"; // LONG_MAX
// //     const char *test5 = "-9223372036854775808"; // LONG_MIN
// //     const char *test6 = "2147483647"; // INT_MAX
// //     const char *test7 = "-2147483648"; // INT_MIN

// //     printf("Test 1: %s -> %ld\n", test1, ft_atol(test1));
// //     printf("Test 2: %s -> %ld\n", test2, ft_atol(test2));
// //     printf("Test 3: %s -> %ld\n", test3, ft_atol(test3));
// //     printf("Test 4: %s -> %ld\n", test4, ft_atol(test4));
// //     printf("Test 5: %s -> %ld\n", test5, ft_atol(test5));
// //     printf("Test 6: %s -> %ld\n", test6, ft_atol(test6));
// //     printf("Test 7: %s -> %ld\n", test7, ft_atol(test7));

// //     return 0;
// // }