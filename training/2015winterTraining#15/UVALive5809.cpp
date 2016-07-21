/*************************************************************************
     File Name: UVALive5809.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月12日 星期五 12时39分06秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
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
const int N=1010,INF=0x3f3f3f3f;
int a[2][N],tmp[N];
char mp[N][N];

int change(int sum,int n,int x){
  int ans=INF,i,j;
  for(i=0;i<n;++i){
    for(j=0;j<n;++j) tmp[j]=a[x][j];
    int cur=i,temp=0;
    for(j=0;j<n;++j){
      temp+=Abs(tmp[cur],sum);
      tmp[(cur+1)%n]+=tmp[cur]-sum;
      cur=(cur+1)%n;
    }
    ans=Min(ans,temp);
  }
  return ans;
}

int main(){
  int t,n,m,i,j,sum,temp;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      Mem0(a),sum=0;
      scanf("%d%d",&n,&m);
      for(i=0;i<n;++i){
        scanf("%s",mp[i]);
        for(j=0;j<m;++j)
          if(mp[i][j]=='1')
            a[0][i]++,a[1][j]++,sum++;
      }
      printf("Case %d: ",nc);
      if(sum%m==0 && sum%n==0)
        printf("both %d\n",change(sum/n,n,0)+change(sum/m,m,1));
      else if(sum%n==0)printf("row %d\n",change(sum/n,n,0));
      else if(sum%m==0)printf("column %d\n",change(sum/m,m,1));
      else puts("impossible");
    }
  }
}
