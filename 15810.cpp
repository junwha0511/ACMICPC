#include<iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;

    cin>>N>>M;

    int staff[1000000];

    for(int i=0; i<N; i++){
        cin>>staff[i];
    }
    long long st = 1, et = 1000000000000;

    while(st+1 < et){
        long long mt = (st + et) / 2;

        long long balloonCnt = 0;
        for(int i=0; i<N; i++)
            balloonCnt += mt / staff[i];
    
        if(balloonCnt < M){
            st = mt; 
        }else if(balloonCnt >= M){
            et = mt;
        }
    }

    cout << et;

    cin >> N;

}