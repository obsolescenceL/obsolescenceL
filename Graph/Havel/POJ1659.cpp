/*************************************************************************
     File Name: i.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月14日 星期六 16时20分33秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
  int id,inde;
  bool operator < (const node& rhs) const {
    return inde>rhs.inde;
  }
}in[15];
bool adj[15][15];

int main(){
  int t,n,i,j,k;
  while(~scanf("%d",&t)){
    while(t--){
      memset(adj,0,sizeof adj);
      bool flag=1;
      scanf("%d",&n);
      for(i=1;i<=n;++i)scanf("%d",&in[i].inde),in[i].id=i;
      for(k=1;k<=n&&flag;++k){
        sort(in+k,in+1+n);
        int x=in[k].inde;
        for(i=1;i<=x&&flag;++i){
          int a=in[k].id,b=in[k+i].id;
          in[k+i].inde--;
          adj[a][b]=adj[b][a]=1;
          //cout<<"x="<<x<<' '<<"in.id="<<in[i].id<<endl;
          if(in[i+k].inde<0)flag=0;
        }
        if(!flag)break;
      }
      if(flag){
        puts("YES");
        for(i=1;i<=n;++i){
          printf("%d",adj[1][i]);
          for(j=2;j<=n;++j)
            printf(" %d",adj[i][j]);
          puts("");
        }
      }else{
        puts("NO");
      }
      if(t) puts("");
    }
  }
}
