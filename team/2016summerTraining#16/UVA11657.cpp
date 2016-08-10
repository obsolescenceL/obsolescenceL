/*************************************************************************
     File Name: G.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月09日 星期二 15时34分26秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define LL long long
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;

int main() {
  int m,n,x1,x2,y1,y2,p,q,abs_p,abs_q,tmp,gcd;
  while (~scanf("%d%d%d%d%d%d%d%d",&m,&n,&x1,&y1,&x2,&y2,&p,&q) && (n||m||x1||x2||y1||y2||p||q)) {
    bool flag=0;
    if (!p || !q) {
      tmp=p*(y2-y1)-q*(x2-x1);
      if (tmp==0) flag=1;
    } else {
      if (p<0) abs_p=-p,p=-1;
      else abs_p=p,p=1;
      if (q<0) abs_q=-q,q=-1;
      else abs_q=q,q=1;
      n*=abs_p,y1*=abs_p,y2*=abs_p;
      m*=abs_q,x1*=abs_q,x2*=abs_q;
      gcd=__gcd(2*n,2*m);
      tmp=q*(y2-y1)-p*(x2-x1);
      //cout<<"tmp="<<tmp<<endl;
      if (tmp%gcd==0) flag=1;
      //cout<<"--------"<<endl;
      tmp=q*(2*n-y2-y1)-p*(x2-x1);
      if (tmp%gcd==0) flag=1;
      tmp=q*(y2-y1)-p*(2*m-x2-x1);
      if (tmp%gcd==0) flag=1;
      tmp=q*(2*n-y2-y1)-p*(2*m-x2-x1);
      if (tmp%gcd==0) flag=1;
    }
    if (flag) puts("HIT");
    else puts("MISS");
  }
}
