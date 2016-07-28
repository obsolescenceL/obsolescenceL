/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月23日 星期六 11时37分24秒
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
const int N=1e5+10;
int a[N];

int main(){
  int n,i,k;
  while(~scanf("%d",&n)){
    i=0;
    while(i<n){
      int maxn=0,j=i;
      for(;i<n;++i){
        scanf("%d",a+i);
        if(!a[i])break;
        maxn=Max(maxn,a[i]);
      }
      //cout<<"i="<<i<<endl;
      ++i;
      queue<int> q;
      stack<int> s;
      deque<int> d;
      int cnt=0;
      for(k=j;k<i-1;++k){
        if(a[k]==maxn && q.empty()){
          q.push(a[k]);
          puts("pushQueue");
          cnt++;
        }else{
          if(s.empty()){
            s.push(a[k]);
            puts("pushStack");
            cnt++;
          }else if(d.empty()){
            d.push_front(a[k]);
            puts("pushFront");
            cnt++;
          }else if(s.top()<=d.front()){
            if(a[k]<s.top()){
              d.push_back(a[k]);
              puts("pushBack");
            }else{
              s.push(a[k]);
              puts("pushStack");
            }
          }else{
            if(a[k]<d.front()){
              d.push_back(a[k]);
              puts("pushBack");
            }else{
              d.push_front(a[k]);
              puts("pushFront");
            }
          }
        }
      }
      //cout<<"a["<<k<<"]="<<a[k]<<endl;
      if(k<n && !a[k]){
        printf("%d",cnt);
        if(!s.empty())printf(" popStack");
        if(!q.empty())printf(" popQueue");
        if(!d.empty())printf(" popFront");
        puts("");
      }
    }
  }
}
