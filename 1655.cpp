/*
중간값 sequence 찾기
priority queue를 두 개 두고, 이전 median과 비교하여 무엇을 삽입할 지 결정

Invariant: top of lq is median

Strategy for new number 
N(lq) == N(gq): push n to lq
N(lq) == N(gq)+1: push n to lq, pop lq and push to gq

*/

#include<iostream>
#include <queue>
#include<cstdio>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> greater_pq; // greater numbers will be here, less out first
    priority_queue<int, vector<int>, less<int>> less_pq; // less numbers will be here, greater out first
    
    int n;
    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> n;
        if (less_pq.size() == greater_pq.size()) {
            greater_pq.push(n);
            less_pq.push(greater_pq.top());
            greater_pq.pop();
        } else if (less_pq.size() == greater_pq.size()+1){
            less_pq.push(n);
            greater_pq.push(less_pq.top());
            less_pq.pop();
        } else {
            cout << "Assertion failed!\n";
        }
        cout << less_pq.top() << "\n";
    }

    return 0;
}