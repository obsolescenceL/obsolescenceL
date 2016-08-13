/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月03日 星期一 12时15分25秒
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
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e5+10;
int num[N];

int main(){
  int n,i,x;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i)
      scanf("%d",num+i);
    for(i=n;i>0;--i)
      if(num[i]<num[i-1]){
        i--;break;
      }
    printf("%d\n",i);
    //cout<<"---------------"<<endl;
  }
}
