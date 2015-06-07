/*************************************************************************
     File Name: e.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月07日 星期日 09时44分17秒
 ************************************************************************/
#include<cstdio>
const int N=100001;
int num[N];

int main(){
  int n,x,i;
  while(~scanf("%d",&n)){
    if(n==1){
      scanf("%d",&x);
      if(x)puts("NO");
      else puts("YES\n0");
      continue;
    }
    for(i=1;i<=n;++i)scanf("%d",num+i);
    if(num[n]){puts("NO");continue;}
    if(num[n-1]){
      puts("YES");
      for(i=1;i<n;++i)
        printf("%d->",num[i]);
      printf("%d\n",num[n]);
    }else{
      int sum=0,pos,cnt=0;
      for(i=1;i<n-1;++i)sum+=num[i];
      if(sum==n-2)puts("NO");
      else{
        puts("YES");
        for(i=n-2;i;--i)
          if(!num[i]){pos=i;break;}
        for(i=1;i<pos;++i)
          printf("%d->",num[i]);
        for(i=pos;i<n-1;++i)
          printf("(%d->",num[i]),cnt++;
        printf("%d",num[n-1]);
        while(cnt--)printf(")");
        puts("->0");
      }
    }
  }
}
