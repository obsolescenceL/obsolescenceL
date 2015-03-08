/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月07日 星期六 15时56分44秒
 ************************************************************************/
#include<cstdio>
int pre[1010];

int find(int x){
  return x==pre[x]?x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  int fx=find(x),fy=find(y);
  //if(fx!=fy){
    pre[fx]=fy;
    //nn--;
  //}
}

int main(){
  int n,m,i,x,y;
  scanf("%d%d",&n,&m);
  //nn=n;
  for(i=0;i<=n;++i)pre[i]=i;
  for(i=0;i<m;++i)scanf("%d%d",&x,&y),Union(x,y);
  //if(!nn){
    //puts("NO");
    //continue;
  //}
  int p=find(1);
  for(i=1;i<=n;++i)
    if(p!=find(i)){
      puts("NO");
      return 0;
    }
  if(n==m)puts("FHTAGN!");
  else puts("NO");
}
