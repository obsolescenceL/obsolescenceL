/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  9/23 21:35:32 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
using namespace std;
const int N=200010;
char s[N];

int main() {
  int n,t,i;
  while (cin>>n>>t) {
    cin>>s;
    int pos=n,point=0;
    bool flag=0,f=0;
    for (i=0; i<n; ++i)
      if (s[i]=='.') {
        point=i;
        flag=1;
        break;
      }
    for (++i; i<n; ++i)
      if (s[i]-'0'>=5) break;
    int cnt=0;
    for (; i>point && cnt<t && flag; --i) {
      if (s[i]-'0'>=5) {
        if (s[i-1]!='.') s[i-1]++;
        else if (i-2>=0) s[i-2]++;
        else f=1;
        s[i]='0';
        pos=i;
        cnt++;
      }
    }
    for (i=0; i<n-1; ++i) {
      int x=n-i-1;
      if (s[x]=='9'+1) {
        if (s[x-1]!='.') s[x-1]++;
        else s[x-2]++;
        s[x]='0';
        pos=x;
      }
      if (pos!=-1 && x>pos) s[x]='0';
    }
    while (flag && s[n-1]=='0') n--;
    if (s[n-1]=='.') n--;
    if (pos==-1) {
      for (i=0; i<n; ++i) {
        if (s[i]=='.') break;
        cout<<s[i];
      }
      for (; i<n; ++i) cout<<s[i];
      cout<<endl;
    } else {
      if (f) cout<<'1';
      flag=0;
      if (s[pos-1]=='.') pos--;
      if (s[0]=='9'+1) cout<<"10",i=1;
      else i=0;
      for (; i<n && i<pos; ++i) {
        if (s[i]=='.') flag=1;
        cout<<s[i];
      }
      for (; i<n; ++i) {
        if (s[i]=='.') flag=1;
        if (!flag) cout<<'0';
      }
      cout<<endl;
    }
  }
}
