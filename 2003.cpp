#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> v;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N, M, c;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> c;
        v.push_back(c);
    }

    int a=0, b=0, ways=0, sum = 0;
    while(true){
        if(sum >= M) sum -= v[a++];
        else if(b == N) break;
        else sum += v[b++];
        if(sum == M) ways++;
    }
    
    cout << ways;

}