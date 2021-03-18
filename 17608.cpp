#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int arr[101010];

    for(int i=0; i<N; i++){
        cin >> arr[i];    
    }

    int max = arr[N-1];
    int cnt = 1;

    for(int i=N-2; i>=0; i--){
        if(arr[i] > max){
            max = arr[i];
            cnt++;
        }
    }

    cout << cnt;
}
