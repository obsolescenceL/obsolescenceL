/*************************************************************************
     File Name: HDU3068.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月02日 星期日 15时28分51秒
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
const int N=110010;
char a[N],b[N<<1];
int p[N<<1];

int main(){
  int len,i,max_id,max_l,id;
  while(~scanf("%s",a+1)){
    for(i=1;a[i];++i){
      b[i<<1]=a[i];
      b[i<<1|1]='#';
    }
    b[0]='?',b[1]='#';
    len=(i<<1)+2,b[len]=0;
    max_id=max_l=0;
    for(i=1;i<len;++i){
      if(max_id>i)
        p[i]=Min(p[id*2-i],max_id-i);
      else p[i]=1;
      while(b[i+p[i]]==b[i-p[i]])
        p[i]++;
      if(p[i]+i>max_id)
        max_id=p[i]+i,id=i;
      max_l=Max(max_l,p[i]);
    }
    printf("%d\n",max_l-1);
  }
}
