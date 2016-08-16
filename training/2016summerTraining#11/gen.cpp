/*************************************************************************
     File Name: gen.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月04日 星期四 15时58分12秒
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

int main() {
  freopen("gen.txt","w",stdout);
  srand(time(0));
  int t=rand()%10;
  cout<<t<<endl;
  while(t--){
    int n=rand()%16;
    cout<<n<<endl;
    for (int i=0; i<n; ++i) {
      int x=(rand()%n)+1;
      cout<<x<<' ';
    }
    int m=rand()%16;
    cout<<m<<endl;
    for (int i=0; i<m; ++i) {
      int x=rand()%n;
      x++;
      cout<<x<<' ';
      //cout<<"----------"<<endl;
      int y=rand()%x;
      y++;
      cout<<y<<endl;
    }
  }
}
