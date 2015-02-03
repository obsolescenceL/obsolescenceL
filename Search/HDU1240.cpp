#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10;
char mp[MAXN*MAXN][MAXN];
int mx[]={1,-1,0,0};
int my[]={0,0,1,-1};
int flag,n,x0,x1,y0,y1,z0,z1,di,dis,ans;

int dist(int x,int y){
  return max(x-x1-n*z1,x1+n*z1-x)+max(y-y1,y1-y);
}

void dfs(int x,int y,int steps){
  if(flag)return;
  if(x==n*z1+x1&&y==y1){
    flag=1,ans=steps;
    return;
  }
  dis=dist(x,y);
  if(dis+steps>di)return;
  for(int i=0;i<4;i++){
    int dx=x+mx[i],dy=y+my[i],dsteps=steps+1;
    if(mp[dx][dy]=='O'&&dx>=0&&dx<n*n&&dy>=0&&dy<n)
      mp[dx][dy]='X',dfs(dx,dy,dsteps);
  }
}

int main(){
  int i,j;
  while(~scanf("%*s%d",&n)){
    flag=0;
    for(i=0;i<n*n;i++) scanf("%s",mp[i]);
    scanf("%d%d%d",&y0,&x0,&z0);
    scanf("%d%d%d%*s",&y1,&x1,&z1);
    di=max(x1+n*z1-x0-n*z0,x0+z0*n-x1-n*z1)+max(y1-y0,y0-y1);
    dfs(x0+z0*n,y0,0);
    if(flag)printf("%d %d\n",n,ans);
    else puts("NO ROUTE");
  }
}
