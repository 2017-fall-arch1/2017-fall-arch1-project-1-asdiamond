#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "bst.h"		
#include "bstdemo.h"//for the gets_n() function
#define COUNT 10//for the pprint function

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

Node* addNode(Node *root, Node *a)
{
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
	space += COUNT;
	printInorder(root->rightChild, space);
	printf("\n");
	int i = COUNT;
	for(; i < space; i++)
		printf(" ");
	printf("%s\n", root->str);
	printInorder(root->leftChild, space);
}

/* Wrapper method to remove a node containing *s from tree */
void removeNode(BinarySearchTree *bst, char *s){
	bst->root = removeRec(bst->root, s);
	printf("Removed %s\n", s);
}

/* remove method */
Node* removeRec(Node *root, char *s){
	if (root == NULL) return root;
	int cmpval = strcmp(s, root->str);
	if(0 > cmpval)//s < root
		root->leftChild = removeRec(root->leftChild, s);
	else if(0 < cmpval)//s > root
		root->rightChild = removeRec(root->rightChild, s);
	//otherwise they are equal, this is the node youre looking for
	else {
		if(root->leftChild == NULL) return root->rightChild;
		else if(root->rightChild == NULL) return root->leftChild;
	
		//otherwise node has 2 children :(
		//promote min from right subtree
		root->str = min(root->rightChild);

		root->rightChild = removeRec(root->rightChild, s);
	}
	return root;
	
}

/* finds min in tree */
char* min(Node *root){
	char *minval = root->str;	
	while(root->leftChild != NULL){
		minval = root->leftChild->str;
		root = root->leftChild;
	}
	return minval;
}

/* uses preorder traversal serialize a bst to a file */
void serializeBST(BinarySearchTree *bst, FILE *file){
	printf("Serializing to file...\n");
	preorderSerialization(bst->root, file);
}

void preorderSerialization(Node *root, FILE *file){
	if(root == NULL) return;
	fprintf(file, "%s\n" , root->str);//node, left, right
	preorderSerialization(root->leftChild, file);
	preorderSerialization(root->rightChild, file);
	
}

void deserializeBST(BinarySearchTree *bst, FILE *file){
	printf("Deserializing bst from file\n");
	while(gets_n(buf, 100, file)){
		BSTInsert(bst, buf);
	}
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
