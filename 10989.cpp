#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio();

    int N;
    cin >> N;
    int nums[10001] = {0,};

    int n;
    for (int i=0; i<N; i++) {
        cin >> n;
        nums[n]++;
    }

    for (int i=1; i<10001; i++) {
        for (int j=0; j<nums[i]; j++) {
            cout << i << "\n";
        }
    }
}

