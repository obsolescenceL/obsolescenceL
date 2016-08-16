/*************************************************************************
     File Name: H.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月24日 星期日 13时41分18秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=200010;
int a[N],tmp[N];
struct node{
  int op,c;
}q[N];

int main(){
  int n,m,i,op,x,j;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i){
      scanf("%d",a+i);
      tmp[i]=a[i];
    }
    int t=0;
    for(i=0;i<m;++i){
      scanf("%d%d",&op,&x);
      while(t && x>=q[t-1].c)t--;
      q[t].op=op,q[t++].c=x;
    }
    q[t++].c=0;
    m=t;
    sort(tmp,tmp+q[0].c);
    int pos1=0,pos2=q[0].c-1;
    for(i=0;i<m-1;++i)
      for(j=q[i].c-1;j>=q[i+1].c;--j){
        if(q[i].op==1)a[j]=tmp[pos2--];
        else a[j]=tmp[pos1++];
      }
    for(i=0;i<n;++i)
      printf("%d%c",a[i],i!=n-1?' ':'\n');
  }
}
