/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月03日 星期三 11时54分46秒
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
#define ll unsigned long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=100,M=262143,NN=100010;
struct node{
  ll to;
  int r,c,len;
  node *next;
}*head[M],e[NN];
int top,r1,r2,c1,c2,mark;
char s[N];
ll seed=31;

void Addedge(ll hash,int r,int c,int len){
  int from=hash&M;
  node *p=&e[++top];
  p->to=hash,p->c=c,p->r=r,p->len=len,p->next=head[from],head[from]=p;
}

bool find(ll hash,int c,int len){
  int from=hash&M;
  for(node *p=head[from];p;p=p->next)
    if(p->to==hash && p->c==c && p->len==len){
      if(mark==2 || (mark==1 && p->r==r1)){
        r1=p->r;
        return 0;
      }
    }
  return 1;
}

int main(){
  int n,m,i,j,k,l,len;
  while(~scanf("%d%d",&n,&m)){
    getchar();
    Mem0(head),top=0;
    bool flag=1;
    for(i=1;i<=n;++i){
      gets(s);len=strlen(s);
      s[len++]=',',s[len]='\0';
      //cout<<"s="<<s<<endl;
      mark=2;
      ll hash=0;
      for(j=l=0,k=1;j<len && flag;++j,++l)
        if(s[j]==','){
          //cout<<"l="<<l<<endl;
          //cout<<"hash="<<hash<<endl;
          if(find(hash,k,l))Addedge(hash,i,k,l);
          else{
            if(mark==2)c1=k;
            if(mark==1)c2=k,r2=i,flag=0;
            mark--;
          }
          hash=0,k++,l=0;
        }else hash=hash*seed+s[j];
    }
    if(flag)puts("YES");
    else printf("NO\n%d %d\n%d %d\n",r1,r2,c1,c2);
  }
}
