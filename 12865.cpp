//Knapsack problem(DP)
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int dp[100][100001];

int findValue(int i, int cap){
    if(cap<0) return -10000001;
    if(i<0) return 0;
    
    return dp[i][cap];
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio();
    
    vector<pair<int, int>> v;

    int N, K, weight, val;
    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> weight >> val;
        v.push_back({weight, val});
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<=K; j++){
            dp[i][j] = max(findValue(i-1, j), findValue(i-1, j-v[i].first)+v[i].second);
        }
    }

    cout << dp[N-1][K];
}
