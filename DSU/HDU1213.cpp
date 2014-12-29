#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1010;
int pre[MAXN];
int find(int x){
  return pre[x]==x? x:pre[x]=find(pre[x]);
}
void Union(int x,int y){
  int fx=find(x),fy=find(y);
  pre[fx]=fy;
}
int main(){
  int t,n,m,i,x,y;
  cin>>t;
  while(t--){
    cin>>n>>m;
    for(i=1;i<=n;i++)pre[i]=i;
    while(m--){
      cin>>x>>y;
      Union(x,y);
    }
    m++;
    for(i=1;i<=n;i++) if(i==pre[i])m++;
    cout<<m<<"\n";
  }
}
