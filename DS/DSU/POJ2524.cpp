#include<cstdio>
const int MAXN=50010;
int n,pre[MAXN];
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
  int m,i,j,k=0,x,y;
  while(~scanf("%d%d",&n,&m)&&n||m){
    for(i=1;i<=n;i++)pre[i]=i;
    while(m--){
      scanf("%d%d",&x,&y);
      Union(x,y);
    }
    printf("Case %d: %d\n",++k,n);
  }
}
