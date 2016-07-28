/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月28日 星期四 13时14分02秒
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
const int N=20010;
struct node{
  string s;
  int ord;
  bool operator < (const node &rhs) const {
    return ord < rhs.ord;
  }
}str[N];
map<string,int> my_map;
int cnt[N];

int main() {
  int n,i,j;
  ios::sync_with_stdio(0);
  while (cin>>n) {
    int top=0;
    Mem0(cnt);
    for (i=0; i<n; ++i) {
      cin>>str[i].s;
      for (j=0; str[i].s[j]; ++j)
        if (str[i].s[j]=='@') break;
      string tmp="",tmp1="bmail.com",tmp2="";
      for (++j; str[i].s[j]; ++j) {
        if (str[i].s[j]>='A' && str[i].s[j]<='Z') tmp+=str[i].s[j]-'A'+'a';
        else tmp+=str[i].s[j];
      }
      //cout<<"tmp="<<tmp<<endl;
      bool flag=0;
      if (tmp==tmp1) flag=1;
      for (j=0; str[i].s[j]; ++j) {
        if (str[i].s[j]=='@') {
          tmp2+=str[i].s[j];
          break;
        }
        if (str[i].s[j]=='.' && flag) continue;
        if (str[i].s[j]=='+' && flag) {
          while (str[i].s[j+1]!='@') ++j;
        } else if (str[i].s[j]>='A' && str[i].s[j]<='Z') {
          tmp2+=str[i].s[j]-'A'+'a';
        } else tmp2+=str[i].s[j];
      }
      tmp2+=tmp;
      if (!my_map[tmp2]) {
        my_map[tmp2]=++top;
      }
      //cout<<"tmp2="<<tmp2<<endl;
      cnt[my_map[tmp2]]++;
      str[i].ord=my_map[tmp2];
    }
    cout<<top<<'\n';
    sort(str,str+n);
    for (i=0; i<n;) {
      int tmp=cnt[str[i].ord];
      cout<<tmp;
      while (tmp--) {
        cout<<' '<<str[i].s;
        ++i;
      }
      cout<<'\n';
    }
  }
}
