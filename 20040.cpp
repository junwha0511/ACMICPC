#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int parent[501010];
int sz[501010];
int n, m;

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v){
    int x = find(u);
    int y = find(v);
    if(x == y) return false;
    if(sz[x] > sz[y]) swap(x, y);
    parent[x] = y;
    sz[y] += sz[x];
    return true;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
        sz[i] = 1;
    }

    int u, v;
    for(int i=1; i<=m; i++){
        cin >> u >> v;
        if(!merge(u, v)){
            cout << i;
            return 0;
        }
    }
    
    cout << 0;

}