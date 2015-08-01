/*************************************************************************
     File Name: M.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月27日 星期一 16时33分45秒
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
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=200010,INF=0x3f3f3f3f;
int a1[N],a2[N];

int main(){
  int n,m,i,s,num,cnt1,cnt2,x;
  while(~scanf("%d",&n)){
    cnt1=cnt2=0;
    for(i=1;i<=n;++i){
      scanf("%d%d",&s,&num);
      if(s==1)a1[++cnt1]=num;
      else a2[++cnt2]=num;
    }
    //cout<<"cnt1="<<cnt1<<" cnt2="<<cnt2<<endl;
    //for(i=1;i<=cnt1;++i)
      //cout<<"a2["<<i<<"]="<<a2[i]<<endl;
    sort(a1+1,a1+1+cnt1);
    sort(a2+1,a2+1+cnt2);
    a1[cnt1+1]=a2[cnt2+1]=INF;
    scanf("%d",&m);
    for(i=1;i<=m;++i){
      scanf("%d",&x);
      //cout<<"x="<<x<<endl;
      int pos1=lower_bound(a1+1,a1+1+cnt1,x)-a1;
      int pos2=lower_bound(a2+1,a2+1+cnt2,-x)-a2;
      while(a1[pos1]==x)pos1++;
      while(a2[pos2]==-x)pos2++;
      printf("%d\n",pos1+pos2-2);
    }
  }
}
