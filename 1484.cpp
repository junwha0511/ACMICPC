#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;
typedef long long int lld;

vector<lld> v;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    int G;
    cin >> G;
    


    for(lld i=0; i<=200000; i++) v.push_back(i*i);

    int past = 0, now = 0;
    bool none = true;
    while(true){
        if(G <=  v[now]-v[past]) past++;
        else if(now==v.size()) break;
        else now++;

        if(G == v[now]-v[past]){
            if(none) none = false;
            cout << static_cast<lld>(sqrt(v[now])) << '\n';
        }
    }

    if(none) cout << -1;
}