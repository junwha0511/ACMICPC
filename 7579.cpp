#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int DP[2][10000001] = {0};
int cur = 1, pst = 0;

vector<int> m, c;

int findValue(int i, int mem){
    if(mem<0) return -10101010;
    if(i<0) return 0;
    //cout <<  DP[pst][mem] << endl;

    return DP[pst][mem];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N, M, tmp, sumM = 0, sumC = 0;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> tmp;
        m.push_back(tmp);
        sumM += tmp;
    }

    for(int i=0; i<N; i++){
        cin >> tmp;
        c.push_back(tmp);
        sumC += tmp;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<=sumM-M; j++){
            DP[cur][j] = max(findValue(i-1, j), findValue(i-1, j-m[i])+c[i]);
        }
        swap(cur, pst);
    }

    cout << sumC-DP[pst][sumM-M];
    
}