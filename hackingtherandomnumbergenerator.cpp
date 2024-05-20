#include <stdio.h>
void swap(int* first, int* second)
{
    int t;
    t = *first;
    *first = *second;
    *second = t;
}

int HoarePartition(int arr[], int l, int r)
{
    int p, i, j;
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

void quickSort(int a[], int l, int r)
{
    int s; 
    if (l < r) {
        
        s = HoarePartition(a, l, r);
        quickSort(a, l, s - 1);
        quickSort(a, s + 1, r);
    }
}
int binarySearch (int arr[], int l, int r, int k) 
{
    int m;
    if (r >= l){
        m = ((l+r)/2); 
        if (k==arr[m]){
        return 1; 
        }
        else if (k < arr[m]) {
            return (binarySearch(arr, l, m-1, k)); 
        } else {
            binarySearch (arr, m+1, r, k); 
        }
    } else {
        return -1;
    }
    
}
int main() {

    int n, k;
    scanf("%d%d", &n, &k); 
    int num[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &num[i]); 
    }
    quickSort(num, 0, n-1); 
    int ans = 0, j; 
    for (int i=0; i<n; i++) {
        j = binarySearch(num, 0, n, num[i]-k);
        if (j == 1) {
            ans++; 
        }
    }
    printf("%d", ans); 
    return 0;
}
