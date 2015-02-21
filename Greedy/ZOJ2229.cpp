/*************************************************************************
     File Name: ZOJ2229.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月12日 12:21:11
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
const int INF=0x3F3F3F3F;
using namespace std;

int main(){
  int n,v,t,i;
  while(~scanf("%d",&n)&&n){
    double arrive,minn=INF;
    //cout<<n<<endl;
    for(i=0;i<n;++i){
      scanf("%d%d",&v,&t);
      if(t>=0 && (arrive=t+4500*3.6/v)<minn)
        minn=arrive;
      //cout<<arrive[i]<<endl;
    }
    printf("%.0lf\n",ceil(minn));
  }
}
