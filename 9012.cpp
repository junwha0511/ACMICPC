#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;

int main(){
    // cin.tie(NULL);
    // ios_base::sync_with_stdio();

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        stack<char> st;
        string s;
        cin >> s;
        bool isVPS = true;
        for(int j=0; j<s.length(); j++){
            if(isVPS){
                if(s[j] == ')'){
                    if(st.empty()) isVPS = false;
                    st.pop();
                }else if(s[j] == '(') st.push('(');
            }
        }
        if(!st.empty()) isVPS = false;

        cout << (isVPS?"YES":"NO") << '\n';
    }

    
    
}