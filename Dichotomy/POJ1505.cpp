/*************************************************************************
     File Name: POJ1505.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月05日 星期日 22时17分22秒
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
using namespace std;
const int N=501;
vector<int> v[N];
int num[N];

int main(){
  int t,n,k,i,j,sum,max_n,cnt,temp;
  scanf("%d",&t);
  while(t--){
    memset(v,0,sizeof v);
    scanf("%d%d",&n,&k);
    sum=max_n=0;
    for(i=0;i<n;++i){
      scanf("%d",num+i);
      max_n=Max(max_n,num[i]);
      sum+=num[i];
    }
    int low=max_n,high=sum,ans=0,mid;
    while(low<=high){
      mid=(low+high)>>1;
      cnt=temp=0;
      for(i=n-1;i>=0;){
        if(temp+num[i]>mid){
          temp=0;
          cnt++;
          continue;
        }
        temp+=num[i];
        if(!i&&temp<=mid)cnt++;
        i--;
      }
      if(cnt<=k)high=mid-1,ans=mid;
      else low=mid+1;
    }
    sum=temp=cnt=0;
    for(i=k-1;i<n;++i)sum+=num[i];
    sum=Min(sum,ans);
    for(i=n-1;i>=0;){
      if(temp+num[i]>sum){
        cnt++;
        temp=0,sum=0;
        for(j=k-1-cnt;j<=i;++j)sum+=num[j];
        sum=Min(sum,ans);
        continue;
      }
      temp+=num[i];
      v[cnt].push_back(num[i--]);
    }
    for(i=cnt;i>=0;--i){
      if(i!=cnt)printf(" ");
      for(j=v[i].size()-1;j>=0;--j)
        printf("%d ",v[i][j]);
      if(i)printf("/");
    }
    puts("");
  }
}
