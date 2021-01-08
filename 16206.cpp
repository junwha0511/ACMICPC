#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, a, cnt=0;
    cin >> N >> M;
    vector<int> v;

    for(int i=0; i<N; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    
    for(int i=0; i<N; i++){
        a = v[i];
        if(v[i]%10==0){
            while(a>10&&M>0){
                a -= 10;
                cnt++;
                if(a>0){
                    M--;
                }
            }
            if(a==10){
                cnt++;
            }
        }
    }
    for(int i=0; i<N; i++){
        a = v[i];
        if(v[i]%10!=0){
            while(a>10&&M>0){
                a -= 10;
                cnt++;
                if(a>0){
                    M--;
                }
            }
            if(a==10){
                cnt++;
            }
        }
    }
    cout << cnt;

}