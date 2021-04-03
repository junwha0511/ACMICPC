#include<iostream>
#include<queue>
#include<stack>
#include<string>

using namespace std;

int main(){    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T, Q, K;
    
    cin >> T;
    for(int i=0; i<T; i++){
        priority_queue<int, vector<int>, greater<int>> pq;

        int sum = 0;

        cin >> Q >> K;
        for(int j=0; j<Q; j++){
            string s;
            cin >> s;
            if(s == "insert"){
                int n;

                cin >> n;
                sum ^= n;

                pq.push(n);
                if(pq.size() == K+1){
                    sum ^= pq.top();
                    pq.pop();
                }
            }else if(s == "print"){
                cout << sum << '\n';
            }
        }
    }
}