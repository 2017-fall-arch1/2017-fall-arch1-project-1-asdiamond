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

/* recycle a bst, discarding all items it contains */
void BSTFree(BinarySearchTree *bst)
{
  //doCheck(lp);
  BSTMakeEmpty(bst->root);
  free(bst);
}

/* Delete all elements off of the bst */
void BSTMakeEmpty(Node *root)
{
	//my take is to process left, right then node...
	if(root == NULL) return;
	BSTMakeEmpty(root->leftChild);
	BSTMakeEmpty(root->rightChild);
	//process node after both left and right have been KILLED
	free(root->str);
	free(root);
	return;
}
  
/* inserts a node containing string s into the bst */
void BSTInsert(BinarySearchTree *bst, char *s)
{
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

Node* addNode(Node *root, Node *a){
	if(root == NULL){
		return a;
	}
	//compare to node and decide where to add it...
	int cmpval = strcmp(a->str, root->str);
	if(0 > cmpval) {//a < root
		root->leftChild = addNode(root->leftChild, a);
	}
	else {//a >= root
		root->rightChild = addNode(root->rightChild, a);
	}
	return root;
}

/* pprints the bst using inorder traversal... uses printInorder */
void pprintBST(BinarySearchTree *bst){
	printInorder(bst->root, 0);
}

/* helper, prints bst in order node by node */
void printInorder(Node *root, int space){
	if(root == NULL) return;
	space += 4;//2 is distance between levels...
	printInorder(root->rightChild, space);
	
	//print current node
	printf("\n");
	int i;
	for(i = 4; i < space; i++)//remember 2 is the distance between levels...
		printf(" ");
	printf("%s\n", root->str);
	printInorder(root->leftChild, space);
}

/* Removes a node containing *s from tree */
void removeBST(BinarySearchTree *bst, char *s){
	printf("called remove with %s\n", s);
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
