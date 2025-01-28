# TODO

# Doesn't matter what they say do CESS & TESS
- **CESS** = Comment Every Single Shit
- **TESS** = Test Every Single Shit
### TOOD my dear !!
- [x] if one argument handle:
	- [x] split without lixes
- [x] if many arguments -> send the argv to stack_init
- When argv is ready (from split)
	- [x] parsing - Validator - checks:
		- [x] stack init
			- [x] check quality inputs.
			- [x] Error handling.
			- [x] leaks handling.
			- [x] create stack A.
			- [x] add all values to stack A.
	- [ ] Create instructions: 
		- [ ] something.
		- [ ] something.
		- [ ] something.
		- [ ] something.
		- [ ] something.
	- [ ] Check if stack A is organised
		- if yes return stack A -> end of program baby!! .
		- if not organised :
			- [ ] if 2 :
				- swap
				- end of program
			- [ ] use cases : stack A <= 3 nodes
				- XS algo.
			- [ ] if stack A > 3 nodes.
				- XXL algo.
---
# Parsing :

	## stack init
		- When argv is ready we run stack init function: 
			- Inside a while :
				- [x] We check every string. If in any case there is a bug like ::	  non nbs +/-           -> error
				- If everything is in good shape we atol everything
					- [x] we will need atol (atoi but with a long int to handle INT_MIN/MAX)
				- [x] We check every string. If in any case there is a bug like ::	  int_min  / int_max    -> error
				- [x] We check every string. If in any case there is a bug like ::	  nbs repetitions		-> error
				- [x] we create / append a new node in the stack A.
			- Outside the loop
				- When stack in full with the needed nodes and the code didn't found any problem
					- [x] we free all data in argv. We aint gonna need it animore baby !!
			- [x] TESS: Test Every Single Shit
			
		## error_handler.c :: FREE errors or mallocs = NULL (super important)
		- In case you need to stop the program. You will need to free every elemnt of the stack and also argv. 
			- [x] free_stack.
			- If argv was already freed (don't free it again).
			- If argv wasn't freed then: 
				- [x] free_argv.
			- [x] write 'Error\n' in the terminal
			- [x] Stop push_swap. 

		## stack_tools.c
		- [x] print_stack													<!--! just for testing  -->
			- just for testing: will print all the stack values
		- [x] create_new_node
			- [x] will create a new node with the given value.
			- [x] new_node->next/prev set to NULL by default.	
		- [x] push_to_top_node												<!--! just for testing  -->
			- ex: Stack : (1,2,3) to_add : 40  ==>  Stack : (40,1,2,3)   
		- [x] get_last_node
		- [x] push_to_bottom_node
			- [x] will need to go to the end of the current stack.
			- [x] when in the end. add a new node.
			- ex: Stack : (1,2,3) to_add : 40  ==>  Stack : (1,2,3,40)
		- [x] TESS: Test Every Single Shit

---
## Instructions

---
# Algo

## XS algo

## XXL algo