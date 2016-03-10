/*************************************************************************
     File Name: UVALive5810.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月14日 星期日 13时44分17秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Min(x,y) ((x)<(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int N=1050,M=110;
bool flag[N][M],bit_pos[N][11],mark[N];
int cnt[N];

bool check(int k,int x){
  int cnt[11];
  Mem0(cnt);
  if(k<10)cnt[k]++;
  else cnt[k/10]++,cnt[k%10]++;
  if(x<10)cnt[x]++;
  else cnt[x/10]++,cnt[x%10]++;
  for(int i=0;i<10;++i)
    if(cnt[i]>1)return 1;
  return 0;
}

void pre(){
  int i,j,k,x;
  for(i=0;i<1024;++i){
    for(k=0;k<10;++k)if(i&(1<<k))bit_pos[i][k]=1,cnt[i]++;
    for(j=1;j<=100;++j){
      if(j<10){
        flag[i][j]=bit_pos[i][j];
        for(k=1;k<=j/2 && !flag[i][j];++k)
          if(k!=j-k && bit_pos[i][k] && bit_pos[i][j-k])flag[i][j]=1;
      }else{
        if(j%10!=j/10)flag[i][j]=bit_pos[i][j%10]&bit_pos[i][j/10];
        for(k=1;k<=j/2 && !flag[i][j];++k){
          x=j-k;
          if(check(k,x))continue;
          if(k<10 && x<10) flag[i][j]=bit_pos[i][k]&bit_pos[i][x];
          else if(k<10) flag[i][j]=bit_pos[i][k]&bit_pos[i][x/10]&bit_pos[i][x%10];
          else if(x<10) flag[i][j]=bit_pos[i][k/10]&bit_pos[i][k%10]&bit_pos[i][x];
          else flag[i][j]=bit_pos[i][k/10]&bit_pos[i][k%10]&bit_pos[i][x/10]&bit_pos[i][x%10];
        }
      }
    }
  }
}

int main(){
  pre();
  int n,i,j,x,nc=0;
  while(~scanf("%d",&n)&&n){
    Mem0(mark);
    for(i=0;i<n;++i){
      scanf("%d",&x);
      for(j=0;j<1024;++j)
        if(!flag[j][x])mark[j]=1;
    }
    int min_cnt=10,status;
    for(i=0;i<1024;++i)
      if(!mark[i] && min_cnt>cnt[i]){
        min_cnt=cnt[i];
        status=i;
      }
    printf("Case %d: ",++nc);
    for(i=9;i>=0;--i)
      if(bit_pos[status][i])printf("%d",i);
    puts("");
  }
}
