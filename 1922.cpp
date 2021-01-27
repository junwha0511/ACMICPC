#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

vector<pair<int, int>> v[1010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
int visited[1010] = {0};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N, M, a, b, c;
    cin >> N >> M;

    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }   

    int sumWeights = 0;
    int numVisited = 1;
    int lastVisited = 1;
    visited[1] = true;
    
    while(numVisited < N){
        for(auto node : v[lastVisited]) if(!visited[node.second]) pq.push(node);
        while(visited[pq.top().second]) pq.pop();
        sumWeights += pq.top().first;   
        visited[pq.top().second] = true;
        lastVisited = pq.top().second;
        pq.pop();
        numVisited++;
        
    }

    cout << sumWeights;
}  