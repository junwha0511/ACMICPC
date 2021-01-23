#include<iostream>
#include<cstdio>

using namespace std;

int disjtSet[101010];

int find(int a){
    if(disjtSet[a]==a) return a;
    return disjtSet[a] = find(disjtSet[a]);
}

void unionSet(int u, int v){
    int x = find(u);
    int y = find(v);
    disjtSet[x] = y;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int G, P, g;
    cin >> G >> P;
    
    for(int i=0; i<=G; i++) disjtSet[i] = i;

    int cnt = 0;
    
    for(int i=0; i<P; i++){
        cin >> g;
        int f = find(g);
        if(f!=0){
            unionSet(f, f-1);
            cnt++;
        }else{
            break;
        }
    }    
    
    cout << cnt;
}