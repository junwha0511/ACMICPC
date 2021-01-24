#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int par[101010];
int sz[101010];

struct wood{
    int x1, x2, i;
};

vector<wood> v;

int find(int u){
    if(u==par[u]) return u;
    return par[u] = find(par[u]);
}

bool comp(wood a, wood b){
    return a.x1 < b.x1;
}

void unionWood(int u, int v){
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

    int N, Q, a, b, c;
    cin >> N >> Q;

    for(int i=1; i<=N; i++){
        cin >> a >> b >> c;
        v.push_back({a, b, i});
        par[i] = i;
        sz[i] = 1;
    }

    sort(v.begin(), v.end(), comp);

    wood last = v[0];

    for(auto w : v){
        if(w.x1 <= last.x2){
            unionWood(w.i, last.i);
            if(w.x2 > last.x2) last = w;
        }else{
            last = w;
        }
    }

    for(int i=0; i<Q; i++){
        cin >> a >> b;
        if(find(a)==find(b)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

}