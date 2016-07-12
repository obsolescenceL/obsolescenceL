/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  4/11 19:32:52 2016
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
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=1010;
char n[N];
int mark[11],k,len,check,cnt;

bool change(int cur){
  int i,j,x=-1;
  if(cnt==k){
    for(i=0;i<10;++i)
      if(mark[i]){x=i;break;}
    if(x==-1)return 0;
    for(i=cur+1;i<len;++i)n[i]=x+'0';
    n[i]='\0';
    //printf("---n=%s\n",n);
    printf("%s\n",n);
    check=0;
    return 1;
  }else{
    if(cnt<k && k-cnt<=len-cur-1){
      string ans;
      while(cnt<k){
        for(i=0;i<10;++i)
          if(!mark[i]){
            mark[i]++;
            ans+='0'+i;
            break;
          }
        cnt++;
      }
      x=-1;
      for(i=0;i<10;++i)
        if(mark[i]){
          x=i;
          break;
        }
      n[cur+1]='\0';
      printf("%s",n);
      for(i=0;i<len-cur-ans.size()-1;++i)
        printf("%d",x);
      cout<<ans<<endl;
      check=0;
      return 1;
    }
  }
  return 0;
}

int main(){
  int t,i,j;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%s%d",n,&k);
      len=strlen(n);

      if(len<k){
        printf("10");
        for(i=2;i<k;++i)//wa1!!!
          printf("%d",i);
        puts("");
        continue;
      }

      Mem0(mark);
      cnt=0;
      for(i=0;i<len;++i){
        int x=n[i]-'0';
        if(!mark[x])cnt++;
        mark[x]++;
      }

      if(cnt==k){
        printf("%s\n",n);
        continue;
      }

      bool flag=1;
      check=1;
      for(i=len-1;i>=0 && flag;--i){
        int x=n[i]-'0';
        mark[x]--;
        if(!mark[x])cnt--;
        for(j=x+1;j<10;++j){
          mark[j]++;
          if(mark[j]==1)cnt++;
          n[i]=j+'0';
          if(change(i)){flag=0;break;}
          if(mark[j]==1)cnt--;
          mark[j]--;
        }
      }
      //cout<<"check="<<check<<endl;
      if(check){
        printf("1");
        for(i=0;i<len-k+2;++i)
          printf("0");
        for(i=2;i<k;++i)
          printf("%d",i);
        puts("");
      }
    }
  }
}
