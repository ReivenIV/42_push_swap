I shoud do a nicer readme ^^

Sincere recomendations : 
 - Don't panic see these proyect just as an inistiation to linked lists
 - i propose you to check the commented version like that you will have a better understanding of what is going on.

# Stats of these push_swap : 

- Started date : 22/01/2025.
- Finished date : 11/02/2025.
- validated date : 12/02/2025.
- Validated with : 98 points.
- Time spend coding these project : 46hrs 32min

### 100 random numbers 100 runs:
 - worst : 677
 - median : 605
 - best : 531
 - deviation : 28.8
 - effectivnes : 100%
 - objective of less than 700 moves : 100%

### 500 random numbers 100 runs:
 - worst : 5746
 - median : 5480
 - best : 5102
 - deviation : 123.3
 - effectivnes : 100%
 - objective of less than 5500 moves : ~60%

# TODO

## Doesn't matter what they say. Do CESS & TESS
- **CESS** = Comment Every Single s**
- **TESS** = Test Every Single s**
- write code that you will understand in 6 month !


## The project logic
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
	- [x] Create instructions:
		- [x] Swap
			- [x] sa
			- [x] sb
			- [x] ss
		- [x] Push
			- [x] pa	
			- [x] pb
		- [x] Reverse
			- [x] ra
			- [x] rb
			- [x] rr
		- [x] Reverse Rotate:
			- [x] rra
			- [x] rrb
			- [x] rrr
	- [x] Check if stack A is organised:
		- [x] create function that check if the stack is organized in ascending order.
		- if yes return stack A -> end of program baby!! .
		- if not organised "hell on earth":
			- [x] if 2 :
				- swap
				- end of program
			- [x] if 3. sort_3_algo:
				- there are only 5 ways to do 
			- [x] if 4 :
				- [x] test it.
				- [x] push smallest to B then sort_3_algo
			
			- [x] if 5 :
				- [x] push smallest to B
				- [x] sort_4_algo.
				- Something more
			- if stack A > 5 nodes.
				-  [x] sort_random_amount
			- [x] create algo_handler to manage wich algo should be used in every sitaution

---


# Algo
	- tools:
		- data: 
			- [x] refresh_nodes_data
				- [x] refresh_ids (& is_above_median)
					- super usefull every time we move, push, rotate something we update every id and is_above_median flag.
				- [x] refresh_targets_node
					- will update tager_node with the smallest-bigger node in the oposite stack.
				- [x] set_prices
					- will update prices related to target_node and current id.
				- [x] flag_cheapest
					- after setting prices now we can flag the cheapest node.
		- get: 
			- [x] get smallest
			- [x] get cheapest
			- [x] get lenth
			- [x] get last node
		- move
			- [x] move target to top

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
			- [x] TESS: Test Every Single s**
			
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
		- [x] TESS: Test Every Single s**

--- 


07/02/2025

	TODO :

		- [x] connect sort_4
		- [x] create connect sort_5
		- [x] sort_5 fixbug.
		- [x] start looking for sort_100 / sort_500

--- 
08/02/2025

	TODO :

		- [x] debug refresh_nodes_data
		- [x] sort_random_amount is seg faulting. check whats going on. I think the problems is related to refresh_nodes_data not adding data and the ids:-1 are creating the problem. 
--- 
10/02/2025

	TODO :
		- [x] Norminette
		- [x] Well structured .h
		- [x] use checker
		- [x] create Makefile
		- [x] check leaks (valgrind)
		- [x] Update all file names in headers
		- [x] use tester to see average 100/500 movements result
		- [x] Bugs found
			- [x] not handling well negative numbers at 2 or 3
			- [x] don't accept inputs with more than 10 digits (atol wiil not handle that s*)
