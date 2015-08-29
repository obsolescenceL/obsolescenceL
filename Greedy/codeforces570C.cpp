/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月27日 星期四 20时59分58秒
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
const int N=300010;
char s[N];

int main(){
  int n,m,i,pos,cnt,sum;
  char ch[2];
  while(~scanf("%d%d",&n,&m)){
    scanf("%s",s+1);
    sum=cnt=0;s[0]='#';
    bool flag=1;
    for(i=1;i<=n;++i){
      if(s[i]=='.' && flag){
        flag=0;
      }else if(s[i]=='.'){
        cnt++;
      }else{
        flag=1,sum+=cnt,cnt=0;
      }
    }
    sum+=cnt;
    while(m--){
      scanf("%d%s",&pos,ch);
      if(ch[0]==s[pos] || (ch[0]!='.' && s[pos]!='.')){//!!!~~~
        printf("%d\n",sum);
        continue;
      }
      if(ch[0]=='.'){
        if(s[pos-1]=='.' && s[pos+1]=='.')sum+=2;
        else if(s[pos-1]=='.' || s[pos+1]=='.')sum+=1;
      }else{
        if(s[pos-1]=='.' && s[pos+1]=='.')sum-=2;
        else if(s[pos-1]=='.' || s[pos+1]=='.')sum-=1;
      }
      printf("%d\n",sum);
      s[pos]=ch[0];
    }
  }
}
