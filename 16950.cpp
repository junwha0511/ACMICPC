#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct Road{
    int weight, par, node;
};

struct compare{
    bool operator()(Road &a, Road &b){
        return a.weight < b.weight;
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int n, m, k, f, t, w;
    char c;

    vector<pair<int, int>> v[1010];
    priority_queue<Road, vector<Road>, compare> kPQ;
    vector<pair<int, int>> maxTree; 

    int visited[1010] = {0};

    cin >> n >> m >> k;
    
    for(int i=0; i<m; i++){
        cin >> c >> f >> t;
        if(c == 'R') w = 0; else w = 1;
        v[f].push_back({w, t});
        v[t].push_back({w, f});
    }
    
    
    int kWeights = 0;
    int numVisited = 1;
    int lastVisited = 1;
    bool isK = true;
    visited[1] = true;
    
    while(maxTree.size() < n-1){
        for(auto node : v[lastVisited]) if(!visited[node.second]) kPQ.push({node.first, lastVisited, node.second});
        while(visited[kPQ.top().node]) kPQ.pop();
        if(kWeights == k) while(kPQ.top().weight == 1&&!kPQ.empty()) kPQ.pop();
        if(kPQ.size() == 0){
            isK = false;
            break;
        }
        kWeights += kPQ.top().weight;   
        visited[kPQ.top().node] = true;
        maxTree.push_back({kPQ.top().par, kPQ.top().node});
        lastVisited = kPQ.top().node;
        kPQ.pop();
    }

    if(kWeights==k && isK) for(auto p : maxTree) cout << p.first << ' ' << p.second << '\n';
    else cout << 0;        
}  
