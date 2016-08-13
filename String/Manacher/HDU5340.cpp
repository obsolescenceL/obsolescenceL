/*************************************************************************
     File Name: HDU5340.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月02日 星期日 15时21分26秒
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
const int N=20010;
char ss[N],s[N<<1];
int p[N<<1];
bool flag[N<<1];

int main(){
  int t,i,n,len,max_id,id;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%s",ss+1);
      for(i=1;ss[i];++i){
        s[i<<1]=ss[i];
        s[i<<1|1]='#';
      }
      s[0]='?',s[1]='#';
      n=(i<<1)+2,s[n]=0;
      len=(i-1)<<1|1;
      max_id=0;
      for(i=1;i<n;++i){
        if(max_id>i)
          p[i]=Min(p[id*2-i],max_id-i);
        else p[i]=1;
        while(s[i+p[i]]==s[i-p[i]])
          p[i]++;
        if(p[i]+i>max_id)
          max_id=p[i]+i,id=i;
      }
      Mem0(flag);
      for(i=0;i<len;++i)
        cout<<"s["<<i<<"]="<<s[i]<<endl;
      for(i=len/2+1+2;i<len;i+=2)//3
        if(i+p[i]-1==len)flag[i]=1;
      for(i=2;i<len/2+1-2;i+=2)//1
        if(i-p[i]+1==0){//2
          if(
          for(j=i+p[i];j<len-2;++j){
            if(j-p[j]
          


        }
    }
  }
}
