#include <bits/stdc++.h>
#define INF 1000000
#define ii pair<int, int>
using namespace std;

typedef struct aux {
    int distancia;
    string name;
} aux;

bool comp(const aux& a, const aux& b) {
    if (a.distancia == b.distancia) {
        return a.name < b.name;
    }
    return a.distancia < b.distancia;
}


map<string, int> bfs(int nv, string origem, map<string, vector<string>> g, vector<aux>& arr) {
    map<string, int> dist;
    queue<string> q;

    q.push(origem);
    dist[origem] = 0;
    aux tmp;
    tmp.name = origem; 
    tmp.distancia = 0;
    arr.push_back(tmp); 
    while (!q.empty()) {
        string current = q.front();
        
        q.pop();

        for (string to : g[current]) {
            if (!dist.count(to)) { // verifica se to não foi visitado ainda
                dist[to] = dist[current] + 1;
                tmp.name = to;
                tmp.distancia = dist[to];
                arr.push_back(tmp);

                q.push(to);
            }
        }
    }

    for (auto it = g.begin(); it != g.end(); ++it) {
        if (dist.find(it->first) == dist.end()) {
            tmp.name = it->first;
            tmp.distancia = 100000; 
            arr.push_back(tmp);
        }
    }

   

    return dist;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int teams;
        cin >> teams;
        map<string, vector<string>> g;
        string name1, name2, name3;
        for (int j = 0; j < teams; j++) {
            cin >> name1 >> name2 >> name3;
            g[name1].push_back(name2);
            g[name1].push_back(name3);
            g[name2].push_back(name1);
            g[name2].push_back(name3);
            g[name3].push_back(name1);
            g[name3].push_back(name2);
        }
        cout << g.size() << endl;
        vector<aux> sorting;
        map<string, int> dist = bfs(g.size(), "Ahmad", g, sorting);
        sort(sorting.begin(), sorting.end(), comp); 
        
        for(int k=0; k<g.size(); k++){
            if(sorting[k].distancia != 100000)
            cout << sorting[k].name << " " << sorting[k].distancia << endl;
            else cout << sorting[k].name << " undefined" << endl;
        
        }

    }
    return 0;
}
