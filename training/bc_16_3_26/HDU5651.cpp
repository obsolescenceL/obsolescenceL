/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  3/26 19:48:21 2016
 ************************************************************************/
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
const int N=1010,mod=1e9+7;
char s[N];
ll cnt[30],c[N][N];

void init(){
  int i,j;
  for(i=0;i<=1000;++i)
    c[i][0]=c[i][i]=1;
  for(i=2;i<=1000;++i){
    for(j=1;j<i;++j){
      c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
  }
}

int main(){
  init();
  int t,i,j;
  ios::sync_with_stdio(0);
  while(cin>>t){
    while(t--){
      Mem0(cnt);
      cin>>s;
      int n=strlen(s);
      if(n==1){cout<<"1\n";continue;}
      for(i=0;i<n;++i)cnt[s[i]-'a']++;
      int flag=2;
      for(i=0;i<26;++i){
        if(cnt[i]%2)flag--;
        cnt[i]/=2;
      }
      if(flag>0){
        n/=2;
        ll sum=1;
        int tmp=n;
        for(i=0;i<26;++i){
          sum*=c[tmp][cnt[i]];
          sum%=mod;
          tmp-=cnt[i];
        }
        cout<<sum<<endl;
      }else cout<<"0\n";
    }
  }
}
