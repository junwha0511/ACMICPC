#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long lld;

lld N, h[101010];

lld findIntersection(lld start, lld mid, lld end){
    lld i=mid, j=mid+1, minHeight=min(h[i], h[j]), width=2, maxArea=width*minHeight;
    

    while(i>start && j<end){
        if(h[i-1] < h[j+1]) minHeight = min(minHeight, h[++j]);
        else minHeight = min(minHeight, h[--i]);
        maxArea = max(maxArea, ++width*minHeight);
    }
    while(i>start){
        minHeight = min(minHeight, h[--i]);
        maxArea = max(maxArea, ++width*minHeight);
    }
    while(j<end){
        minHeight = min(minHeight, h[++j]);
        maxArea = max(maxArea, ++width*minHeight);
    }
    
    return maxArea;
}

lld solve(lld start, lld end){
    if(start == end) return h[start];

    lld mid = (start+end)/2;
    lld area1 = solve(start, mid);
    lld area2 = solve(mid+1, end);
    lld area3 = findIntersection(start, mid, end);

    return max(area1, max(area2, area3));
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    while(true){
        cin >> N;
        if(N==0) break;
        for(int i=0; i<N; i++){
            cin >> h[i];
        }
        cout << solve(0, N-1) << '\n';
    }   
}

