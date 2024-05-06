#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> tab, int n) {
    for(int i=0; i<n; i++) {
        for(int j= 0; j<tab[i].size(); j++){
            cout << tab[i][j];
        }
        cout << endl; 
    }
}

vector<vector<int>> backup; 

void solution(vector<vector<int>> &tab, int n, int i, int j, int &count, int &ans) {
    if(ans < count) {
            ans = count; 
    }
    if(i < 0 || i >= n || j < 0 || j >= tab[i].size() ) {
        return;
    }
    if(tab[i][j] == 0 || tab[i][j] == 2) return; 
   
    if(tab[i][j] == 1) {
        tab[i][j] = 2;
        count++;
        solution(tab, n, i+1, j+2, count, ans);
        solution(tab, n, i-1, j+2, count, ans);
        solution(tab, n, i+1, j-2, count, ans);
        solution(tab, n, i-1, j-2, count, ans);
        solution(tab, n, i+2, j+1, count, ans);
        solution(tab, n, i-2, j+1, count, ans);
        solution(tab, n, i+2, j-1, count, ans);
        solution(tab, n, i-2, j-1, count, ans);
        tab[i][j] = 1;
        count--;
    }
   
}

int main() {
    pair<int,int> read;
    int n, numsquares = 0, cases = 1;
    cin >> n;
    while (n > 0) {
        vector<vector<int>> tab(10, vector<int>(10, 0));
        for(int i=0; i<n; i++) {
            cin >> read.first >> read.second;
            numsquares += read.second;
            vector<int> row;
            for(int j=0; j<read.first+read.second; j++){
                if(j < read.first) {
                    row.push_back(0);
                } else {
                    row.push_back(1);
                }
            }
            tab[i]= row;
        }
        int count = 0, ans = 0;
       

        solution(tab, n, 0, 0, count, ans);
        if(numsquares -  ans != 1) {
        cout << "Case " << cases << ", " << numsquares - ans << " squares can not be reached." << endl;
        
        } else 
         cout << "Case " << cases << ", " << numsquares - ans << " square can not be reached." << endl;
        
        cases++;
        numsquares = 0;
        cin >> n;
    }
    return 0;
}
