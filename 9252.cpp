#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int greed[1000][1000];

string a, b;

string backTracking(int i, int j){
    if(greed[i][j]==0) return "";
    
    if(i==0){
        if(a[i]==b[j]) return string(1, a[i]);
        else return backTracking(i, j-1);
       
    }
    if(j==0){
        if(a[i]==b[j]) return string(1, b[j]);
        else return backTracking(i-1, j);

    }
    if(greed[i][j]==greed[i-1][j]) return backTracking(i-1, j);
    
    if(greed[i][j]==greed[i][j-1]) return backTracking(i, j-1);
    
    return backTracking(i-1, j-1).append(1, a[i]);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> a >> b;

    int prev, left, top;
    for(int i=0; i<a.length(); i++){
        for(int j=0; j<b.length(); j++){
            if(a[i]==b[j]){
                if(i==0||j==0){
                    prev = 0;
                }else{
                    prev = greed[i-1][j-1];
                }
                greed[i][j] = prev+1;
            }else{
                if(i==0) left = 0;
                else left = greed[i-1][j];
                if(j==0) top = 0;
                else top = greed[i][j-1];
                
                greed[i][j] = max(left, top);
            }
        }
    }

    string match = backTracking(a.length()-1, b.length()-1);
    cout << match.length() << '\n' << match;    
}
