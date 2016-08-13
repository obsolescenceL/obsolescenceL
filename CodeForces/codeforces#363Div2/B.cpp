/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月19日 星期二 21时26分45秒
 ************************************************************************/
#include<bits/stdc++.h>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=1010;
char mp[N][N];
struct node{
  int x,y;
}p[N*N];

bool cmp1(node lhs,node rhs){
  return lhs.x<rhs.x;
}

bool cmp2(node lhs,node rhs){
  return lhs.y<rhs.y;
}

int main(){
  int n,m,i,j;
  while(~scanf("%d%d",&n,&m)){
    bool flag=1;
    int cnt=0;
    for(i=0;i<n;++i){
      scanf("%s",mp[i]);
      for(j=0;j<m;++j){
        if(mp[i][j]=='*'){
          p[cnt].x=i;
          p[cnt].y=j;
          cnt++;
        }
      }
    }
    sort(p,p+cnt,cmp1);
    int con_x=-1,con_y=-1;
    int cntx=1,cnty=1;
    for(i=0;i<cnt-1;++i){
      if(p[i].x==p[i+1].x){
        if(con_x==-1)con_x=p[i].x;
        if(con_x==p[i].x)cntx++;
      }
    }
    //cout<<"cntx="<<cntx<<endl;
    sort(p,p+cnt,cmp2);
    for(i=0;i<cnt-1;++i){
      if(p[i].y==p[i+1].y){
        if(con_y==-1)con_y=p[i].y;
        if(con_y==p[i].y)cnty++;
      }
    }
    //cout<<"cnty="<<cnty<<endl;
    //cout<<"cnt="<<cnt<<endl;
    
    if(cnt==0)con_x=con_y=0;
    if(cnt==1)con_x=p[0].x,con_y=p[0].y;
    if(cnt==2)con_x=p[0].x,con_y=p[1].y;
    if(cntx+cnty>cnt || (cntx+cnty==cnt && mp[con_x][con_y]=='.'))printf("YES\n%d %d\n",con_x+1,con_y+1);
    else puts("NO");
  }
}
