#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    bool* flags = new bool[t];

    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        string letters = "";
        vector<char> v;

        cin.ignore();

        for(int j=0; j<n; j++){
            string line;
            getline(cin, line);
            letters += line;
        }

        copy(letters.begin(), letters.end(), back_inserter(v));
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        
        flags[i] = true;
        for(int j=0; j<v.size(); j++){
            int cnt = count(letters.begin(), letters.end(), v[j]);
            if(cnt%n != 0){
                flags[i] = false;
                break;
            }
        }
    }

    for(int i=0; i<t; i++){
        cout << (flags[i]?"YES":"NO") << "\n";
    }

    delete *flags;
}