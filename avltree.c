#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bstNode {
  int data;
  struct bstNode *right;
  struct bstNode *left;
  int height;
  int nodes;

} bstNode;

bstNode *createbstNode(int value) {
  bstNode *aux;
  aux = (bstNode *)malloc(sizeof(bstNode));
  aux->data = value;
  aux->left = aux->right = NULL;
  aux->height = 1;
  aux->nodes = 0;

  return aux;
}
int child(bstNode *bst) {
  if (bst == NULL) {
    return 0;
  }
  return bst->nodes;
}
void updateChild1 (bstNode *rt) {
  bstNode *aux;
  int old = 0, idk = 0; 
  if(rt->left != NULL) {
    if(rt->left->right != NULL) {
      old = child(rt->left->right) + 1;
    } 
  } 
  if(rt->right != NULL) {
    idk = child(rt->right) + 1; 
  }
  rt->nodes = idk + old; 
}
void updateChild2 (bstNode *rt){
  bstNode *aux; 
}
int max(int a, int b) { 
  return (a > b) ? a : b;
}
int h(bstNode *rt) {
  if (rt == NULL) {
    return 0;
  }
  return rt->height;
}
int getBalance(bstNode *rt) {
  if (rt == NULL) {
    return 0;
  }
  return h(rt->left) - h(rt->right);
}
bstNode *rightRotate(bstNode *rt) {
  int newNode = child(rt);
  int leftrightChild = 0, rightChild = 0;
  if(rt->left != NULL){
    if(rt->left->right != NULL) {
      leftrightChild = child(rt->left->right) + 1;
    }
  }
  if(rt->right != NULL) {
    rightChild = child(rt->right) + 1; 
  }
  bstNode *l = rt->left;
  bstNode *lr = l->right;
  l->right = rt;
  rt->left = lr;
  rt->height = max(h(rt->left), h(rt->right)) + 1;
  l->height = max(h(l->left), h(l->right)) + 1;
  
    rt->nodes = rightChild + leftrightChild;
    l->nodes = newNode; 

  return l;
}

bstNode *leftRotate(bstNode *rt) {  
  int newNode = child(rt); 
  
  int rightleftChild = 0; 
  if(rt->right != NULL) {
    if(rt->right->left != NULL) {
      rightleftChild = child(rt->right->left) + 1; 
      //printf("filho a direita: %d\n", rt->left);
      //printf("rightleftChild: %d\n", rightleftChild); 
    } 
  } 
  int leftChild = 0;
  if(rt->left != NULL) {
    leftChild = child(rt->left) + 1; 
    //printf("leftChild: %d\n", leftChild); 
  }
  bstNode *r = rt->right;
  bstNode *rl = r->left;
  r->left = rt;
  rt->right = rl;
  rt->height = max(h(rt->left), h(rt->right)) + 1;
  r->height = max(h(r->left), h(r->right)) + 1;
  //rt vai perder todos os seus filhos a direita mais va
  
  rt->nodes = leftChild + rightleftChild;
  //printf("no left: %d -- %d\n", rt->data, rt->nodes); 
  r->nodes = newNode; 
  //printf("no left %d -- %d\n", r->data, r->nodes);
 
  return r;
}
bstNode *inserthelp(bstNode *rt, int e) {
  
  if (rt == NULL) { 
    return createbstNode(e);
  }
  rt->nodes++;
  if (rt->data > e) {

    rt->left = inserthelp(rt->left, e);
   
  } else {

    rt->right = inserthelp(rt->right, e);
  }
  rt->height = 1 + max(h(rt->left), h(rt->right));

  int balance = getBalance(rt);

  if (balance < -1 && e >= rt->right->data) {
    //printf("left\n");
    return leftRotate(rt);
  } else if (balance > 1 && e < rt->left->data) {
    //printf("right\n");
    return rightRotate(rt);
  } else if (balance > 1 && e >= rt->left->data) {
    rt->left = leftRotate(rt->left);
    //printf("lr\n");
    return rightRotate(rt);
  } else if (balance < -1 && e < rt->right->data) {
    rt->right = rightRotate(rt->right);
    //printf("rl\n");
    return leftRotate(rt);
  }
  return rt;
}
int height(bstNode *rt) {
  if (rt == NULL) {
    return 0;
  }
  int left_height = h(rt->left);
  int right_height = h(rt->right);
  return 1 + max(left_height, right_height);
}

int findhelp(bstNode *rt, int key, int *index) {

  if (rt == NULL) {
    return -1;
  }
  if (rt->data > key) {
    return findhelp(rt->left, key, index);
  } else if (rt->data == key) {
    if(rt->left != NULL) {
      (*index) += rt->left->nodes + 2;
    } else {
      (*index)++;
    }
    return (*index);
  } else {
    if(rt->left != NULL) {
      (*index) += rt->left->nodes + 2;
     // printf("%d\n", rt->left->nodes);
     //   printf("dentro do if: %d\n", (*index));
      } 
     else (*index)++;
    
    //printf("fora do if: %d\n", (*index));
    return findhelp(rt->right, key, index);
  }
}

void inorder (bstNode *idk) {
    if(idk != NULL) {
        inorder(idk->left);
        printf("%d -- %d\n", idk->data, idk->nodes); 
        inorder(idk->right); 
        }
    }


int main() {
  int n;
  scanf("%d", &n);
  int num;
  int option;
  int aux;
  bstNode *bst = NULL;
  int *index = (int *)malloc(sizeof(int));
  (*index) = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &option);
    scanf("%d", &num);
    if (option == 1) {
      bst = inserthelp(bst, num);
      
    } else if (option == 2) {
      aux = findhelp(bst, num, index);
    
      if (aux != -1) {
        printf("%d\n", aux);
      } else {
        printf("Data tidak ada\n");
      }
      (*index) = 0;
    }
  }
  free(index);
  return 0;
}
