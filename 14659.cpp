#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    int m=0, e=0, d=0, h;
    for(int i=0; i<N; i++){
        cin >> h;
        if(h>=d){
            d = h;
            if(m < e){
                m = e; 
            }
            e = 0;
        }else{
            e++;
        }
    }
    
    cout << max(m, e);
}