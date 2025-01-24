#include "push_swap.h"


// Will check src is a number. 
// if valid, TRUE/1
// if not valid, FALSE/0
int	syntax_check(char* src)
{
	int i;

	if (!(src[0] == '+' || src[0] == '-' || (src[0] >= '0' && src[0] <= '9'))) 		// if first char is not +/-/nb
		return (0);
	if (src[0] == '+' || src[0] == '-' && !(src[1] >= '0' && src[1] <= '9'))			// if first char is +/- 
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		if (!(src[i] >= '0' && src[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
/*
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
*/