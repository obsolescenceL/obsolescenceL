/*************************************************************************
     File Name: HDU2177.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月14日 星期四 15时50分25秒
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

int main(){
  int a,b,i;
  while(~scanf("%d%d",&a,&b)&&(a||b)){
    //cout<<"a="<<a<<" b="<<b<<endl;
    int k=b-a;
    int ak=k*(1.0+sqrt(5.0))/2.0;
    //cout<<"ak="<<ak<<endl;
    if(a==ak) puts("0");
    else{
      puts("1");
      if(a>ak)printf("%d %d\n",ak,ak+k);
      for(i=b-1;i>=0;--i){
        k=a-i;
        if(k<0)k=-k;
        ak=k*(1.0+sqrt(5.0))/2.0;
        if(i<a && i==ak)printf("%d %d\n",i,a);
        if(i>a && a==ak)printf("%d %d\n",a,i);
      }
    }
  }
}
