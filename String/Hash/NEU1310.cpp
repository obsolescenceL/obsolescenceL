/*************************************************************************
     File Name: NEU1310.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月02日 星期二 09时57分50秒
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
const int N1=5010,N2=34*30+10,N3=34*100000+10,N4=100010;
char s[N2],ss[N3];
ll num[40],nn[N4],h[N1],seed=31;
int l[N1];

ll BKRD_Hash(ll *str,int len){
  ll hash=0;
  while(len--)hash=hash*seed+(*str++);
  return hash;
}

int main(){
  int n,i,j,k,len;
  while(~scanf("%d",&n)){
    Mem0(nn);
    for(i=0;i<n;++i){
      Mem0(num);
      scanf("%s",s);
      len=strlen(s);
      for(j=k=0;j<len;++j)
        if(s[j]==')')k++;
        else if(s[j]>='A' && s[j]<='Z')
          num[k]=num[k]*seed+s[j];
      h[i]=BKRD_Hash(num,k);
      l[i]=k;
      //cout<<"h["<<i<<"]="<<h[i]<<" l["<<i<<"]="<<l[i]<<endl;
    }
    scanf("%s",ss);
    len=strlen(ss);
    for(i=j=0;i<len;++i)
      if(ss[i]==')')j++;
      else if(ss[i]>='A' && ss[i]<='Z')
        nn[j]=nn[j]*seed+ss[i];
    len=j;
    int cnt=0;
    for(i=0;i<n;++i){
      ll tmp=1,hash=BKRD_Hash(nn,l[i]-1);
      for(j=0;j<l[i];++j)tmp*=seed;
      for(j=l[i]-1;j<len;++j){
        hash=hash*seed+nn[j]-nn[j-l[i]]*tmp;
        //cout<<"hash="<<hash<<endl;
        if(hash==h[i])cnt++;
      }
    }
    printf("%d\n",cnt);
  }
}
