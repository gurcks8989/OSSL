#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], linkedlist_t * l);
void display_menu();

// main function
int main(){

  linkedlist_t * l ;

	l = linkedlist_alloc() ;

	//Record records[MAX_RECORDS];
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, l);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], linkedlist_t * l){

	// TODO: Modify this function as you need
  printf("\n\n") ;

	if(!strcmp(input, "0"))
		print_all_members(l);
	else if(!strcmp(input, "1"))
		add_a_member(l);
	else if(!strcmp(input, "2"))
		remove_a_member(l);	
	else if(!strcmp(input, "3"))
		modify_a_member(l);
	else if(!strcmp(input, "4"))
		load_the_data(l) ;
	else if(!strcmp(input, "5"))
		save_the_data(l) ;
	else if(!strcmp(input, "6"))
		clear_all_members(l) ;	
	else if(!strcmp(input, "7"))
		sorts_the_order_of_the_data(l) ;
	else if(!strcmp(input, "8"))
		search_the_members(l) ;
	else if(!strcmp(input, "9"))
		display_stats(l);	
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	printf("\n\n");
	printf("*********************************\n");
	printf("**** grade management system ****\n");
	printf("*********************************\n");
	printf("*    0. Print all members       *\n");
	printf("*    1. Add a new member        *\n");
  printf("*    2. Remove a member         *\n"); 
	printf("*    3. Modify a member         *\n");
	printf("*    4. Open a file             *\n");
  printf("*    5. Save a file             *\n");
	printf("*    6. Clear all members       *\n");
  printf("*    7. Sorts the data          *\n");
  printf("*    8. Search the members      *\n");
	printf("*    9. Member statistics       *\n");
	printf("*   99. Quit                    *\n");
	printf("*********************************\n");
}
