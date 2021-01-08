#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    
    int N, a, cnt=0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a;
        v.push_back(a);
    }

    for(int i=N-1; i>0; i--){
        for(int j=i-1; j>=0; j--){
            if(v[j] >= v[i]){
                cnt += v[j]-(v[i]-1);
                v[j] = v[i]-1;
            }
        }
    }

    cout << cnt;
}
