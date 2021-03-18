#include<iostream>
#include<string>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    int minCnt = b.length();
    

    for(int i=0; i+a.length()<=b.length(); i++){
        int cnt = 0;
        for(int j=0; j<a.length(); j++) if(a[j] != b[i+j]) cnt++;
        if(cnt < minCnt) minCnt = cnt;
    }
    
    cout << minCnt;
}