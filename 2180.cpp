#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(pair<int, int> i, pair<int, int> j){
    if(i.first==0) return false;
    if(j.first==0) return true;

    return j.first*i.second < i.first*j.second;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int n, a, b;
    vector<pair<int, int>> v;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), comp);

    int t=0;
    for(auto info : v){
        t += ((info.first*t)+info.second)%40000;
    }
    cout << t%40000;
}