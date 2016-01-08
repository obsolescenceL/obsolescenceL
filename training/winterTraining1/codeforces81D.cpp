/*************************************************************************
     File Name: codeforces81D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月08日 星期五 14时08分18秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
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
const int N=1010,M=45;
int a[M],b[N];

int main(){
  int n,m,i,j;
  while(~scanf("%d%d",&n,&m)){
    Mem0(a),Mem0(b);
    for(i=1;i<=m;++i){
      scanf("%d",&a[i]);
    }
    if(n==1){puts("1");continue;}
    if(m==1 || (m==2 && n%2)){
      puts("-1");continue;
    }
    //cout<<"----------------"<<endl;
    bool flag=1;
    for(i=1;i<=n;++i){
      int max_a=0;
      for(j=1;j<=m;++j){
        if(a[j] && j!=b[i-1] && (i!=n || j!=b[1])){
          if(a[max_a]<a[j])max_a=j;
          else if(a[max_a]==a[j] && j==b[1])max_a=j;
          //if(a[j]==a[max_a]
          //if(max_a==b[1])max_a=j;
        }
      }
      //cout<<"max_a="<<max_a<<endl;
      if(!max_a){flag=0;puts("-1");break;}
      b[i]=max_a;
      a[max_a]--;
    }
    if(!flag)continue;
    for(i=1;i<n;++i)printf("%d ",b[i]);
    printf("%d\n",b[n]);
  }
}
