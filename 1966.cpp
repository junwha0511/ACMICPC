#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();
    int T, N, M;

    
    cin >> T;
    for(int i=0; i<T; i++){
        queue<int> q;
        int P[101], max=0;
        cin >> N >> M;
    
        for(int j=0; j<N; j++){
            cin >> P[j];
            q.push(j);
            if(P[j] > max) max = P[j];
        }

        int prt = 1;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            if(P[f] >= max){
                //print
                if(f == M){
                    cout << prt << '\n';
                    break;
                }else{
                    max = 0;
                    f = q.front();
                    while(true){
                        if(P[q.front()] > max) max = P[q.front()];
                        q.push(q.front());
                        q.pop(); 
                        if(q.front() == f) break;
                    }
                    prt++;
                }
            }else{
                q.push(f);
            }
        }
    }


    
}