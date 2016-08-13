/*************************************************************************
     File Name: b.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月06日 星期六 20时54分44秒
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
const int N=110;
int message[N];

int main(){
  int n,i,j,x;
  char s[N];
  while(~scanf("%d",&n)){
    //cout<<"n="<<n<<endl;
    Mem0(message);
    for(i=1;i<=n;++i){
      scanf("%s",s);
      for(j=0;j<n;++j)
        message[j+1]+=s[j]-'0';
    }
    int sum=0;
    queue<int> q;
    for(i=1;i<=n;++i){
      scanf("%d",&x);
      //cout<<"x="<<x<<" message["<<i<<"]="<<message[i]<<endl;
      if(x!=message[i])sum++,q.push(i);
    }
    printf("%d\n",sum);
    if(!q.empty())
      printf("%d",q.front()),q.pop();
    else continue;
    while(!q.empty()){
      printf(" %d",q.front());
      q.pop();
    }
    puts("");
  }
}
