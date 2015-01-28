/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月28日 12:21:14
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=310;
int m,t,r,c[MAXN],g[MAXN],x;
bool vis[MAXN];
int main(){
  int i,j,k;
  while(~scanf("%d%d%d",&m,&t,&r)){
    memset(g,0,sizeof g);
    memset(c,0,sizeof c);
    memset(vis,0,sizeof vis);
    for(i=1;i<=m;i++)scanf("%d",&x),g[x]=1;
    if(t<r){
      puts("-1");
      continue;
    }
    int flag=1,cnt;
    for(i=1;i<MAXN;i++){
      if(g[i]&&flag){
        //cout<<i<<endl;
        flag=0;
        cnt=r;
        k=r;
        for(j=i;j<i+t;j++){
          if(j>i+t-r)k--;
          c[j]=k;
        }
        //cout<<"c["<<i<<"]="<<c[i]<<endl;
      }
      j=i-1;
      while(g[i]&&c[i]<r){
        if(!vis[j]){
          vis[j]=1;
          //cout<<"vis["<<j<<"]="<<vis[j]<<endl;
          for(k=j+1;k<=j+t;k++){
            c[k]++;
            //cout<<"c["<<k<<"]="<<c[i]<<endl;
          }
        }
        j--;
      }
    }
    for(i=1;i<MAXN;i++){
      if(vis[i])cnt++;
      //cout<<"i="<<i<<' '<<"cnt="<<cnt<<endl;
    }
    printf("%d\n",cnt);
  }
}
