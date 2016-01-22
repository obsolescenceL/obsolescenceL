/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月20日 星期三 15时15分01秒
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
const int N=20;
char s[N],ss[N];

int main(){
  int len,i,n,nn;
  while(~scanf("%s",s)){
    Mem0(ss);
    len=strlen(s);
    if(s[0]=='0' && len==1)break;
    sscanf(s,"%d",&n);
    bool flag=1;
    for(i=0;i<len/2;++i)
      if(s[i]!=s[len-1-i])flag=0;
    if(flag){puts("0");continue;}

    for(i=0;i<len/2;++i)
      if(s[i]==s[len-1-i])
        ss[i]=ss[len-1-i]=s[i];
      else if(s[i]>s[len-1-i])ss[i]=ss[len-1-i]=s[i];
      else{
        if(s[len-i-2]!='9')s[len-i-2]++;
        else{
          int cnt=0;
          while(s[len-i-2-cnt]=='9')
            s[len-i-2-cnt]='0',cnt++;
          s[len-i-2-cnt]++;
        }
        ss[i]=ss[len-1-i]=s[i];
      }
    if(len%2)ss[len/2]=s[len/2];
    sscanf(ss,"%d",&nn);
    printf("%d\n",nn-n);
  }
}
