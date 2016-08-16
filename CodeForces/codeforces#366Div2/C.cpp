/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月07日 星期日 22时04分07秒
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
const int N=300010;
int position[N];
bool flag[N];
vector<int> v[N];

int main() {
  int n,m,op,x,i;
  while (~scanf("%d%d",&n,&m)) {
    int pos=1,unread=0,notes_num=0;
    Mem0(position);
    while (m--) {
      scanf("%d%d",&op,&x);
      if (op==1) {
        notes_num++;
        unread++;
        v[x].pb(notes_num);
      } else if (op==2) {
        for (i=position[x]; i<v[x].size(); ++i)
          if (!flag[v[x][i]])
            unread--,flag[v[x][i]]=1;
        position[x]=v[x].size();
      } else if (op==3) {
        for (; pos<=x; ++pos)
          if (!flag[pos])
            unread--,flag[pos]=1;
      }
      //cout<<"---------"<<endl;
      printf("%d\n",unread);
    }
  }
}
