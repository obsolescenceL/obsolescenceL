/*************************************************************************
     File Name: F.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月10日 星期三 13时14分07秒
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
const int N=110;
string s[N][4];
bool vis[N];
struct Node{
  string str;
  int step;
  Node(string _str,int _step):str(_str),step(_step){};
}str("",0);
vector<string> v[N];
set<string> my_set;

int main() {
  int t,n,i;
  ios::sync_with_stdio(0);
  while (cin>>t) {
    while (t--) {
      cin>>n;
      MEM0(vis);
      my_set.clear();
      queue<Node> q;
      for (i=0; i<n; ++i) {
        v[i].clear();
        cin>>s[i][0]>>s[i][1]>>s[i][2];
        if (s[i][0]=="Ahmad") {
          q.push(Node(s[i][1],1));
          q.push(Node(s[i][2],1));
          vis[i]=1;
        }
        if (s[i][1]=="Ahmad") {
          q.push(Node(s[i][0],1));
          q.push(Node(s[i][2],1));
          vis[i]=1;
        }
        if (s[i][2]=="Ahmad") {
          q.push(Node(s[i][0],1));
          q.push(Node(s[i][1],1));
          vis[i]=1;
        }
      }
      int m=0,cnt=0;
      while (!q.empty()) {
        str=q.front();
        q.pop();
        if (my_set.count(str.str))
          continue;
        else my_set.insert(str.str),cnt++;
        v[str.step].pb(str.str);
        m=MAX(m,str.step);
        for (i=0; i<n; ++i) {
          if (vis[i]) continue;
          if (s[i][0]==str.str) {
            q.push(Node(s[i][1],str.step+1));
            q.push(Node(s[i][2],str.step+1));
            vis[i]=1;
          }
          if (s[i][1]==str.str) {
            q.push(Node(s[i][0],str.step+1));
            q.push(Node(s[i][2],str.step+1));
            vis[i]=1;
          }
          if (s[i][2]==str.str) {
            q.push(Node(s[i][0],str.step+1));
            q.push(Node(s[i][1],str.step+1));
            vis[i]=1;
          }
        }
      }
      for (i=0; i<n; ++i) {
        if (vis[i]) continue;
        if (!my_set.count(s[i][0])) {
          v[0].pb(s[i][0]);
          cnt++;
          my_set.insert(s[i][0]);
        }
        if (!my_set.count(s[i][1])) {
          v[0].pb(s[i][1]);
          cnt++;
          my_set.insert(s[i][1]);
        }
        if (!my_set.count(s[i][2])) {
          v[0].pb(s[i][2]);
          cnt++;
          my_set.insert(s[i][2]);
        }
        sort(v[0].begin(),v[0].end());
      }
      cout<<cnt+1<<"\nAhmad 0\n";
      for (i=1; i<=m; ++i) {
        sort(v[i].begin(),v[i].end());
        EACH(it,v[i])
          cout<<*it<<' '<<i<<'\n';
      }
      EACH(it,v[0])
        cout<<*it<<" undefined\n";
    }
  }
}
