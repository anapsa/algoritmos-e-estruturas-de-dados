#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

typedef struct Node {
  char data;
  struct Node *next;
} Node;
typedef struct List {
  Node *head;
  Node *tail;
  Node *curr;
  int length;
} List;
Node *createNode(char it, Node *nextval) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->next = nextval;
  n->data = it;
  return n;
}
Node *createNode2(Node *nextval) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->next = nextval;
  return n;
}
List *createList(void) {
  List *l = (List *)malloc(sizeof(List));
  l->curr = l->tail = l->head = createNode2(NULL);
  l->length = 0;
  return l;
}
void insert(List *l, char it) {
  l->curr->next = createNode(it, l->curr->next);
  if (l->tail == l->curr) {
    l->tail = l->tail->next;

  }
  //printf("%c\t", l->curr->data); 
  l->curr = l->curr->next;
  //printf("%c\n", l->curr->data);

  l->length++;
}
void next(List *l) {
  if (l->curr != l->head) {
    l->curr = l->curr->next;
  }
}

void printList(List* l) {
  
  Node *tmp = l->head; 
 
  while (tmp->next != NULL) {
        printf("%c", tmp->next->data);
        tmp = tmp->next; 
    }
  printf("\n"); 
  }
void freeList(List *l) {
  Node *tmp = l->head;
  Node *aux; 
  while(tmp != NULL) {
    aux = tmp;
    tmp = tmp->next; 
    free(aux); 
  }
  free(l); 
}
void movetoEnd (List *l) {
  l->curr = l->tail;
}
void movetoStart(List *l) {
  l->curr = l->head; 
}
int main () {
  char str[1000000];
  List* text, *temp; 
  text = createList();
  int comprimento; 
  
  while(scanf(" %s", str) != EOF) {
    comprimento = strlen(str); 
    if(comprimento > 0) {
    for(int i=0; i<comprimento; i++){
        if(str[i]== ']') {
          movetoEnd(text);  
        }
        else if (str[i] == '[') {
          movetoStart(text); 
        } else {
          insert(text, str[i]);
        }
      }
      printList(text);
    }
      freeList(text);
      text = createList(); 
  }
  freeList(text);
  return 0;
}
