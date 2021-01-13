#include<iostream>
#include<cstdio>

using namespace std;

long long N, L, I;
long long greed[32][32] = {0};
long long number[32] = {0};
long long notIncludeNth;

void nBitWays(long long n, long long l, long long i){  
    if(n==0 || l==0) return;    

    notIncludeNth = greed[n-1][l];
    
    if(i<=notIncludeNth){
        number[n] = 0;
        nBitWays(n-1, l, i);
    }else{
        number[n] = 1;
        nBitWays(n-1, l-1, i-notIncludeNth);
    }   
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> N >> L >> I;
    
    for(int n=1; n<=N; n++){ 
        greed[n][0] = 1;    
    }
    
    for(int l=0; l<=L; l++){ 
        greed[0][l] = 1;    
    }

    for(int l=1; l<=L; l++){
        for(int n=1; n<=N; n++){
            if(n<l) greed[n][l] = greed[n][l-1];
            else if(n==l) greed[n][l] = greed[n][l-1]+1;
            else greed[n][l] = greed[n-1][l]+greed[n-1][l-1];
        }
    }

    
    nBitWays(N, L, I);
    
    for(int i=N; i>0; i--){
        cout << number[i];
    }
}