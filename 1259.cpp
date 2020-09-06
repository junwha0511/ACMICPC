
#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        int num, d=0, flag=true;
        int* numArr = new int[5];
        cin>>num;
        if(num==0){
            break;
        }else{
            while(num){
                numArr[d] = num%10;
                num /= 10;
                d++;
            }
        }
        
        for(int i=0; i<d; i++){
            if(numArr[i]!=numArr[d-i-1]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
        delete[] numArr;
    }
}