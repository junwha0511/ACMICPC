#include<iostream>

using namespace std;

int pibo(int*& sequence, int n){ 
    if(sequence[n]==-1){
        sequence[n] = pibo(sequence, n-1) + pibo(sequence, n-2);
    }
    return sequence[n];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int* sequence = new int[46];
    int N;

    sequence[0] = 0;
    sequence[1] = 1;

    for(int i=2; i<46; i++){
        sequence[i] = -1;
    }
    cin>>N;
    cout<<pibo(sequence, N);

    cin>>N;

    delete[] sequence;

    return 0;

}