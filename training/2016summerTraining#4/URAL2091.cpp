/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月24日 星期日 11时47分15秒
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
const int N=110,INF=0x3f3f3f3f;
int mp[N][N];

int main(){
  int n,m,i,j,k;
  while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=n;++i){
      for(j=1;j<=m;++j){
        scanf("%d",&mp[i][j]);
      }
    }
    int cnt1,cnt2,cnt3,cnt4,ans1,ans2;
    int minn=INF,tmp;
    for(i=1;i<=m;++i)
      for(j=i+1;j<=m;++j){
        cnt1=cnt2=cnt3=cnt4=0;
        for(k=1;k<=n;++k){
          if(mp[k][i] && mp[k][j])
            cnt1++;
          else if(mp[k][i] && !mp[k][j])
            cnt2++;
          else if(!mp[k][i] && mp[k][j])
            cnt3++;
          else cnt4++;
        }
        tmp=Max(Max(cnt1,cnt2),Max(cnt3,cnt4));
        if(tmp<minn)minn=tmp,ans1=i,ans2=j;
        if(minn==(n+m-1)/m)break;
      }
    printf("%d\n%d %d\n",minn,ans1,ans2);
  }
}
