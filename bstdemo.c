#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "bst.h"		/* for list operations */

/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit)	
{
  char *p = s;			/* for indexing into s */
  char c;
  if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */
      p++;
    if (c == '\n')		/* erase \n */
      *p = 0;
  }
  return (p - s);		/* #chars read (not including terminator or \n*/
}

int main()
{
	printf("Welcome to the Aleksandr Diamond personnel management system\n");
	printf("Please enter employee names less than 100 chars long\n");

  	char buf[100];
	BinarySearchTree *bst = BSTAlloc();	/* make empty bst */

	printf("Enter a name or q to quit:\n");
  	while (gets_n(buf, 100)){	/* build list */
		printf("Enter a name or q to quit:\n");
		if(strcmp(buf, "q") == 0)//buf == q
			break;
  		BSTInsert(bst, buf);
	}

	printf("Here are the bst contents:\n");
	pprintBST(bst);

  return 0;
}
