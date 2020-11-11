#include<iostream>

using namespace std;

int main(){
    int t, n;
    unsigned long long k;

    cin >> t;
    
    int** arr = new int*[t];

    for(int i=0; i<t; i++){
        cin >> n >> k;
        arr[i] = new int[n];
        
        int min = 1000000001, max = -1000000001;
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j]<min)
                min = arr[i][j];
            if(arr[i][j]>max)
                max = arr[i][j];
        }
        if(k%2==0){
            for(int j=0; j<n; j++){
                arr[i][j] = -min+arr[i][j];
            }
        }else if(k%2==1){
            for(int j=0; j<n; j++){
                arr[i][j] = max-arr[i][j];
            }
        }

        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    delete *arr;

    cin >> t;
}