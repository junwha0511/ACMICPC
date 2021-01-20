#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int greed[15][15] = {0};
int ways = 0;
int N;

bool canLocQueen(int x, int y){
    for(int i=0; i<N; i++){
        if(x-i>=0) if(greed[x-i][y]) return false;
        if(x+i<N) if(greed[x+1][y]) return false;
        if(i!=0){
        if(y-i>=0) if(greed[x][y-i]) return false;
        if(x-i>=0&&y-i>=0) if(greed[x-i][y-i]) return false;
        if(x+i<N&&y-i>=0) if(greed[x+i][y-i]) return false;
        }
    }
    return true;
}

void setQueen(int numberQueen){
    if(numberQueen==N){
        ways++;
        return;
    }   

    for(int i=0; i<N; i++){
        if(canLocQueen(i, numberQueen)){
            greed[i][numberQueen] = 1;
            setQueen(numberQueen+1);
            greed[i][numberQueen] = 0;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> N;
    setQueen(0);
    cout << ways;
}