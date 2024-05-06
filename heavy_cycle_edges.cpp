#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

bool cmp(const Edge &e1, const Edge &e2) {
    return e1.wt < e2.wt;
}

struct DS {
    vector<int> R;
    DS(int n) {
        R.resize(n+1);
        for (int i = 1; i <= n; i++) {
            R[i] = i;
        }
    }
};

int find(DS &ds, int curr) {
    if (ds.R[curr] != curr) {
        ds.R[curr] = find(ds, ds.R[curr]);
    }
    return ds.R[curr];
}

void Union(DS& ds, int a, int b) {
    int root1 = find(ds, a);
    int root2 = find(ds, b);
    ds.R[root2] = root1;
}

void Kruskal(vector<Edge>& edges, int n,  vector<int>&cycles, vector<Edge>& mst) {
    sort(edges.begin(), edges.end(), cmp);
    DS ds(n);
    int cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].wt;
        if (find(ds, u) != find(ds, v)) {
            Union(ds, u, v);
            cnt++;
            mst.push_back({u, v, wt});
        } else {
            cycles.push_back(wt); 
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        int u, v, w;
        vector<Edge> edges;
        vector<Edge> mst;
        vector<int> cycles;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        Kruskal(edges, n, cycles, mst);
        sort(cycles.begin(), cycles.end());
        if (cycles.size() == 0) {
            cout << "forest";
        } else {
            for (int i = 0; i < cycles.size(); i++) {
                cout << cycles[i];
                if(i!=cycles.size()-1) cout << " "; 
               
            }
           
        }
        cout << endl;
        cin >> n >> m;
    }
    return 0;
}
