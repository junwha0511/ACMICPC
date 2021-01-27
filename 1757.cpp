#include<iostream>
#include<vector>

using namespace std;

int dp[10001][501][2];
vector<int> time;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();
    
    int N, M, t;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<=M; j++){
            dp[i][j] = -1;
        }
    }

    for(int i=0; i<N; i++){
        cin >> t;
        time.push_back(t);
    }

    

}