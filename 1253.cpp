#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long int lld;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    lld N, A[2010];
    cin >> N;

    for(int i=0; i<N; i++) cin >> A[i];
    sort(A, A+N);

    int cnt = 0;
    for(int i=0; i<N; i++){
        if(N<=2) break;
        int a=0, b=N-1;
        while(true){
            if(a==i) a++;
            if(b==i) b--;

            lld sum = A[a]+A[b];
            if(a>=b) break;
            if(sum == A[i]){
                cnt++;
                break;
            }else if(sum > A[i]){
                b--;
            }else{
                a++;
            }
        }
    }

    cout << cnt;

}