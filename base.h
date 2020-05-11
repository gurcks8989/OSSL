#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"


linkedlist_t *  linkedlist_alloc()  ;	

void linkedlist_insert (linkedlist_t * l, char name[], char number[], int attend, int midterm, int project, int assign) ;

int linkedlist_length (linkedlist_t * l) ;
// function prototypes
void print_all_members(linkedlist_t * l);

int linkedlist_retrieve (linkedlist_t * l, int pos, char name[], char number[], int * attend, int * midterm, int * project, int * assign) ;

int get_a_score(int attend, int midterm, int project, int assign) ;

void add_a_member(linkedlist_t * l);

void load_the_data(linkedlist_t * l) ;

void save_the_data(linkedlist_t * l) ;

void check_a_number(char number[]) ;

int check_a_score(int score) ;

void modify_a_member(linkedlist_t *l) ;

int find_a_location (linkedlist_t * l, char number[]) ;

void element_menu() ;

void update_a_member(linkedlist_t * l, int pos) ;

void remove_a_member(linkedlist_t * l) ;

void delecte_a_member(linkedlist_t * l, int pos) ;

void clear_all_members(linkedlist_t * l) ;	

void search_the_members(linkedlist_t * l) ;

int not_eqauls(int menu, node_t * node_1, char input[]) ;

//update this part
//find a data record(s) by specifying 2+ (2 or more than 2) conditions
int not_search(node_t * node_1, char name[], char number[]);

void search_the_exact_member(linkedlist_t * l);
//finish

#endif
