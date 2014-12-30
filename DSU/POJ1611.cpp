#include<cstdio>
const int MAXN=30010;
int pre[MAXN],num[MAXN];
int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}
void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx!=fy){
    pre[fx]=fy;
    num[fy]+=num[fx]; 
  }
}
int main(){
  int n,m,k,x,y,i;
  while(~scanf("%d%d",&n,&m)&&n||m){
    for(i=0;i<n;i++)pre[i]=i,num[i]=1;
    while(m--){
      scanf("%d%d",&k,&x);
      for(i=1;i<k;i++){
        scanf("%d",&y);
        Union(x,y);
      }
    }
    printf("%d\n",num[find(0)]);
  }
}
