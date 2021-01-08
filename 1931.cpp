#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, a, b;
    vector<pair<int, int>> v;

    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> a >> b;
        v.push_back({b,a});
    }
    
    sort(v.begin(), v.end());

    a = 0, b = 0;

    for(int i=0; i<N; i++){
        if(v[i].second < a){
            continue;
        }
        a = v[i].first;
        b++;
    }
    cout << b;
}