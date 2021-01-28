#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long lld;

vector<lld> v;
lld M, N, a, maxLength=0;

void binarySearch(lld low, lld high){
    if(low > high) return;
    lld mid = (low+high)/2, sumFregment = 0;
    
    for(int i=0; i<N; i++){
        sumFregment += v[i]/mid;
        if(sumFregment >= M) break;
    }

    if(sumFregment >= M){
        maxLength = mid;
        binarySearch(mid+1, high);
    }else{
        binarySearch(low, mid-1);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> M >> N;

    for(int i=0; i<N; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    binarySearch(1, 1e+9);

    cout << maxLength;
}