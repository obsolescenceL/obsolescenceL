/*************************************************************************
     File Name: UESTC1061_baoli.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月25日 星期一 21时54分16秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Mem0(x) memset(x,0,sizeof(x))
const int N=100001;
bool flag[N];

int main(){
  int n,m,op,x,i,ans;
  while(~scanf("%d%d",&n,&m)){
    Mem0(flag);
    flag[0]=1,flag[n+1]=1;
    while(m--){
      scanf("%d%d",&op,&x);
      if(!op)flag[x]=1;
      else if(op==1)flag[x]=0;
      else{
        if(flag[x]){
          puts("0");
          continue;
        }
        ans=0;
        for(i=x;!flag[i];++i)
          ans++;
        for(i=x-1;!flag[i];--i)
          ans++;
        printf("%d\n",ans);
      }
    }
  }
}
