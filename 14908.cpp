#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(pair<double, int> a, pair<double, int> b){
    if(a.first==b.first) return a.second < b.second;
    return a.first > b.first;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    vector<pair<double, int>> v;

    int N, T, S;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T >> S;
        if(T==0||S==0) v.push_back({0, i+1});
        else v.push_back({(double)S/T, i+1});
    }
    
    sort(v.begin(), v.end(), comp);

    for(pair<double, int> p: v){
        cout << p.second << ' ';
    }
    
    
}