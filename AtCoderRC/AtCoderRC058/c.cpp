/*************************************************************************
     File Name: c.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月23日 星期六 20时21分57秒
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
const int N=20;
bool flag[N];

int main(){
  int k,i,x,j;
  char n[N],s[N];
  while(~scanf("%s%d",n,&k)){
    Mem0(flag);
    for(i=0;i<k;++i){
      scanf("%d",&x);
      flag[x]=1;
    }
    int len=strlen(n),f1=0,f2=0;
    for(i=0;i<len;++i){
      if(f2){
        for(j=0;j<=9;++j){
          if(flag[j]==0 && j>n[i]-'0'){
            s[i]='0'+j;
            n[i]=s[i];
            break;
          }
        }
        if(j==10){
          if(!i){ f1=1; break; }
          i-=2,f2=1;
          continue;
        }else{
          f2=i;
          break;
        }
      }
      if(flag[n[i]-'0']){
        for(j=0;j<=9;++j){
          if(flag[j]==0 && j>n[i]-'0'){
            s[i]='0'+j;
            n[i]=s[i];
            break;
          }
        }
        //cout<<"i="<<i<<" f1="<<f1<<endl;
        if(j==10){
          if(!i){ f1=1; break; }
          f2=1,i-=2;
          continue;
        }else{
          f2=i;
          break;
        }
      }else s[i]=n[i];
    }
    //cout<<"f1="<<f1<<endl;
    if(f1){
      //cout<<"--------"<<endl;
      for(i=1;i<=9;++i)
        if(flag[i]==0){
          printf("%d",i);
          break;
        }
      for(i=0;i<=9;++i)
        if(flag[i]==0){
          while(len--)printf("%d",i);
          break;
        }
    }else{
      if(i==len)printf("%s",n);
      else{
        for(i=0;i<=f2;++i)
          printf("%c",s[i]);
        for(j=0;j<=9;++j)
          if(flag[j]==0){
            for(;i<len;++i)
              printf("%d",j);
            break;
          }
      }
    }
    puts("");
  }
}
