/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月18日 星期一 11时58分21秒
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
const int N=110;
int dp[N][N];
char a[N],b[N];
bool vis_b[N];

int main(){
  int n,m,i,j,k;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n+1;++i)
      for(j=0;j<m+1;++j)
        scanf("%d",&dp[i][j]);
    for(i=0;i<n;++i)a[i]='a'+i;
    a[n]='\0';
    b[m]='\0';
    Mem0(vis_b);
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j)
        if(dp[i][j]==dp[i-1][j-1]+1 && dp[i][j]!=Max(dp[i-1][j],dp[i][j-1])){
          if(!vis_b[j]){
            b[j-1]=a[i-1];
            vis_b[j]=1;
          }else{
            for(k=0;k<m;++k)
              if(b[k]==a[i-1])
                b[k]=b[j-1];
            for(k=0;k<n;++k)
              if(a[k]==a[i-1] && k!=i-1)
                a[k]=b[j-1];
            a[i-1]=b[j-1];
          }
        }else if(a[i-1]==b[j-1]){
          if(!vis_b[j])b[j-1]++;
        }
    bool flag[26];
    Mem0(flag);
    for(i=0;i<n;++i)
      flag[a[i]-'a']=1;
    int tmp=25;
    for(i=0;i<26;++i)
      if(!flag[i]){
        tmp=i;
        break;
      }
    //cout<<"tmp="<<tmp<<endl;
    for(i=1;i<=m;++i)
      if(!vis_b[i])b[i-1]='a'+tmp;
    printf("%s\n%s\n",a,b);
  }
}
