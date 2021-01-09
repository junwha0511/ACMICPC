#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N, a;

    cin >> N;

    vector<int> v, dp(N, 1);
    for(int i=0; i<N; i++){
        cin >> a;
        v.push_back(a);
    }
    
    
    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(v[j] < v[i]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}