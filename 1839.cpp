#include<iostream>
#include<cstdio>

using namespace std;

const int SIZE = 1 << 17;
int segTree[SIZE*2] = {0};

void build(){
    for(int i=SIZE-1; i>0; i--) segTree[i] = segTree[i*2]+segTree[i*2+1];
}

void update(int n){
    segTree[SIZE+n] = 0;
    for(int i=(SIZE+n)/2; i>0; i/=2) segTree[i] = segTree[i*2]+segTree[i*2+1];
}   

int find(int n, int sum, int start, int end){
    if(start == end) return start;
    int mid = (start+end)/2;
    if(segTree[n*2] <= sum) return find(n*2, sum, start, mid);
    else return find(n*2+1, sum-segTree[n*2], mid+1, end);
}

int main(){
    int N;
    
    int a, sequence[101010];
    
    cin >> N;
    segTree[0] = 0;
    for(int i=1; i<=N; i++) segTree[SIZE+i] = 1;
    build();
    for(int i=1; i<=N; i++){
        cin >> a;
        int k = find(1, a+1, 0, SIZE-1);
        sequence[k] = i;
        update(k);
    
    }
    for(int i=1; i<=N; i++) cout << sequence[i] << endl;

}