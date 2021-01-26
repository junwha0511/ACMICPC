#include<iostream>
#include<cstdio>
#include<vector>
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int par[201010];
int parentStr[201010];

struct Query{
    int x, arg1, arg2;
};

stack<Query> query;
stack<string> ans;

int find(int u){
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N, Q, a, x, bc, d;

    cin >> N >> Q;
    
    for(int i=1; i<=N; i++){
        par[i] = i;
    }

    for(int i=1; i<=N-1; i++){
        cin >> a;
        parentStr[i+1] = a;
    }

    for(int i=0; i<(N-1+Q); i++){
        cin >> x >> bc;
        if(x == 0){
            query.push({x, bc, -1});
        }else{
            cin >> d;
            query.push({x, bc, d});
        }
    }   

    while(!query.empty()){
        Query q = query.top();
        if(q.x == 0){
            par[q.arg1] = parentStr[q.arg1];
        }else{
            if(find(q.arg1) == find(q.arg2)){
                ans.push("YES");
            }else{
                ans.push("NO");
            }
        }
        query.pop();
    }

    while(!ans.empty()){
        cout << ans.top() << '\n';
        ans.pop();
    }
}