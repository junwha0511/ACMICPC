#include<iostream>
#include<cstdio>

using namespace std;

const int SIZE = 1 << 17;
int segTree[SIZE*2] = {0};

void build(){
    for(int i=SIZE-1; i>0; i--) segTree[i] = segTree[i*2]+segTree[i*2+1];
}

void update(int n){
    segTree[n] = 0;
    for(int i=n; i>0; i/=2) segTree[i] = segTree[i*2]+segTree[i*2+1];
}   

int frontNum(int n, int start, int end, int targetStart, int targetEnd){
    if(start>targetEnd || end<targetStart) return 0;
    if(targetStart<=start && end<=targetEnd) return segTree[n];

    int mid = (start+end)/2;
    return frontNum(n*2, start, mid, targetStart, targetEnd)+frontNum(n*2+1, mid+1, end, targetStart, targetEnd);
}

int main(){
    int N;
    
    int a, sequence[101010];
    
    for(int i=1; i<=N; i++){
        cin >> a;
        for(int j=0; j<N; j++){
            if(frontNum(1, 0, SIZE-1, 1, j) == a){
                sequence[j] = i;
                update(j);
                break;
            }
        }
    }

    for(int i=0; i<N; i++) cout << sequence[i];

}