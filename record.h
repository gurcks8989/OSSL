#ifndef _RECORD_H_
#define _RECORD_H_

typedef struct node {
  char name[20] ;
  char number[20] ;
  int attend ;
  int midterm ;
  int project ;
  int assign ;
	struct node * next ; 	
} node_t ;

typedef struct linkedlist {
	int length ;
	struct node * first ;
	struct node * last ;
  
} linkedlist_t ;


#endif
