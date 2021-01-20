#include<iostream>

using namespace std;

long long int seq[91] = {0};

long long int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    if(seq[n]==0) seq[n] = fibo(n-1) + fibo(n-2);
    
    return seq[n];

}
int main(){
    int N;
    cin >> N;
    cout << fibo(N);
}