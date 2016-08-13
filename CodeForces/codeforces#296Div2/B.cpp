/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月18日 星期三 01时28分04秒
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
using namespace std;
const int N=200010;
char s[N],t[N];
int pos[N];

int main(){
  int n,i,j,x,y;
  while(~scanf("%d",&n)){
    scanf("%s%s",s,t);
    int cnt=0;
    for(i=0;i<n;++i)
      if(s[i]!=t[i]){
        pos[cnt++]=i;
      }
    //cout<<pos[0]<<endl;
    bool flag=1,is_ok=1;
    int m=cnt;
    for(i=0;i<m&&is_ok;++i){
      for(j=i+1;j<m;++j){
        if(s[pos[i]]==t[pos[j]]&&s[pos[j]]==t[pos[i]]){
          cnt-=2,x=pos[i],y=pos[j];
          flag=0;
          is_ok=0;
          break;
        }else if((s[pos[j]]==t[pos[i]]||s[pos[i]]==t[pos[j]])&&flag){
          flag=0;
          x=pos[i],y=pos[j];
        }
      }
    }
    if(is_ok&&!flag)cnt--;
    printf("%d\n",cnt);
    if(flag)puts("-1 -1");
    else printf("%d %d\n",x+1,y+1);
  }
}
