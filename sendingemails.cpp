#include <bits/stdc++.h>
#define max 10000000 //infinito
#define ii pair <int, int>
using namespace std;


int main() { 
  int N; 
  cin >> N; 
  for(int j = 1; j <= N; j++){
      int n, m, S, T, v, u, w;
      cin >> n >> m >> S >> T;
      vector<vector<pair<int, int>>> graph(n); //declara o grafo
      for(int i=0; i<m; i++) {
        int v, u, w; 
        cin >> v >> u >> w; 
        graph[v].push_back({u, w}); 
        graph[u].push_back({v, w}); 
      }
      
      priority_queue<ii, vector<ii>, greater<ii>> dj;
      
      vector <int>distance(n, max); 
      
      distance[S] = 0; //a distancia para ele próprio é 0
      dj.push ( {0,S}); 

      int cost, s;
      
      while(!dj.empty()) {
        v = dj.top().second; 
        s = dj.top().first;
        dj.pop(); 
        if(s != distance[v]) continue; //boa pratica
        for(auto i : graph[v]) {
          u = i.first; 
          cost = i.second;
          if(distance[u] > distance[v]+cost) {
            distance[u] = distance[v] + cost;
            dj.push( {distance[u], u});
          }
        }
      }
      
      cout << "Case #" << j << ": ";
        if (distance[T] == max) {
            cout << "unreachable\n";
        } else {
            cout << distance[T] << "\n";
        }
  }
  return 0;
}
