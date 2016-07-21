/*************************************************************************
     File Name: D.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月20日 星期三 15时00分08秒
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
const int N=110;
int a[N];

int main(){
  int t,n,i;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=0;i<n;++i)scanf("%d",a+i);
      sort(a,a+n);
      int wrong=0,right=0,ans=0;
      for(i=0;i<n;++i){
        right+=i;
        wrong+=a[i];
        if(wrong<right){
          ans+=right-wrong;
          wrong=right;
        }
      }
      printf("%d\n",ans+wrong-right);
    }
  }
}
