#include <bits/stdc++.h> 
#define INF 10000000000

using namespace std;
int frog(vector<int> &minimum, long long int stones, int steps, int height[]) {
    minimum[0] = 0; 
    for(long long int i=0; i<stones; i++) {
        for(long long int j=i+1; j<=i+steps; j++) {
            if(j<stones)
                minimum[j] = min(minimum[j], minimum[i] + abs(height[i]-height[j])); 
        }
    }
    return minimum[stones - 1]; 
    
}
int main()
{
    long long int stones;
    int steps; 
    cin >> stones >> steps;
    int height[stones]; 
    for(long long int i=0; i<stones; i++) {
        cin >> height[i];
    }
    vector<int> minimum(stones, INF); 
    int answer = frog(minimum, stones, steps, height); 
    cout << answer; 
     
    return 0;
}
