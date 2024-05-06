#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;
typedef struct Stack {
  int size;
  Node *top;
} Stack;
Node *createNode(int it, Node *nextval) {
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
Stack *createStack(void) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->top = NULL;
  s->size = 0;
  return s;
}
void push(Stack *s, int it) {
  s->top = createNode(it, s->top);
  s->size++;
}
int pop(Stack *s) {
  if (s->top == NULL) {
    return -1;
  }
  int it = s->top->data;
  s->top = s->top->next;
  s->size--;
  return it;
}
int empty(Stack *s) { return (s->size == 0); }
int main() {
  int n, curr = 1, index = 0;
  Stack *station = createStack();
  scanf("%d", &n);
  int flag = 0;
  while (n>0) {
    int perm[n];
    while (flag == 0) {
      for (int i = 0; i < n; i++) {
        scanf("%d", &perm[i]);
        if (perm[0] == 0) {
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        break;
      }
      int k = 0;
      for (int j = 0; j < n; j++) {
        //isso aqui nao da runtime error
        push(station, j + 1);
        while (station->top->data == perm[k] && k < n) {
          //isso aqui também não dá runtime error
          pop(station);
          k++;
          if (station->size == 0) {
            break;
          }
        }
      }

      if (station->size == 0) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
      station = createStack();
    }
    printf("\n");
    flag = 0;
    scanf("%d", &n);
    if(n == 0){
      break;
    }
  }
  return 0;
}
