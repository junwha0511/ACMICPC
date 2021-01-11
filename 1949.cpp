#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

#define MAX_N 10001

using namespace std;

int town[MAX_N];
vector<int> edge[MAX_N];
int DP[MAX_N][2];
int N, s, t;

void checkTown(int parent, int cur){
    int curIsBest = 0;
    int curIsNotBest = 0;

    for(int child : edge[cur]){
        if(child == parent) continue;
        checkTown(cur, child);

        curIsBest += DP[child][0];
        curIsNotBest += max(DP[child][0], DP[child][1]);
    }

    DP[cur][0] = curIsNotBest;
    DP[cur][1] = curIsBest + town[cur];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> town[i];
    }
    for(int i=0; i<N-1; i++){
        cin >> s >> t;
        s--;
        t--;
        edge[s].push_back(t);
        edge[t].push_back(s);
    }

    checkTown(-1, 0);

    cout << max(DP[0][0], DP[0][1]);
}
