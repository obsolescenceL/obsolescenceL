/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  1/ 2 14:24:30 2016
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
map<int,int> mp;
const int N=100010;
int a[N];

int main(){
  int n,i,j,x;
  while(~scanf("%d",&n)){
    Mem0(a);
    for(i=0;i<n;++i){
      scanf("%d",&a[i]);
      //mp[x]++;
    }
    sort(a,a+n);
    //for(i=0;i<n;++i)cout<<a[i]<<' ';
    //cout<<endl;
    int p=a[0],t=0;
    //bool check=1;
    for(i=0;i<n;i=j){
      for(j=i+1;a[i]==a[j];++j);
      //cout<<"j="<<j<<' ';
      if(a[i]>p+1){
        t=1;
        break;
      }
      if(j-i>t)t=j-i-t,p=a[i];
      else t-=j-i;
      //cout<<"p="<<p<<' ';
      //cout<<"j-i="<<j-i<<' ';
      //cout<<"t="<<t<<endl;
    }
    if(t)puts("NO");
    else puts("YES");
  }
}
