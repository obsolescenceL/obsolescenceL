/*************************************************************************
     File Name: UESTC1069.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月23日 星期六 23时20分20秒
 ************************************************************************/
#include<cstdio>
#include<stack>
#define Max(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int N=200010;
struct node{
  int h,w;
  node(int _h=0,int _w=0):h(_h),w(_w){}
}post[N];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    stack<node> s;
    for(i=1;i<=n;++i)scanf("%d%d",&post[i].w,&post[i].h);
    int ans=0;
    for(i=1;i<=n;++i){
      int tot_w=0;
      while(!s.empty() && s.top().h>post[i].h){
        tot_w+=s.top().w;
        ans=Max(ans,s.top().h*tot_w);
        s.pop();
      }
      s.push(node(post[i].h,post[i].w+tot_w));
    }
    while(!s.empty()){
        ans=Max(ans,s.top().h*s.top().w);
        int temp=s.top().w;
        s.pop();
        if(!s.empty())s.top().w+=temp;
    }
    printf("%d\n",ans);
  }
}
