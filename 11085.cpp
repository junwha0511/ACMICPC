#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

struct Road{int width, n1, n2;};
struct compare{
    bool operator()(Road &a, Road &b){
        return a.width < b.width;
    }
};

int par[1001], sz[1001];
priority_queue<Road, vector<Road>, compare> pq;

int find(int u){
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}

void unionRoad(int u, int v){
    int x = find(u);
    int y = find(v);

    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    par[x] = y;
    sz[y] += sz[x];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int p, w, c, v;
    int arg1, arg2, arg3;

    cin >> p >> w >> c >> v;
    for(int i=0; i<p; i++){
        par[i] = i;
        sz[i] = 1;
    }
    
    for(int i=0; i<w; i++){
        cin >> arg1 >> arg2 >> arg3;
        pq.push({arg3, arg1, arg2});
    }
    
    int lastWidth = 0;
    while(find(c) != find(v)){
        lastWidth = pq.top().width;
        unionRoad(pq.top().n1, pq.top().n2);    
        pq.pop();
    }

    cout << lastWidth;
}