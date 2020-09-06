#include<iostream>
#include<cstdio>

using namespace std;
//N이라는 숫자가 있을 때, N/2를 초과하는 수 중에 N의 약수는 존재하지 않는다!
//따라서 M~N의 약수 판별에서는 2~N/2로 에라토스테네스의 체를 적용하면 된다.

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    short numArr[1000001] = {0,};
    numArr[0] = -1;
    numArr[1] = -1;

    int M, N;
    cin>>M>>N;  
    //cout<<M<<N;
    
    if(M==1){
        M = 2;
    }

    for(int i=2; i<(N/2); i++){
        if(numArr[i]!=-1){
            for(int j=2; j*i<=N; j++){
                numArr[i*j] = -1;
            }
        }
    }

    for(int i=M; i<=N; i++){
        if(numArr[i]!=-1){
            cout<<i<<"\n";
        }
    }
}
