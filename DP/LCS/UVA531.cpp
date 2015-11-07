/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五 11/ 6 21:56:46 2015
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
string s1[N],s2[N];
int dp[N][N];
bool first;

void print_lcs(int i,int j){
  if(!i || !j)return;
  if(s1[i]==s2[j]){
    print_lcs(i-1,j-1);
    if(first)cout<<s1[i];
    else cout<<' '<<s1[i];
    first=0;
  }else if(dp[i-1][j]>dp[i][j-1])
    print_lcs(i-1,j);
  else print_lcs(i,j-1);
}

int main(){
  ios::sync_with_stdio(0);
  while(cin>>s1[1]){
    //cout<<"s1[1]="<<s1[1]<<endl;
    int n=1,m=0,i,j;
    Mem0(dp);
    first=1;
    if(s1[n][0]!='#')
      while(cin>>s1[++n] && s1[n][0]!='#');
    //cout<<"n="<<n<<endl;
        //cout<<"s1["<<n<<"]="<<s1[n]<<endl;
    while(cin>>s2[++m] && s2[m][0]!='#');
    //cout<<"m="<<m<<endl;
    n--,m--;
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j){
        //cout<<"s1["<<i<<"]="<<s1[i]<<" s2["<<j<<"]="<<s2[j]<<endl;
        if(s1[i]==s2[j]){
          dp[i][j]=dp[i-1][j-1]+1;
          //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        }else if(dp[i-1][j]>dp[i][j-1]){
          dp[i][j]=dp[i-1][j];
        }else{
          dp[i][j]=dp[i][j-1];
        }
      }
    print_lcs(n,m);
    cout<<'\n';
  }
}
