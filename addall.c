#include <stdio.h>
#include <stdlib.h>
 

void HeapBottomUp(int* H, int n) {
    int i, k, j, v, heap;
    for (i = n/2; i >= 1; i--) {
        k = i;
        v = H[k];
        heap = 0;
        while (!heap && 2*k <= n) {
            j = 2*k;
            if (j < n) {
                if (H[j] > H[j+1]) {
                    j++;
                }
            }
            if (v <= H[j]) {
                heap = 1;
            } else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}
int main(void) {
  int testes, size, aux, swap, sum, result = 0;
  int* array = NULL;
    scanf("%d", &size);
    while(size !=0) { 
    array = (int *)realloc(array, sizeof(int) * (size + 1)); 
    for(int j=1; j<=size; j++) {
      scanf("%d", &array[j]); 
    }
    HeapBottomUp(array, size); 
    while(size != 1) {
      aux = array[1]; 
      swap = array[1];
      array[1] = array[size]; 
      array[size] = swap; 
      size--;
      array = (int *)realloc(array, sizeof(int) * (size + 1)); 
      HeapBottomUp(array, size); 
      sum = aux + array[1]; 
      result+=sum; 
      array[1] = sum;
      HeapBottomUp(array, size);
    } 
    printf("%d\n", result);
    result = 0; 
    scanf("%d", &size); 

}
  free(array); 
  return 0;
}
