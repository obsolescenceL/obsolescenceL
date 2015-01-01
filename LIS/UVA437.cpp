/*************************************************************************
    > File Name: UVA437.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 1日 14:00:50
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=200;
struct brick{
  int x,y,z;
}b[MAXN];
int sum[MAXN];
bool cmp(brick a,brick b){
  if(a.x==b.x)return a.y<b.y;
  return a.x<b.y;
}
int main(){
  int n,i,j,x,y,z,k=0;
  while(~scanf("%d",&n)&&n){
    int len=0;
    while(n--){
      scanf("%d%d%d",&x,&y,&z);
      b[len].x=x,b[len].y=y,b[len++].z=z;
      b[len].x=x,b[len].y=z,b[len++].z=y;
      b[len].x=y,b[len].y=x,b[len++].z=z;
      b[len].x=y,b[len].y=z,b[len++].z=x;
      b[len].x=z,b[len].y=x,b[len++].z=y;
      b[len].x=z,b[len].y=y,b[len++].z=x;
    }
    sort(b,b+len,cmp);
    int max_len=0;
    for(i=0;i<len;i++)sum[i]=b[i].z;
    for(i=0;i<len;i++){
      for(j=0;j<i;j++)
        if(b[j].x<b[i].x && b[j].y<b[i].y)
          sum[i]=max(sum[i],sum[j]+b[i].z);
      max_len=max(max_len,sum[i]);
    }
    printf("Case %d:maximum height = %d\n",++k,max_len);
  }
}
