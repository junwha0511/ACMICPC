#include<iostream>
#include<cstdio>

using namespace std;

int getSumDeci(int n){
    int deciSum = 0;
    while(n>0){
        deciSum += n%10;
        n /= 10;
    }
    return deciSum;
}

int getSeperateSum(int N){
    int seperator = 0;
    for(int i=N; i>=0; i--){
        if(getSumDeci(i)+i == N){
            seperator =  i;

        }
    }

    return seperator;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int N;
    cin >> N;
    
    cout << getSeperateSum(N);
    
}