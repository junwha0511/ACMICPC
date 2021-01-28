#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long lld;

lld N, M, a, mid, num, minTime;

vector<lld> v;

void binarySearch(lld low, lld high){
    if(low > high) return;

    mid = (low+high)/2;
    num = 0;
    
    for(lld i=0; i<N; i++){
        num += mid/v[i]; 
        if(num >= M) break;
    }

    if(num >= M){
        minTime = mid;
        binarySearch(low, mid-1);
    }else{
        binarySearch(mid+1, high);
    }

    
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> N >> M;
    for(lld i=0; i<N; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    binarySearch(1, 1e18);
    cout << minTime;
}