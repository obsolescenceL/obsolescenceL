/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月31日 星期日 11时59分43秒
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

int main(){
  ios::sync_with_stdio(0);
  int n,a,b,c;
  while (cin>>n>>a>>b>>c) {
    if (!n && !a && !b && !c) break;
    double a1=0,a2=0,b1=0,b2=0,c1=0,c2=0,t1=0,t2=0;
    if (a) {
      a1=(double)a-0.5;
      a2=(double)a+0.5;
    }
    if (b) {
      b1=(double)b-0.5;
      b2=(double)b+0.5;
    }
    if (c) {
      c1=(double)c-0.5;
      c2=(double)c+0.5;
    }
    t1=a1*9.0+b1*4.0+c1*4.0;
    t2=a2*9.0+b2*4.0+c2*4.0;
    //cout<<"t1="<<t1<<" t2="<<t2<<endl;
    if (n>=t1 && n<t2) cout<<"yes\n";
    else cout<<"no\n";
  }
}
