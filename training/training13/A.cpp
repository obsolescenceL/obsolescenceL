/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月31日 星期五 14时22分54秒
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
const int N=100010;
char s[N];
int cnt[30];

ll get_sum(int n,int m){
  n=Min(n,m-n);
  ll ans=1;
  for(int i=0;i<n;++i) ans*=m-i;
  for(int i=1;i<=n;++i) ans/=i;
  return ans;
}

int main(){
  int k,i;
  while(~scanf("%s%d",s,&k)){
    Mem0(cnt);
    int len=strlen(s);
    for(i=0;i<len;++i)
      cnt[s[i]-'a']++;
    sort(cnt,cnt+26,greater<int>());
    int ans1=0,ans3=0,temp=-1;
    ll ans2=0;
    for(i=0;i<k;++i){
      ans1+=cnt[i];
      if(i==k-1 && cnt[i])temp=cnt[i];
    }
    for(i=0;i<k;++i)
      if(cnt[i]==temp)ans2++;
    for(;i<26;++i)
      if(cnt[i]==temp)ans3++;
    if(ans3)ans2=get_sum(ans2,ans3+ans2);
    else ans2=1;
    printf("%d %I64d\n",ans1,ans2);
  }
}
