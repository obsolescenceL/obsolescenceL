/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三 10/ 5 13:16:06 2016
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
#include<map>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
map<char,int> mp;
vector<char> v;
int num[]={2,3,4,5,6,7,3,4,5,6,7,8,4,5,6,7,8,9,5,6,7,8,9,10,6,7,8,9,10,11,7,8,9,10,11,12};
const int N=50;
int cnt[N];

int main() {
  int t,i;
  string s;
  sort(num,num+36);
  cin>>t;
  getline(cin,s);
  for (int nc=1; nc<=t; ++nc) {
    v.clear();
    mp.clear();
    mp[' ']=0;
    getline(cin,s);
    for (i=0; i<s.size(); ++i) {
      if (!mp.count(s[i])) v.pb(s[i]);
      mp[s[i]]++;
    }
    for (i=0; i<v.size(); ++i)
      cnt[i]=mp[v[i]];
    sort(cnt,cnt+v.size(),greater<int>());
    int ans=0;
    for (i=0; i<v.size(); ++i) {
      ans+=cnt[i]*num[i];
      //cout<<cnt[i]*num[i]<<"--------"<<endl;
    }
    cout<<ans<<endl;
  }
}
