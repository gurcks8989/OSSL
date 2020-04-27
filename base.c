#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "base.h"

linkedlist_t * linkedlist_alloc (){
	linkedlist_t * l ;
	l = (linkedlist_t *) malloc(sizeof(linkedlist_t)) ;

	l->first = 0x0 ;
	l->last = 0x0 ;
	l->length = 0 ;     //make a empty list

	return l ;
}
enum {F, D, DP, C, CP, B, BP, A, AP} Alpha ;

const char * grade[] = {"F ", "D ", "D+", "C ", "C+", "B ", "B+", "A ", "A+"};

const char* filename = "report.txt" ;


void print_all_members(linkedlist_t * l){
  
  char name[20], number[20] ;
  int attend, midterm, project, assign, score ;


  if(linkedlist_length(l) == 0){
    printf("No data entered!\n") ;
    return ;
  }
  else{
    printf("Student No.| Name | Attend | exam | projects | Assign | Score | Grade\n");
    printf("=====================================================================\n");
    for(int i = 0; i < linkedlist_length(l); i ++){
      memset(name, 0, sizeof(name)) ;
      memset(number, 0, sizeof(number)) ;
      attend = -1, midterm = -1, project = -1, assign = -1 ;

      linkedlist_retrieve(l, i, name, number, &attend, &midterm, &project, &assign) ;
      score = get_a_score(attend, midterm, project, assign) ;

      printf("%s    %s   %3d     %3d      %3d       %3d      %3d      %s\n", number, name, attend, midterm, project, assign, score, grade[Alpha]);
    }
  }
}

int linkedlist_retrieve (linkedlist_t * l, int pos, char name[], char number[], int * attend, int * midterm, int * project, int * assign){

	int i = 0;
  char buffer[20], temp;
	node_t * itr ;

	if (!(pos < l->length))
		return 1 ;

	itr = l->first ; 
	while (i < pos) {
		i++ ;
		itr = itr->next ;
  }
  
	memset(name, 0, 20) ; 
  if(strlen(itr->name) == 6){
		strcpy(buffer, itr->name) ;
		strncpy(buffer, "_  ", 3) ;
		strncat(name, itr->name, 3) ;
		strcat(name, strtok(buffer, "_")) ;
  }
  else
    strcpy(name, itr->name) ;
      
  strcpy(number, itr->number) ;
	*attend = itr->attend ;
	*midterm = itr->midterm ;
	*project = itr->project ;
	*assign = itr->assign ;
	return 0 ;
}

int get_a_score(int attend, int midterm, int project, int assign){
  
  int score, sum ;
  sum = attend*10 + midterm*20 + project*20 + assign*50 ;
  score = sum / 100 ;

  int k = score ;

  if(95 <= k)
    Alpha = AP ;
  else if(90 <= k)
    Alpha = A ;
  else if(85 <= k)
    Alpha = BP ;
  else if(80 <= k)
    Alpha = B ;
  else if(75 <= k)
    Alpha = CP ;
  else if(70 <= k)
    Alpha = C ;
  else if(65 <= k)
    Alpha = DP ;
  else if(60 <= k)
    Alpha = D ;
  else
    Alpha = F ;

  return score ;

}


void add_a_member(linkedlist_t * l){
  char name[20]={0x0}, number[20]={0x0} ;
  int attend = -1, midterm = -1, project = -1, assign = -1, score ;

  printf("Please enter the name and student number of the member\n") ;
  printf("=>(Korean Name) - range(2 ~ 3 letters) : ") ;
  scanf("%s", name) ;
  printf("=>(Student Number) : ") ;
  scanf("%s", number) ;
    
  printf("Enter as follow form(Attendance, Midterm, Team projects, Assignment)\n=>") ;
  scanf("%d,", &attend) ;
  scanf("%d,", &midterm) ;
  scanf("%d,", &project) ;
  scanf("%d", &assign) ;
  linkedlist_insert(l, name, number, attend, midterm, project, assign) ;
  printf("=>Add is complete!\n\n");
  getchar() ;
  
}

void linkedlist_insert (linkedlist_t * l, char name[], char number[], int attend, int midterm, int project, int assign){
	
  node_t * n ;
	n = (node_t *) malloc(sizeof(* n)) ;

  check_a_number(number) ;

	strcpy(n->name, name) ;
  strcpy(n->number, number) ;
  n->attend = check_a_score(attend) ;
  n->midterm = check_a_score(midterm) ;
  n->project = check_a_score(project) ;
  n->assign = check_a_score(assign) ;
	n->next = 0x0 ;

	if (l->length == 0)
		l->first = n ;
	else
		l->last->next = n ;

	l->last = n ;
	l->length += 1 ;
}

int linkedlist_length (linkedlist_t * l) {
	return l->length ;
}


void load_the_data(linkedlist_t * l){
  char name[20]={0x0}, number[20]={0x0}, buffer[20]={0x0} ;
  int attend = -1, midterm = -1, project = -1, assign = -1, score, k = 0 ;

  FILE *fp;
  
  fp = fopen(filename, "rt");
  
  fseek(fp, 1, SEEK_CUR);

  do{
  memset(buffer, 0, sizeof(buffer)) ;
  fseek(fp, 57, SEEK_CUR);
  for(int j = 0; j < 3; j ++){
    fread(buffer, 2, 1, fp);
    if(!strcmp(buffer, "  "))  continue ;
    else{
      strcat(name, buffer) ;
      memset(buffer, 0, sizeof(name)) ;
      fread(buffer, 1, 1, fp);
      strcat(name, buffer) ;
    }
  }

  fseek(fp, 68, SEEK_CUR);
  fread(number, 8, 1, fp);

  fseek(fp, 56, SEEK_CUR);
  fread(buffer, 3, 1, fp);
  attend = atoi(buffer) ;

  fseek(fp, 58, SEEK_CUR);
  fread(buffer, 3, 1, fp);
  midterm = atoi(buffer) ;
  
  fseek(fp, 65, SEEK_CUR);
  fread(buffer, 3, 1, fp);
  project = atoi(buffer) ;

  fseek(fp, 53, SEEK_CUR);
  fread(buffer, 3, 1, fp);
  assign = atoi(buffer) ;
  
  memset(buffer, 0, sizeof(buffer)) ;
  fseek(fp, 198, SEEK_CUR);
  linkedlist_insert(l, name, number, attend, midterm, project, assign) ;
  memset(name, 0, sizeof(name)) ;
  fread(buffer, 3, 1, fp);
  if(!strcmp(buffer, "|\n|"))
    k = 1 ;
  else
    k = 0 ;
  
  }while(k) ;
  
  fclose(fp);
  printf("==>Loading complete!\n") ;
}


void save_the_data(linkedlist_t * l){
  FILE *fp;
  char name[20]={0x0}, number[20]={0x0} ;
  int attend = -1, midterm = -1, project = -1, assign = -1, score ;

  fp = fopen(filename, "wt");

  for(int i = 0; i < linkedlist_length(l); i++){
    linkedlist_retrieve(l, i, name, number, &attend, &midterm, &project, &assign) ;

    if(attend == -1 && midterm == -1 && project == -1 && assign == -1) continue;
    
    score = get_a_score(attend, midterm, project, assign) ;

    fprintf(fp, "|=============================================|\n") ;
    fprintf(fp, "|  Name : %s                              |\n", name) ;
    fprintf(fp, "|                  Student number : %s  |\n", number) ;
    fprintf(fp, "|  _________________________________________  |\n") ;
    fprintf(fp, "|  %3d    •   Attendance………………..10%%           |\n", attend) ;
    fprintf(fp, "|  %3d    •   Midterm………………………..20%%           |\n", midterm) ;
    fprintf(fp, "|  %3d    •   Team projects………..20%%           |\n", project) ;
    fprintf(fp, "|  %3d    •   Assignment………………..50%%           |\n", assign) ;
    fprintf(fp, "|  _________________________________________  |\n") ;
    fprintf(fp, "|  The total score is %3d      Grade :  %s    |\n", score,  grade[Alpha]) ;
    fprintf(fp, "|=============================================|\n") ;
  }
  fclose(fp);
  printf("=> Saved!\n");
}

void check_a_number(char number[]){

  if(strlen(number)<8){
  	char temp[20] = {0x0} ;
    
		for(int i=0; i < 8 - strlen(number); i++){
      strcat(temp, "0") ;
		}
    strcat(temp, number) ;
    strcpy(number, temp) ;
  }
  else if(8 < strlen(number))
    number[8] = '\0' ;

	for(int i = 0; i < 8; i++)
		while(!isdigit(number[i]))
			if('9' < number[i] || number[i] < '0')
				number[i] = '0' ;
}


int check_a_score(int score){
	
	if(score < 0) //input : negative number
		score *= -1 ;
	while(100 < score) // input : oversize
		score /= 10 ;
	
	return score ;
}

void modify_a_member(linkedlist_t *l){
  
  char number[20]={0x0} ;
  int pos = 0 ;
  do{
    print_all_members(l);
    printf("What student(Number) do you want to modify?(Cancel : 0) ") ;

    scanf("%s", number) ;
    printf("\n") ;
    getchar() ;
    if(atoi(number) == 0){
      printf("==>Cancel!\n") ;
      return ;
    }
    check_a_number(number) ;
  
    pos = find_a_location(l, number) ;
  }while(pos == -1) ;

  update_a_member(l, pos) ;
  printf("\n=>Modification completed!\n");
}

int find_a_location(linkedlist_t * l, char number[]){

	int pos = 0 ;
	node_t * itr ;

	itr = l->first ; 

	while (strcmp(itr->number, number)) {
		pos += 1 ;
		itr = itr->next ;
    if(l->length == pos){
      printf("This number is wrong number\n\n") ;
      return -1 ;
    }
	}
	return pos ;
}

void element_menu(){
  printf("****************************\n") ;
  printf("*   1. Name                *\n") ;
  printf("*   2. Student Number      *\n") ;
  printf("*   3. Attendance Score    *\n") ;
  printf("*   4. Midterm Score       *\n") ;
  printf("*   5. Team projects       *\n") ;
  printf("*   6. Assignment          *\n") ;
  printf("****************************\n") ;
}

void update_a_member(linkedlist_t * l, int pos){

  int menu, i = 0 ;
  char input[20] ;
	node_t * n ;

	n = l->first ; 
	while (i < pos) {
		i++ ;
		n = n->next ;
	}
  element_menu() ;
  printf("Select a menu> ") ;
  scanf("%d", &menu) ;
  getchar() ;
  printf("Enter an input> ") ;
  scanf("%s", input) ;
  getchar() ;
  switch(menu){
    case 1 : strcpy(n->name, input) ;   break ;
    case 2 : strcpy(n->number, input) ; break ;
    case 3 : n->attend = atoi(input) ;  break ;
    case 4 : n->midterm = atoi(input) ; break ;
    case 5 : n->project = atoi(input) ; break ;
    case 6 : n->assign = atoi(input) ;  break ;
  }
}

void remove_a_member(linkedlist_t * l){

  char number[20]={0x0} ;
  int pos = 0 ;
  do{
    print_all_members(l);
    printf("What student(Number) do you want to remove?(Cancel : 0) ") ;

    scanf("%s", number) ;
    printf("\n") ;
    getchar() ;
    if(atoi(number) == 0){
      printf("==>Cancel!\n") ;
      return ;
    }
    check_a_number(number) ;
  
    pos = find_a_location(l, number) ;
  }while(pos == -1) ;

  delecte_a_member(l, pos) ;
  
  printf("\n=>Removed complete!\n");
}

void delecte_a_member(linkedlist_t * l, int pos){

  char input[20]={0x0} ;
	node_t * n = 0x0 ;

	if(pos == 0){
    n = l->first ;
	  l->first = l->first->next ;
    free(n) ;
  }
  else{
    node_t* curr = 0x0 ;
    curr = l->first ; 
    for (int i=0 ; i < pos ; curr = curr->next, i++)
      n = curr ;
    n = l->last ;
    free(curr) ;
  }
	l->length -= 1 ;
	if (l->length == 0) {	
		l->first = 0x0 ; 
		l->last = 0x0 ;
	}
}


void clear_all_members(linkedlist_t * l){

  char answer ;
  int k = 1 ;

 	printf("Are you sure you want to delete all members?(Y/N) : ") ;
  while(k){
  	scanf("%c", &answer) ;
		while(getchar() != '\n');

		switch(answer){
				case 'Y' :
				case 'y' :
					k = 0 ;
					break ;
				case 'N' :
				case 'n' :
					printf("\n=>Cancel\n") ;
					return ;
		}
		printf("Wrong value!! Re-enter please : ") ;
	}
 	
  node_t * curr ;
  node_t * n ;
  
	while(0 <= l->length){
	  n = (node_t *) malloc(sizeof(* n)) ;
    curr = l->first ;
    n = curr ;
    curr = curr->next ;
    free(n) ;
    l->length -= 1 ;
  }
  free(curr) ;
  l->length = 0 ;
  l->first = 0x0 ;
  l->last = 0x0 ;
  printf("\n=>All member clear!\n");
}




void search_the_members(linkedlist_t * l){
  int menu ;
  char input[20]={0x0} ;
  node_t * n ;
  linkedlist_t * search_result ;
  search_result = linkedlist_alloc () ;

  element_menu() ;

  printf("Select a menu> ") ;
  scanf("%d", &menu) ;
  printf("Enter the search element >") ;
  scanf("%s", input) ;
  getchar() ; 
  printf("\n\n") ;
  
  n = l->first ;
  for(int i=0; i < l->length; i++, n=n->next){
    if(not_eqauls(menu, n, input))      continue ;
    else{
      linkedlist_insert(search_result, n->name, n->number, n->attend, n->midterm, n->project, n->assign) ;
      
    }
  }
  print_all_members(search_result) ;
  
  free(search_result) ;
}


int not_eqauls(int menu, node_t * node_1, char input[]){

  switch(menu){
    case 1 : return (strcmp(node_1->name, input) != 0) ;
    case 2 : return (strcmp(node_1->number, input) != 0) ;
    case 3 : return (node_1->attend != atoi(input)) ;
    case 4 : return (node_1->midterm != atoi(input)) ;
    case 5 : return (node_1->project != atoi(input)) ;
    case 6 : return (node_1->assign != atoi(input)) ;
    default : return 0 ;
  }
}
