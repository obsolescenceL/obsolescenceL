/*************************************************************************
     File Name: HDU1338.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月11日 22:02:11
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int card[55];

int main(){
  int n,m,i,k=1,j,cnt,maxn;
  while(~scanf("%d%d",&m,&n)&&(n||m)){
    for(i=0;i<n;++i)scanf("%d",card+i);
    sort(card,card+n,greater<int>());
    cnt=0,maxn=n*m;
    for(i=0;i<n;++i){
      if(card[i]==maxn){
        cnt++,maxn--;
        //cout<<"maxn="<<maxn<<' '<<"card[i]="<<card[i]<<endl;
      }
      else maxn-=2;
    }
    printf("Case %d: %d\n",k++,cnt);
  }
}
