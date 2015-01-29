/*************************************************************************
     File Name: HDU2037.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月29日 15:52:46
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using std::sort;
const int MAXN=110;
struct Pro{
  int start,end;
  bool operator < (const Pro& rhs)const{
    return end<rhs.end;
  }
}pro[MAXN];


int main(){
  int i,n,cnt,k;
  while(~scanf("%d",&n)&&n){
    for(i=0;i<n;++i)
      scanf("%d%d",&pro[i].start,&pro[i].end);
    sort(pro,pro+n);
    cnt=1;
    for(i=1,k=0;i<n;++i){
      //printf("pro[%d].start=%d,pro[%d].end=%d\n",i,pro[i].start,i-1,pro[i-1].end);
      if(pro[i].start>=pro[k].end)k=i,cnt++;
    }
    printf("%d\n",cnt);
  }
}
