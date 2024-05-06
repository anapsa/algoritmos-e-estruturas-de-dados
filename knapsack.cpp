#include <bits/stdc++.h>

using namespace std;

int F[2001][2001];
int knapsack(int N, int S, int w[], int v[]) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= S; j++) {
            if (w[i] <= j) {
                F[i][j] = max(F[i-1][j], v[i] + F[i-1][j-w[i]]);
            } else {
                F[i][j] = F[i-1][j];
            }
        }
    }
    return F[N][S];
}

int main() {
    int S, N;
    cin >> S >> N;
    int size[N+1], value[N+1];
    
    for (int i = 1; i <= N; i++) {
        cin >> size[i] >> value[i];
    }
    
    cout << knapsack(N, S, size, value) <<endl;

    return 0;
}
