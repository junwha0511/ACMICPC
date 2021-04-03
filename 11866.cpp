#include<iostream>
#include<queue>

using namespace std;

int main(){
    int N, K;

    queue<int> tq, fq;

    cin >> N >> K;

    for(int i=1; i<=N; i++) tq.push(i);
    
    int i = 1;
    while(tq.size()){
        if(i == K){
            fq.push(tq.front());
            i = 1;
        }else{
            tq.push(tq.front());
            i++;
        }
        
        tq.pop();
    }

    while(fq.size()){
        if(fq.size() == N) cout << '<';
        else cout << ", ";
        cout << fq.front();
        fq.pop();
        if(fq.size() == 0) cout << '>';
    }
}