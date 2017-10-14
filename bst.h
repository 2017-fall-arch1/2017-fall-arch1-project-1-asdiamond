#ifndef llist_included		/* prevent multiple inclusion */
#define llist_included

/* a BST node with item */
typedef struct node {
  struct node *leftChild; 
  struct node *rightChild; 
  char *str;
} Node;

/* a list of LLItems */
typedef struct {
	Node *root;
} BinarySearchTree;

/* Check to see if this is necessary */
extern int llDoCheck;		/* set true for paranoid consistency checking */
//debug flag

/* create a new list */
BinarySearchTree *BSTAlloc();

/* free memory associated with a BST, discarding all items it contains */
void BSTFree(BinarySearchTree *bst);

/* Delete all elements off list */
void BSTMakeEmpty(BinarySearchTree *bst);

/* Insert a copy of str into bst */
void BSTInsert(BinarySearchTree *bst, char *s);

/* pprints bst */
void pprintBST(BinarySearchTree *bst);

/* helper to print bst inorder */
void printInorder(Node *root, int space);

/* helper to add node to bst */
Node* addNode(Node *root, Node *a);

//TODO reimplement this for bst...
/* check llist consistency, always returns zero */
//int llCheck(LList *lp);

#endif	/* included */
