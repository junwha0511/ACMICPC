#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

bool isUsed[9] = {};
int seq[8] = {};

int N, M;

void printSeq(int lv){
    if(lv==M){
        for(int i=0; i<M; i++) cout << seq[i] << ' ';
        cout << '\n';
        return;
    }   

    for(int i=1; i<=N; i++){
        if(isUsed[i]) continue;
        seq[lv] = i;
        isUsed[i] = true;
        printSeq(lv+1);
        isUsed[i] = false;
    }


}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        for(int i=1; i<=N; i++){
            isUsed[i] = false;
        }

        seq[0] = i;
        isUsed[i] = true;
        
        printSeq(1);
    }
}