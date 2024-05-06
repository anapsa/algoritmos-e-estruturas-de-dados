#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;


vector<int> adj[MAXN];
vector<int> ans; 
int dp[MAXN];

int Kahns(int n){
    priority_queue<int, vector<int>, greater<int>> pq; 
    for(int i=1; i<=n; i++){
        if(dp[i] == 0) 
            pq.push(i);
    }
    while(!pq.empty()) {
        int curr = pq.top();
        ans.push_back(curr); 
        pq.pop();
        for(int child : adj[curr]) {
            dp[child]--; 
            if(dp[child] == 0) pq.push(child); 
        }
    }
    if(ans.size() == n) {
        return 1; 
    } else return 0;  
}

int main() {
    int n, m, flag = 0;
    cin >> n >> m;
  
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        dp[b]++;
    }
  
    if(Kahns(n) == 0) {
        cout << "Sandro fails." << "\n"; 
    } else {
         for(int i=0; i<n; i++){
        cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
