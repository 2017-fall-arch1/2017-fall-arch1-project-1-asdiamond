#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "bst.h"		

int llDoCheck = 1;		/* set true for paranoid consistency checking */
//a debug flag

#define doCheck(_lp) (llDoCheck && llCheck(_lp))

/* create a new list */
BinarySearchTree *BSTAlloc()
{
  BinarySearchTree *bst = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));
  bst->root = 0;
  //doCheck(lp);
  return bst;
}

/* recycle a list, discarding all items it contains */
void BSTFree(BinarySearchTree *bst)
{
	printf("Called BST free\n");
  //doCheck(lp);
  BSTMakeEmpty(bst);
  free(bst);
}

/* Delete all elements off of the list */
void BSTMakeEmpty(BinarySearchTree *bst)
{
/*
  LLItem *current = lp->first, *next;
  doCheck(lp);
  while (current) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  lp->first = lp->last = 0;	/* list is empty */
 // doCheck(lp);
	printf("Called BSTMakeEmpty\n");
}
  
/* append a copy of str to end of list */
//TODO this is gonna be a little more complicated for bst...
void BSTInsert(BinarySearchTree *bst, char *s)
{
	printf("Called BST Insert\n");
	int len;
	char *scopy;
	Node *a;

	for (len = 0; s[len]; len++);//get s length

	scopy = (char *)malloc(len + 1);//malloc char * of size s
	for(len = 0; s[len]; len++)
		scopy[len] = s[len];//copy it into scopy
	scopy[len] = 0;//terminate copy with \0

	a = (Node *)malloc(sizeof(Node));
	a->str = scopy;
	a->leftChild = NULL;
	a->rightChild = NULL;
	
	bst->root = addNode(bst->root, a);//add node to bst
  	//doCheck(lp);
}

//TODO test this implementation...
Node* addNode(Node *root, Node *a){
	if(root == NULL){
		return a;
	}
	int cmpval = strcmp(a->str, root->str);
	if(0 > cmpval) {//a < root
		return addNode(root->leftChild, a);
	}
	else {//a >= root
		return addNode(root->rightChild, a);
	}
}

/* helper, prints bst in order node by node */
void printInorder(Node *root){
	if(root == NULL) return;
	printInorder(root->leftChild);
    	printf("<%s>\n", root->str);
	printInorder(root->rightChild);
}

/* check llist consistency */
//TODO reimplement this to make sure bst fulfills its max min stuff.
/*
int llCheck(LList *lp)
{
  LLItem *ip;
  ip = lp->first;
  if (!ip) 
    assert(lp->last == 0);
  else {
    for (; ip->next; ip = ip->next);
    assert(ip == lp->last);
  }
  return 0;
}
*/
