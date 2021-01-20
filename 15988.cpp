#include<iostream>

using namespace std;
typedef long long int lld;
lld ways[1010101] = {0};

lld findWays(int n){
    if(n<0) return 0;
    if(ways[n]==0) ways[n] = (findWays(n-1)+findWays(n-2)+findWays(n-3))%1000000009;

    return ways[n];
}
int main(){
    int T, N;
    ways[0] = 1;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        cout << findWays(N) << '\n';
    }
}