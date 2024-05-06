#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int h(char k[]) {
  int s = strlen(k);
  int sum = 0;
  for (int i = 0; i < s; i++) {
    sum += 19 * (i + 1) * k[i];
  }
  return sum % 101;
}
int find(char **table, char value[]) {
  int index = h(value), j;

  int tmp = index; 
  if(table[index] != NULL) {
    if(strcmp(table[index], value) == 0) {
      return 1; 
    }
  }

    for(j = 1; j <= 19; j++) {
        index = (tmp + j * j + 23 * j) % 101; 
        if(table[index] != NULL) {
          if(strcmp(table[index], value) == 0) {
            return 1;
          }
        }
      }
    
      
  
  return 0; 
}
void insert(char value[], char **table, int *num) {
  int index = h(value);
  int j, tmp = index;
  int Find = find(table, value); 

  if(Find == 1) {
    return; 
  } 
  if(table[index] == NULL) {
    (*num)++; 
  }
  if (table[index] != NULL) {
    for (j = 1; j <= 19; j++) {
      //printf("teve colisao\n");
      index = (tmp + j * j + 23 * j) % 101;
      if (table[index] == NULL) {
        (*num)++;
        break; //saio do laço se for null pq esse é o primeiro valor do index livre para aquela chave
      } else if (table[index] != NULL) {
          if (j == 19) { 
          return; //retorna caso não há posições livres 
        }
      }
    }
  }

  //se nenhuma das condições acima forem verdadeiras, não existe colisão no valor retornado por h()
  //se houve colisão, o valor do index foi atualizado
  table[index] = (char *)malloc(strlen(value) + 1); 
  strcpy(table[index], value);
 
  return; 
  
}

void delete(char key[], char **table, int *num){
  int index = h(key);
  int tmp = index;
  int Find = find(table, key); 
  if(Find == 0) {
    return; 
  }
  if (table[index] != NULL) 
  {
    if(strcmp(table[index], key) == 0) {
      table[index] = NULL;
      (*num)--;
      return;
    }
  }
  for (int j = 1; j <= 19; j++)
        {
        tmp = (index + j * j + 23 * j) % 101;
        if (table[tmp] != NULL) {
          if (strcmp(table[tmp], key) == 0) 
          {
            
            table[tmp] = NULL;
            (*num)--;
            return;
          
          } else if (j == 19)
          {
            return;
          }
        } 
      }
  //mesmo que não haja elementos,é necessário verificar se ele está em alguma das prováveis posições 

  
  
  return;
}
int main(void) {
  char *HashTable[101] = {NULL};
  int numcase, numop, i, j;
  char option[4], name[41];

  int *num = (int *)calloc(1, sizeof(int));
  scanf("%d", &numcase);
  for (i = 0; i < numcase; i++)
    {
    scanf("%d", &numop);
    for (j = 0; j < numop; j++)
      {
      scanf(" %3[^:]:%s", option, name);
      if (strcmp(option, "ADD") == 0) 
      {
        insert(name, HashTable, num);
      } else if (strcmp(option, "DEL") == 0)
      {
        delete (name, HashTable, num);
      }
    }
    printf("%d\n", (*num));
    (*num) = 0;
    for (int i = 0; i < 101; i++) 
    {
      if(HashTable[i] != NULL) {
        printf("%d:%s\n", i, HashTable[i]); 
        HashTable[i] = NULL;
      }
      
    }
  }
  free(num);
  return 0;
}
