/*************************************************************************
     File Name: POJ3280.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月11日 星期六 20时03分40秒
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
const int N=2010;
int w[30],dp[N][N];
char s[N];

int main(){
  int n,m,i,j,k,w1,w2;
  char ch;
  while(~scanf("%d%d",&n,&m)){
    //cout<<"n="<<n<<" m="<<m<<endl;
    scanf("%s",s);
    //cout<<"s="<<s<<endl;
    getchar();
    while(n--){
      scanf("%c%d%d",&ch,&w1,&w2);
      getchar();
      //cout<<"ch="<<ch<<" w1="<<w1<<" w2="<<w2<<endl;
      w[ch-'a']=Min(w1,w2);
    }
    for(i=m-1;i+1;--i)
      for(j=i+1;j<m;++j){
        if(s[i]==s[j])dp[i][j]=dp[i+1][j-1];
        else dp[i][j]=Min(dp[i+1][j]+w[s[i]-'a'],dp[i][j-1]+w[s[j]-'a']);
      }
    printf("%d\n",dp[0][m-1]);
  }
}
