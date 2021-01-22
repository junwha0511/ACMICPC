#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include <queue>

#define MAXN 501010
using namespace std;

long long int W;
int N, S[MAXN], Q[MAXN];
priority_queue<int> pQ;
vector<pair<double, int>> v;
vector<pair<int, int>> hired;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> N >> W;
    for(int i=0; i<N; i++){
        cin >> S[i] >> Q[i];
        v.push_back({(double)S[i]/Q[i], i});
    }

    sort(v.begin(), v.end());
    
    int kIdx = 0;
    int nHired = 0;
    int hiredQ = 0;
    int hiredS = 0;
    long long int sumHiredQ = 0;
    long long int sumQ = 0;

    for(int i = 0; i < N; i++){
        int q = Q[v[i].second];
        int s = S[v[i].second];
        
        pQ.push(q);
        sumQ += q;
        while(sumQ*s > W*q){
            sumQ -= pQ.top();
            pQ.pop();
        }

        if(pQ.size()>nHired || (pQ.size()==nHired && sumQ*s*hiredQ < sumHiredQ*hiredS*q)){
            nHired = pQ.size();
            hiredQ = q;
            hiredS = s;
            sumHiredQ = sumQ;
            kIdx = i;
        }
    }   

    for(int i=0; i<=kIdx; i++){
        hired.push_back({Q[v[i].second], v[i].second});
    }

    sort(hired.begin(), hired.end());

    cout << nHired << '\n';
    for(int i=0; i<nHired; i++){
        cout << hired[i].second+1 << '\n';
    }
}
