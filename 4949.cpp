#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();
    
    while(true){
        stack<char> st;
        string s;
        bool flag = true;

        getline(cin, s);
        if(s == ".") break;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '[') st.push(s[i]);
            else if(s[i] == ')'){
                if(st.empty()){
                    cout << "no" << '\n';
                    flag = false;
                    break;
                }else if(st.top() == '('){
                    st.pop();
                }else{
                    cout << "no" << '\n';
                    flag = false;
                    break;
                }
            }else if(s[i] == ']'){
                if(st.empty()){
                    cout << "no" << '\n';
                    flag = false;
                    break;
                }else if(st.top() == '['){
                    st.pop();
                }else{
                    cout << "no" << '\n';
                    flag = false;
                    break;
                }
            }
        }        

        if(!flag) continue;

        if(st.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }    
}