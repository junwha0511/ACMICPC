#include<iostream>
#include<cstdio>

using namespace std;

int prefix[1025][1025] = {0}; 

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N, M, x1, y1, x2, y2, c;

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> c;
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + c;
        }
    }

    for(int m=0; m<M; m++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1] << '\n';
    }

}