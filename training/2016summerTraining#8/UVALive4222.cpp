/*************************************************************************
     File Name: E.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月01日 星期一 08时50分42秒
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
const int N=1010;
string s[N],ss;
bool f[10];

int main() {
  int n,i;
  ios::sync_with_stdio(0);
  while (getline(cin,ss)) {
    istringstream stream(ss);
    n=0;
    while (stream>>s[n++]) {
      ;
    }
    n--;
    Mem0(f);
    if (s[0]=="jiggle") f[4]=1;
    if (n-3>=0) f[2]=!(s[n-3]=="clap" && s[n-2]=="stomp" && s[n-1]=="clap");
    else f[2]=1;
    f[5]=1;
    for (i=0; i<n; ++i) {
      if (s[i]=="dip") {
        f[5]=0;
        if (i+1<n && s[i+1]=="twirl") continue;
        if (i-1>=0 && s[i-1]=="jiggle") continue;
        if (i-2>=0 && s[i-2]=="jiggle") continue;
        s[i]="DIP";
        f[1]=1;
      }
      if (s[i]=="twirl") f[3]=1;
    }
    for (i=0; i<n; ++i)
      if (s[i]=="hop") f[3]=0;
    int flag=0;
    for (i=1; i<=5; ++i) flag+=f[i];
    cout<<"form ";
    if (flag) cout<<"error";
    else cout<<"ok";
    if (flag>1) cout<<"s";
    for (i=1; i<=5; ++i) {
      if (f[i]) {
        cout<<" "<<i;
        flag--;
        if (flag>1) cout<<',';
        else if (flag) cout<<" and";
      }
    }
    cout<<":";
    for (i=0; i<n; ++i)
      cout<<' '<<s[i];
    cout<<'\n';
  }
}
