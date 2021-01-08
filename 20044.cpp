#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, a;
    cin >> N;

    vector<int> v;

    for(int i=0; i<2*N; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int sm = v[0]+v[2*N-1];
    for(int i=1; i<N; i++){
        sm = min(v[i]+v[2*N-1-i], sm);
    }

    cout << sm;
}
