/*************************************************************************
     File Name: NEU1315.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月28日 星期四 15时07分48秒
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
const int M=262143,N=100010;
struct node{
  int a,b,c;
  node *next;
}*head[M],e[N];
char s[N];
int top;

void insert(int a,int b,int c){
  int k=abs(a+b+c)&M;
  node *p=&e[++top];
  p->a=a,p->b=b,p->c=c,p->next=head[k],head[k]=p;
}

int find(int a,int b,int c){
  int k=abs(a+b+c)&M;
  for(node *p=head[k];p;p=p->next)
    if(p->a==a && p->b==b && p->c==c)
      return 1;
  return 0;
}

int main(){
  int i,len,a,b,c;
  while(~scanf("%s",s)){
    Mem0(head);
    len=strlen(s);
    top=a=b=c=0;
    bool f=0;
    for(i=0;i<len;i++){
      switch(s[i]){
        case 'A':a++;break;
        case 'B':a--;break;
        case 'C':b++;break;
        case 'D':b--;break;
        case 'E':c++;break;
        case 'F':c--;break;
        default:f=1;
      }
      //cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
      if(i==len-1){
        if(!a && !b && !c) break;
        else f=1;
      }
      if(find(a,b,c) ||(!a && !b && !c))
        f=1;
      if(f)break;
      insert(a,b,c);
    }
    if(f) printf("NO\n");
    else printf("YES\n");
  }
}
