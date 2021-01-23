#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
using namespace std;

vector<ull> wants;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N;
    ull M, w;
    cin >> M >> N;

    ull sumWants = 0;
    for(int i=0; i<N; i++){
        cin >> w; 
        sumWants += w;
        wants.push_back(w);
    }

    sort(wants.begin(), wants.end());

    ull sumR = 0;
    ull k = sumWants - M;
    for(int i=0; i<N; i++){
        ull nonAlloc = min(wants[i], k/(N-i));
        sumR += nonAlloc*nonAlloc;
        k -= nonAlloc;
    }    
    
    cout << sumR;
}