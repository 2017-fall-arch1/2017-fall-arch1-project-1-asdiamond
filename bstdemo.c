#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "bst.h"		/* for list operations */
//i put some function declarations in a header to make
//some other work easier on myself
#include "bstdemo.h"

/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit, FILE *stream)	
{
  char *p = s;			/* for indexing into s */
  char c;
  if (fgets(s, limit, stream)) {
    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */
      p++;
    if (c == '\n')		/* erase \n */
      *p = 0;
  }
  return (p - s);		/* #chars read (not including terminator or \n*/
}

void addEmployees(BinarySearchTree *bst){
	printf("Enter a name or q to quit:\n");
 	while (gets_n(buf, 100, stdin)){	/* build list */
		printf("Enter a name or q to quit:\n");
		if(strcmp(buf, "q") == 0)//buf == q
			return;
  		BSTInsert(bst, buf);
	}
}

int main()
{
	printf("Welcome to the Aleksandr Diamond personnel management system\n");
	BinarySearchTree *bst = BSTAlloc();	/* make empty bst */
	while(1){
		printf("Would you like to add employees (1), print the bst (2), " );
		printf("remove employees (3), write bst to file (4), read bst from file (5) ");
		printf("or quit (0)\n");

		gets_n(buf, 100, stdin);//picks up their response to the above question
		
		if(buf[0] == '0')//option to exit
			break;
		else if(buf[0] == '1')//option to add employees
			addEmployees(bst);
		else if(buf[0] == '2')//option to pprint bst
			pprintBST(bst);
		else if(buf[0] == '3'){//option to remove employees
			printf("Enter employee you want to remove\n");
			gets_n(buf, 100, stdin);
			removeNode(bst, buf);
		}
		else if(buf[0] == '4'){//option to serialize bst to a file
			printf("Enter the filename\n");
			gets_n(buf, 100, stdin);
			//fopen returns a FILE* to whatever the user entered in the buf.
			//w opens for writing, it overwrites whatever was there before.
			FILE *outputf = fopen(buf, "w");
			serializeBST(bst, outputf);
			fclose(outputf);
		}
		else if(buf[0] == '5'){//option to read bst from file
			printf("Enter the filename\n");
			gets_n(buf, 100, stdin);
			FILE *inputf = fopen(buf, "r");//r option is for read file buf
			deserializeBST(bst, inputf);
			fclose(inputf);
		}
	}


  return 0;
}
