/*************************************************************************
    > File Name: POJ1988.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2014年12月31日 19:35:57
 ************************************************************************/
#include<cstdio>
const int MAXN=30010;
int pre[MAXN],num[MAXN],und[MAXN];
int find(int x){
  if(x!=pre[x]){
    int t=pre[x];
    pre[x]=find(pre[x]);
    und[x]+=und[t];
  }
  return pre[x];
}
void Union(int x,int y){
  int fx=find(x),fy=find(y);
  pre[fx]=fy;
  und[fx]+=num[fy];
  num[fy]+=num[fx];
}
int main(){
  int p,x,y,i;
  char op[5];
  scanf("%d",&p);
  for(i=1;i<=MAXN;i++)pre[i]=i,num[i]=1,und[i]=0;
  while(p--){
    scanf("%s",op);
    if(op[0]=='M'){
      scanf("%d%d",&x,&y);
      Union(x,y);
    } else{
      scanf("%d",&x);
      find(x);
      printf("%d\n",und[x]);
    }
  }
}
