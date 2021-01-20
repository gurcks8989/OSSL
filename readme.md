# OSSL 
##### *`mini_project`*
+ This program calculates the scores of OSSL classes and prints out the scores and credits in a report format. 
+ System control in the manner selected to the menu.
+ This system will make it easier to manage students' scores.


## Syntax highlight linkedlist - C 
```c
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
```

MENU
----
![Oops! This is menu]( https://github.com/gurcks8989/OSSL/blob/master/image/menu.jpg "Menu")

> Receive a number, 0 to 9, and 99 from the user.

## If enter 0, print all members
![Oops! This is menu 0]( https://github.com/gurcks8989/OSSL/blob/master/image/0.Print_all_members.png "0")
##### Below that, the list currently stored in the program is printed.

## If enter 1, Add a new member
![Oops! This is menu 1]( https://github.com/gurcks8989/OSSL/blob/master/image/1._Add_a_new_members.jpg "1")
##### This is a function that receives information about name, student’s numbers, and their scores.

## If enter 2, Remove a member
![Oops! This is menu 2]( https://github.com/gurcks8989/OSSL/blob/master/image/2._Remove_a_member.jpg "2")
##### Enter the student’s numbers that you want to delete.If an invalid value has been entered, it will continue to ask to put correct numbers.

## If enter 3, Modify a member 
![Oops! This is menu 3]( https://github.com/gurcks8989/OSSL/blob/master/image/3.Modify_a_member.png "3")
##### Show the currently student. and wait to enter the student number.

## If enter 4, Open a file
##### Below report.txt file open

## If enter 5, Save a file
##### Below report.txt file save

## If enter 6, Clear all members
##### Delete data stored in the program.

## If enter 7, Sorts the data
![Oops! This is menu 7]( https://github.com/gurcks8989/OSSL/blob/master/image/7.Sort_the_data.png "7")
##### If the menu contains negative numbers, we set it in ascending order and descending order if it is positive.

## If enter 8, Search the members
![Oops! This is menu 8]( https://github.com/gurcks8989/OSSL/blob/master/image/8._Search_the_members.png "8")
##### Enter the element you want to find and output the student that contains the value. Outputs is only at the same value

## If enter 9, Member statistics
![Oops! This is menu 9]( https://github.com/gurcks8989/OSSL/blob/master/image/9._Member_statistics.jpg "9")
##### Only the currently stored grade of the linked list is extracted and represented as percentages. Create a simple bar chart using the percent array created. Afterwards, the percentages for each grade are printed together.

## vi report.txt
![Oops! This is report.txt]( https://github.com/gurcks8989/OSSL/blob/master/image/report_txt.jpg "txt")
##### No. 4 and 5 refer to this text file.
