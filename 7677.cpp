#include<iostream>
#include<cstdio>


using namespace std;
typedef long long lld;

struct matrix{
    lld a, b, c, d;
};

matrix mul(matrix m1, matrix m2){
    matrix m3;
    m3.a = (m1.a*m2.a + m1.b*m2.c)%10000;
    m3.b = (m1.a*m2.b + m1.b*m2.d)%10000;
    m3.c = (m1.c*m2.a + m1.d*m2.c)%10000;
    m3.d = (m1.c*m2.b + m1.d*m2.d)%10000;
    return m3;
}

matrix find(lld n){
    if(n == 0) return {0, 0, 0, 0};
    if(n == 1) return {1, 1, 1, 0};
    
    lld d = n/2;
    matrix operand = find(n/2);
    matrix result = mul(operand, operand);
    if(n%2 == 1) result = mul(result, {1, 1, 1, 0});
    return result;
}

int main(){
    cin.tie(NULL);  
    ios_base::sync_with_stdio();

    lld N;

    while(true){
        cin >> N;
        if(N == -1) break;
        cout << find(N).b << '\n';
    }
}

