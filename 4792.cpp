#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int n, m, k, f, t, w;
    char c;

    while(true){
        vector<pair<int, int>> v[1010];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minPQ;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int,int>>> maxPQ;

        int visited[1010] = {0};

        cin >> n >> m >> k;
        if(!(n || m || k)) break;

        for(int i=0; i<m; i++){
            cin >> c >> f >> t;
            if(c == 'R') w = 0; else w = 1;
            v[f].push_back({w, t});
            v[t].push_back({w, f});
        }
        
        int minWeights = 0;
        int maxWeights = 0;
        int numVisited = 1;
        int lastVisited = 1;
        visited[1] = true;
        
        while(numVisited < n){
            for(auto node : v[lastVisited]) if(!visited[node.second]) minPQ.push(node);
            while(visited[minPQ.top().second]) minPQ.pop();
            minWeights += minPQ.top().first;   
            visited[minPQ.top().second] = true;
            lastVisited = minPQ.top().second;
            minPQ.pop();
            numVisited++;
        }

        numVisited = 1;
        lastVisited = 1;
        for(int i=2; i<=n; i++) visited[i] = false;

        while(numVisited < n){
            for(auto node : v[lastVisited]) if(!visited[node.second]) maxPQ.push(node);
            while(visited[maxPQ.top().second]) maxPQ.pop();
            maxWeights += maxPQ.top().first;   
            visited[maxPQ.top().second] = true;
            lastVisited = maxPQ.top().second;
            maxPQ.pop();
            numVisited++;
        }

        if(k <= maxWeights && k >= minWeights) cout << 1 << '\n';
        else cout << 0 << '\n';
        

    }
}  
