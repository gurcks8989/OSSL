#include <stdio.h>
#include <string.h>
#include "extras.h"
#include "base.h"

enum {F, D, DP, C, CP, B, BP, A, AP} Alpha ;
extern char * grade[] ;

// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void display_stats(linkedlist_t * l){
  int percentage[10] = {0x0} ;
  create_a_percentage(l, percentage) ;
  
  printf("__________________________________________________\n") ;
  printf("    ↑                                     \n") ;
  printf("100%%|                                     \n") ;
  for(int i=10; i > 0 ; i--){
    if(i==1)
      printf("____|___") ; 
    else
      printf("    |   ") ;
    print_grade_block(i, percentage) ;
    if(i==1)
      printf("_____=>\n") ;
    else
      printf("       \n") ;
  }
  printf("    |   F   D   D+  C   C+  B   B+  A   A+        \n\n") ;
	printf("(displayed on the graph every 10%% of the value)\n\n\n") ;
  printf("%2d student | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", linkedlist_length(l), grade[8], grade[7], grade[6], grade[5], grade[4], grade[3], grade[2], grade[1], grade[0]) ;
  printf("===========|====|====|====|====|====|====|====|====|====|\n") ;
  printf(" percentage| %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d |\n", percentage[8], percentage[7],percentage[6], percentage[5], percentage[4], percentage[3], percentage[2], percentage[1], percentage[0]);
  printf("\n") ;
}


void create_a_percentage(linkedlist_t * l, int count[]){
  
  char name[20]={0x0}, number[20]={0x0} ;
  int attend=-1, midterm=-1, project=-1, assign=-1, sum = 0 ;

  for(int i=0; i<linkedlist_length(l); i++){
    linkedlist_retrieve(l, i, name, number, &attend, &midterm, &project, &assign) ;
    get_a_score(attend, midterm, project, assign) ;
    count[Alpha] += 1 ;
  }
  for(int i=0; i < 9; i++){
    if(count[i]!=0)
      count[i] *= 100/linkedlist_length(l) ;
  }
}

void print_grade_block(int pos, int percentage[]){
  
  for(int i=0; i < 9; i++){
    if(pos != 1){
      if(percentage[i]/10 < pos)
        printf("    ") ;
      else
        printf("■■  ") ;
    }
    else{
      if(percentage[i]/10 < pos)
        printf("____") ;
      else
        printf("■■__") ;
    }
    
  }
}

void sorts_the_order_of_the_data(linkedlist_t * l){

  int menu, temp ;
  char temp_string[20]={0x0} ;
  node_t * n ;
  node_t * curr ;

  n = l->first ;
  element_menu() ;


  printf("If you want to sort in ascending order, please enter a negative number.\n") ;
  printf("(Default : If entered positive number, sort in descending order.)\n") ;
  printf("Select a menu> ") ;
  scanf("%d", &menu) ;
  getchar() ;

  for(int i = 0; i < l->length ; i++, n=n->next){
    curr = n ;
    for(int j = i ; j < l->length ; j++, curr=curr->next){
      if(button_sort(menu, n, curr)){
        strcpy(temp_string, curr->name) ;
        strcpy(curr->name, n->name) ;
        strcpy(n->name, temp_string) ;

        memset(temp_string, 0, sizeof(temp_string)) ;
        strcpy(temp_string, curr->number) ;
        strcpy(curr->number, n->number) ;
        strcpy(n->number, temp_string) ;

        temp = curr->attend ;
        curr->attend = n->attend;
        n->attend = temp ;

        temp = curr->midterm ;
        curr->midterm = n->midterm;
        n->midterm = temp ;
        
        temp = curr->project ;
        curr->project = n->project;
        n->project = temp ;
        
        temp = curr->assign ;
        curr->assign = n->assign;
        n->assign = temp ;
      }
    }
  }
  printf("\n=>Sorted complete!\n");
}

int button_sort(int menu, node_t * node_1, node_t * node_2){

  switch(menu){
    case -1 : return (0 < strcmp(node_2->name, node_1->name)) ;
    case -2 : return (0 < strcmp(node_2->number, node_1->number)) ;
    case -3 : return (node_2->attend < node_1->attend) ;
    case -4 : return (node_2->midterm < node_1->midterm) ;
    case -5 : return (node_2->project < node_1->project) ;
    case -6 : return (node_2->assign < node_1->assign) ;
    //positive number sort in ascending order

    case 1 : return (strcmp(node_2->name, node_1->name) < 0) ;
    case 2 : return (strcmp(node_2->number, node_1->number) < 0) ;
    case 3 : return (node_2->attend > node_1->attend) ;
    case 4 : return (node_2->midterm > node_1->midterm) ;
    case 5 : return (node_2->project > node_1->project) ;
    case 6 : return (node_2->assign > node_1->assign) ;
    //negative number sort in descending order
    default : return 0 ;
  }
}

