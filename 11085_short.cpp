#include<bits/stdc++.h>
using namespace std;
struct R{int w, n1, n2;};struct o{bool operator()(R &a,R &b){return a.w<b.w;}};int n[1001],s[1001];priority_queue<R,vector<R>,o> q;int f(int u){if(n[u] == u) return u;return n[u]=f(n[u]);}void un(int u, int v){int x=f(u), y=f(v);if(x==y)return;if(s[x]>s[y])swap(x, y);n[x]=y;s[y]+=s[x];}int main(){int p,w,c,v,i,l,x,y,z;cin>>p>>w>>c>>v;for(i=0;i<p;i++){n[i]=i;s[i]=1;}for(i=0;i<w;i++){cin>>x>>y>>z;q.push({z,x,y});}while(f(c)!=f(v)){R t=q.top();l=t.w;un(t.n1,t.n2);q.pop();}cout<<l;}