/*************************************************************************
     File Name: f.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月13日 星期五 17时47分35秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int ans,n,m,k;
char mp[15][15][15];
int mx[]={0,0,0,0,1,-1},my[]={0,0,1,-1,0,0},mz[]={1,-1,0,0,0,0};

void dfs(int x,int y,int z){
  if(x<0||y<0||z<0||x>=n||y>=m||z>=k||mp[z][x][y]=='#')return;
  ans++;
  mp[z][x][y]='#';
  //cout<<"ans="<<ans<<endl;
  for(int i=0;i<6;++i){
    int dx=x+mx[i],dy=y+my[i],dz=z+mz[i];
    dfs(dx,dy,dz);
  }
}

int main(){
  int i,j,l,x,y;
  while(~scanf("%d%d%d",&k,&n,&m)){
    ans=0;
    for(i=0;i<k;++i)
      for(j=0;j<n;++j)
        scanf("%s",mp[i][j]);
    scanf("%d%d",&x,&y);
    dfs(x-1,y-1,0);
    printf("%d\n",ans);
  }
}
