#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

bool binarySort(int start, int end, int target){
    if(start > end) return false;

    int mid = (start+end)/2;
    if(target == v[mid]) return true;
    if(target > v[mid]) return binarySort(mid+1, end, target);
    else return binarySort(start, mid-1, target);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N, M, a;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> a;
        cout << (binarySort(0, N-1, a)?1:0) << '\n';
    }
}