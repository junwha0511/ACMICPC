#include<iostream>
#include<cmath>

using namespace std;
typedef long long int lli;

lli powC(lli a, lli b, lli c){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        return (powC(a, b/2, c)*powC(a, b/2, c))%c;
    }else{
        return (powC(a, b/2, c)*powC(a, b/2, c)*a)%c;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    lli A, B, C;
    cin>>A>>B>>C;
    cout<<powC(A, B, C)%C;
}