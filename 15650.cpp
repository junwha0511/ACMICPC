#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int seq[8] = {};

int N, M;

void printSeq(int n, int lv){
    if(lv==M){
        for(int i=0; i<M; i++) cout << seq[i] << ' ';
        cout << '\n';
        return;
    }   

    for(int i=n; i<=N; i++){
        seq[lv] = i;
        printSeq(i+1, lv+1);
    }


}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> N >> M;
    
    printSeq(1, 0);
    
}