#include<iostream>
#include<cmath>

using namespace std;

int countZ(int n, int r, int c);

int main(){
    int N, R, C;

    cin >> N >> R >> C;
    cout << countZ(N, R+1, C+1)-1;

}

int countZ(int n, int r, int c){
    if(n == 0) return 1;

    int power = pow(2, n-1);

    if(r<=power && c<=power){
        return countZ(n-1, r, c);
    }else if(r<=power && c>power){
        return countZ(n-1, power, power)+countZ(n-1, r, c-power);
    }else if(r>power && c<=power){
        return 2*countZ(n-1, power, power)+countZ(n-1, r-power, c);
    }else{
        return 3*countZ(n-1, power, power)+countZ(n-1, r-power, c-power);
    }
}


