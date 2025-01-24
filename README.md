# TODO

### Main.c
- [ ] if one argument handle:
	- [x] split without lixes
- [ ] if many arguments handle that
- [ ] when we have our tab of strings
- When argv is ready
	- [ ] stack init
	- [ ] check if stack A is organised
		- if yes return stack A -> end of program.
		- if not organised :
			- [ ] if 2 :
				- swap
				- end of program
			- [ ] use cases : stack A <= 3 nodes
				- XS algo.
			- [ ] if stack A > 3 nodes.
				- XXL algo.

# Parsing : 
## stack init
- When argv is ready we run stack init function: 

### Inside a while do : 
- [ ] We check every string. If in any case there is a bug like ::	  non nbs +/-           -> error
- If everything is in good shape we atol everything
	- [x] we will need atol (atoi but with a long int to handle INT_MIN/MAX)
- [ ] We check every string. If in any case there is a bug like ::	  int_min  / int_max    -> error
- [ ] We check every string. If in any case there is a bug like ::	  nbs repetitions		-> error
- [ ] we create / append a new node in the stack A.
### Outside the loop
- When stack in full with the needed nodes and the code didn't found any problem
	- [ ] we free all data in argv. We aint gonna need it animore baby !!


## Error FREE (important)
- In case you need to stop the program. You will need to free every elemnt of the stack and also argv. 
	- [ ] free_stack.
	- If argv was already freed (don't free it again).
	- If argv wasn't freed then: 
		- [ ] free_argv.
	- [ ] write 'Error\n' in the terminal
	- Stop push_swap. 

## Instructions

## Algorithme

## XS algo

## XXL algo