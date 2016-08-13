/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月24日 星期日 16时04分00秒
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
const int N=10010;
int st[N],top;
bool mark[N],cur[N];
char a[N];

int main(){
  int i;
  while(~scanf("%s",a)){
    int len=strlen(a);
    top=0,Mem0(mark);
    for(i=0;i<len;++i){
      if(a[i]=='('){
        st[top++]=i;
        cur[top-1]=0;
      }else if(a[i]=='+'){
        if(top)cur[top-1]=1;
      }else if(a[i]==')'){
        if(!(cur[top-1] && (st[top-1]-1>=0 && a[st[top-1]-1]!='+' && a[st[top-1]-1]!='(' || i+1<len && a[i+1]!='+' && a[i+1]!=')'))){
          if(st[top-1]-1>=0 && a[st[top-1]-1]=='(' && i+1<len && a[i+1]==')')
            cur[top-2] = cur[top-1];
          mark[st[top-1]]=mark[i]=1;
        }
        --top;
      }
    }
    for(i=0;i<len;++i)
      if(!mark[i])putchar(a[i]);
    puts("");
  }
}
