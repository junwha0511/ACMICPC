#include<iostream>
#include<cstdio>

using namespace std;
typedef long long int lld;

const int SIZE = 1 << 20;
lld segTree[SIZE*2] = {0}; //sum(2^k) = 2^(k+1)-1

void update(int i, lld target){ //update ith number with target
    segTree[SIZE+i] = target;
    for(int k=(SIZE+i)/2; k>0; k/=2) segTree[k] = segTree[k*2]+segTree[k*2+1];
}

void build(){
    for(int k=(SIZE-1); k>0; k--) segTree[k] = segTree[k*2]+segTree[k*2+1];
}

lld findSum(int n, int start, int end, int tgStart, int tgEnd){
    if(start>tgEnd || end<tgStart) return 0;
    if(start>=tgStart && end<=tgEnd) return segTree[n];

    int mid = (start+end)/2;
    return findSum(n*2, start, mid, tgStart, tgEnd)+findSum(n*2+1, mid+1, end, tgStart, tgEnd);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    lld N, M, K;
    cin >> N >> M >> K;

    for(int i=SIZE+1; i<=SIZE+N; i++) cin >> segTree[i]; //SIZE+N+1~SIZE*2 is already initialized to 0
    build();
    
    lld a, b, c;
    for(int i=0; i<M+K; i++){
        cin >> a >> b >> c;
        if(a==1) update(b, c);
        else if(a==2) cout << findSum(1, 0, SIZE-1, b, c) << '\n'; 
    }
    


}