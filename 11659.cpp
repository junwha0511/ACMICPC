#include<iostream>
#include<cstdio>

using namespace std;

int prefix[101010] = {0};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N, M, i, j, a;
    cin >> N >> M;
    
    for(i=1; i<=N; i++){
        cin >> a;
        prefix[i] = prefix[i-1] + a;
    }
    
    for(int k=0; k<M; k++){
        cin >> i >> j;
        cout << prefix[j] - prefix[i-1] << '\n';
    }


}