#include<iostream>
#include<cstdio>
#include<deque>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();
    
    int N, M;
    cin >> N >> M;

    deque<int> dq;

    for(int i=1; i<=N; i++) dq.push_back(i);

    int cnt = 0;
    for(int i=0; i<M; i++){
        int target;
        int targetIndex;
        cin >> target;

        for(int j=0; j<dq.size(); j++){
            if(dq[j] == target){
                targetIndex = j;
                break;
            }
        }
        if(targetIndex*2 <= dq.size()){
            while(true){
                if(dq.front() == target){
                    dq.pop_front();
                    break;
                }
                else{
                    cnt++;
                    dq.push_back(dq.front());
                    dq.pop_front();
                }            
            }
        }else{
            while(true){
                if(dq.front() == target){
                    dq.pop_front();
                    break;
                }
                else{
                    cnt++;
                    dq.push_front(dq.back());
                    dq.pop_back();
                }      
            }
        }

    }

    cout << cnt;
    
}


