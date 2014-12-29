#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1010;
int pre[MAXN],n;
int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}
void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx!=fy){
    pre[fx]=fy;
    n--;
  }
}
int main(){
  int m,x,y,i;
  while(~scanf("%d",&n)&&n){
    for(i=1;i<=n;i++)pre[i]=i;
    cin>>m;
    while(m--){
      cin>>x>>y;
      Union(x,y);
    }
    n--;
    cout<<n<<"\n";
  }
}
