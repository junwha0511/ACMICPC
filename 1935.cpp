#include<iostream>
#include<stack>
#include<string>

using namespace std;


int main(){
    cout << fixed;
    cout.precision(2);
    
    stack<double> st;

    int N;
    cin >> N;
    
    string s;
    cin >> s;

    int operand[30];

    for(int i=0; i<N; i++){
        cin >> operand[i];
    }    

    for(int i=0; i<s.length(); i++){
        double operand1, operand2, result;
        if(s[i]>='A' && s[i]<='Z'){
            st.push(operand[s[i]-'A']); //convert A to 0, B to 1, ...
            continue;
        }else{
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();
        }

        if(s[i] == '+') result = operand1+operand2;
        else if(s[i] == '-') result = operand1-operand2;
        else if(s[i] == '*') result = operand1*operand2;
        else if(s[i] == '/') result = operand1/operand2;
        
        st.push(result);
    }

    cout << st.top();
}
