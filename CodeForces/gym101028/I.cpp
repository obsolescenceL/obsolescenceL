/*************************************************************************
     File Name: I.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月12日 星期二 16时01分50秒
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
const int N=1e5+10;
int a[N];

int main(){
  int t,n,k,i,ans;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&k);
      for(i=0;i<n;++i)scanf("%d",a+i);
      int low=1,high=(a[n-1]+k-1)/k,mid;
      //cout<<"low="<<low<<" high="<<high<<endl;
      while(low<=high){
        mid=(low+high)>>1;
        //cout<<"mid="<<mid<<endl;
        int cnt=1,pos=a[0];
        for(i=1;i<n;++i)
          if(a[i]-pos+1>mid)pos=a[i],cnt++;
        //cout<<"cnt="<<cnt<<endl;
        if(cnt>k)low=mid+1;
        else high=mid-1,ans=mid;
        //cout<<"low="<<low<<" high="<<high<<endl;
      }
      printf("%d\n",ans);
    }
  }
}
