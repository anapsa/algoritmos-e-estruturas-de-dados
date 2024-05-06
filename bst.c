#include <stdio.h>
#include <stdlib.h>
typedef struct bstNode {
  long long int data;
  struct bstNode *right;
  struct bstNode *left; 
} bstNode; 
typedef struct BST {
  bstNode* root; 
  int nodecount; 
} BST;
bstNode* createbstNode(long long int value){
  bstNode* aux; 
  aux = (bstNode *) malloc(sizeof(bstNode)); 
  aux->data = value; 
  aux->left = aux->right = NULL; 
  return aux; 
}
BST* createBST (void) {
  BST* aux;
  aux = (BST *)malloc(sizeof(BST)); 
  aux->root=NULL; 
  aux->nodecount = 0;
  return aux; 
}
bstNode* inserthelp (bstNode* idk, long long int value) {
  if(idk == NULL) {
    return(createbstNode(value)); 
  } else if (value > idk->data) {
    idk->right = inserthelp (idk->right, value); 
  } else {
    idk->left = inserthelp (idk->left, value); 
  }
  return idk; 
}
void inorder(bstNode* nome) {
  
  if (nome != NULL) 
  {
    inorder(nome->left); 
    printf("%lld ", nome->data); 
    inorder(nome->right); 
  }

}
void preorder(bstNode* nome) {
  
  if(nome != NULL) 
  {
    printf("%lld ", nome->data); 
    preorder(nome->left); 
    preorder(nome->right); 
  }

}

void posorder(bstNode *nome){
  
  if(nome != NULL) 
  {
    posorder(nome->left);
    posorder(nome->right);
    printf("%lld ", nome->data); 
  }
 
}
void insert(BST *bst, long long int value) {
  bst->root = inserthelp(bst->root, value); 
  bst->nodecount++; 
}
int main () {
  long long int n; 
  scanf("%lld", &n);
  long long int i;
  long long int p; 
  BST* bst = createBST(); 
  for(i=0; i<n; i++) {
    scanf("%lld", &p);
    insert(bst, p); 
  }
  printf("Pre order : ");
  preorder(bst->root);
  printf("\n");
  printf("In order  : ");
  inorder(bst->root);
  printf("\n"); 
  printf("Post order: ");
  posorder(bst->root);
  
  return 0; 
}
