#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();
    int N, K, i;

    cin >> N >> K;

    queue<int> q;

    for(int n=1; n<=N; n++) q.push(n);

    i = 1;
    cout << '<';
    while(!q.empty()){
        int f = q.front();
        q.pop();
        if(i%K == 0){
            if(!q.empty()){
                cout << f << ", ";
            }else{
                cout << f << '>';
            }
            i++;
        }else{
            q.push(f);
            i++;
        }
    }
    
}