#include <stdio.h>
 
void swap(long long int* first, long long int* second)
{
    long long int t;
    t = *first;
    *first = *second;
    *second = t;
}
long long int HoarePartition(long long int arr[], long long int l, long long int r)
{
    long long int p, i, j;
    p = arr[l]; 
    i = l; 
    j = r + 1;          
 
    while (i < j) {
        do {
            i++;
        }
        while (arr[i] < p && i < r);
        do {
            j--;
        }
        while (arr[j] > p); 
        swap(&arr[i], &arr[j]); 
    
    }
    swap(&arr[i], &arr[j]);
    swap(&arr[l], &arr[j]); 
    return j;
}
void quickSort(long long int a[], long long int l, long long int r)
{
    long long int s; 
    if (l < r) {
        
        s = HoarePartition(a, l, r);
        quickSort(a, l, s - 1);
        quickSort(a, s + 1, r);
    }
}
int main (){
    long long int numchoc; 
    scanf("%lld", &numchoc); 
    long long int cost[numchoc]; 
    long long int totalPrice=0; 
    long long int i, j;
    for (i=0; i<numchoc; i++) {
        scanf("%lld", &cost[i]); 
        totalPrice+=cost[i]; 
    }
    quickSort(cost, 0, numchoc-1); 
    long long int numcoupons;
    scanf("%lld", &numcoupons); 
    long long int coupons[numcoupons];
    long long int price[numcoupons];
    for (i=0; i<numcoupons; i++){
        scanf("%lld", &coupons[i]);
        price[i] = totalPrice;
        price[i] -= cost[numchoc-coupons[i]];
        printf("%lld\n", price[i]);
    } 
    
    return 0; 
}
