#include<iostream>
#include<cstdio>

using namespace std;

int sequence[1001010];
int tmp[1001010];
long long int cnt = 0;

void divide(int start, int end){
    if(start==end-1) return;

    //divide and process
    int mid = (start+end)/2;
    divide(start, mid);
    divide(mid, end);
    
    //comparison
    int i = start, j = mid;
    while(i<mid && j<end){
        if(sequence[i] > sequence[j]){
            cnt += end-j;
            i++;
        }else{
            j++;
        }
    }

    //merge
    i = start, j = mid;
    int tmp_idx = start;

    while(i<mid && j<end){
        if(sequence[i] > sequence[j]) tmp[tmp_idx++] = sequence[i++];
        else tmp[tmp_idx++] = sequence[j++];
    }

    while(i < mid) tmp[tmp_idx++] = sequence[i++];
    while(j < end) tmp[tmp_idx++] = sequence[j++];

    for(int k=start; k<end; k++) sequence[k] = tmp[k];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> sequence[i];
    }

    divide(0, N);

    cout << cnt;
}