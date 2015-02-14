/*************************************************************************
     File Name: ZOJ1409.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月12日 10:00:31
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
using namespace std;
struct Node{
  int w,p;
  bool operator < (const Node& rhs) const {
    return p<rhs.p;
  }
};
int B[10010];
vector<Node> v[110];

int main(){
  int t,n,i,j,k,m,a,b,cnt;
  bool flag;
  double sum,ans;
  scanf("%d",&t);
  while(t--){
    ans=cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;++i){
      v[i].clear();
      scanf("%d",&m);
      while(m--){
        scanf("%d%d",&a,&b);
        v[i].push_back((Node){a,b});
        B[cnt++]=a;
      }
      sort(v[i].begin(),v[i].end());
    }
    sort(B,B+cnt);
    m=0;
    for(i=1;i<cnt;++i)
      if(B[i]!=B[i-1])B[++m]=B[i];
    for(i=0;i<=m;++i){
      for(j=flag=sum=0;j<n && !flag;++j)
        for(k=0;k<v[j].size();++k){
          if(v[j][k].w>=B[i]){
            sum+=(double)v[j][k].p;
            break;
          }
          if(k==v[j].size()-1 && v[j][k].w<B[i])flag=1;
        }
      if(flag)continue;
      ans=max(ans,(double)B[i]*1.0/sum);
    }
    printf("%.3lf\n",ans);
  }
}
