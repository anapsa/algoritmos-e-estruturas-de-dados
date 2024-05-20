#include <stdio.h>
#include <stdlib.h>
typedef struct bstNode {
  long long int data;
  struct bstNode *right;
  struct bstNode *left; 
} bstNode; 

bstNode* createbstNode(long long int value){
  bstNode* aux; 
  aux = (bstNode *) malloc(sizeof(bstNode)); 
  aux->data = value; 
  aux->left = aux->right = NULL; 
  return aux; 
}
bstNode* inserthelp (bstNode* idk, long long int value) {
  if(idk == NULL) {
    return(createbstNode(value)); 
  } else if (idk->data > value) {
    idk->left = inserthelp (idk->left, value); 
  } else {
    idk->right = inserthelp (idk->right, value); 
  }
  return idk; 
}
void inorder(bstNode* nome) {
  
  if (nome != NULL) 
  {
    inorder(nome->left); 
    printf(" %lld", nome->data); 
    inorder(nome->right); 
  }

}
void preorder(bstNode* nome) {
  
  if(nome != NULL) 
  {
    printf(" %lld", nome->data); 
    preorder(nome->left); 
    preorder(nome->right); 
  }

}

void posorder(bstNode *nome){
  
  if(nome != NULL) 
  {
    posorder(nome->left);
    posorder(nome->right);
    printf(" %lld", nome->data); 
  }
 
}

int main () {
  long long int n; 
  scanf("%lld", &n);
  long long int i;
  long long int p; 
  bstNode* bst = NULL; 
  for(i=0; i<n; i++) {
    scanf("%lld", &p);
    bst = inserthelp(bst, p); 
  }
  printf("Pre order :");
  preorder(bst);
  printf("\n");
  printf("In order  :");
  inorder(bst);
  printf("\n"); 
  printf("Post order:");
  posorder(bst);
  
  return 0; 
}
