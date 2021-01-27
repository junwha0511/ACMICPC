#include<iostream>
#include<cstdio>

using namespace std;

long dp[1516][3] = {0};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N;
    cin >> N;

    dp[1][2] = 1;
    for(int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][2] = dp[i-1][0] + dp[i-1][1];
        dp[i][0] %= 1000000007;
        dp[i][1] %= 1000000007;
        dp[i][2] %= 1000000007;
    }

    cout << dp[N][0];
}