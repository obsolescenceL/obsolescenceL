/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月03日 星期一 14时34分26秒
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
int num[15];

int main(){
  int v,i,j,temp1,temp2,pos,bit,mod;
  while(~scanf("%d",&v)){
    bit=mod=0;
    for(i=1;i<10;++i){
      scanf("%d",&num[i]);
      temp1=v/num[i];
      temp2=v%num[i];
      if(bit<temp1 || (bit==temp1 && mod<=temp2))
        bit=temp1,mod=temp2,pos=i;
    }
    if(!bit){puts("-1");continue;}
    //cout<<"bit="<<bit<<endl;
    for(i=1;i<bit;++i)
      for(j=9;j>=pos;--j)
        if(num[j]<=num[pos]+mod){
          mod-=num[j]-num[pos];
          printf("%d",j);
          break;
        }
    //cout<<"------"<<endl;
    if(mod){
      for(i=9;i>=pos;--i)
        if(num[i]<=num[pos]+mod){
          printf("%d\n",i);
          break;
        }
    }else printf("%d\n",pos);
  }
}
