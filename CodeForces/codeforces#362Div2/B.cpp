/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月15日 星期五 00时42分16秒
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
const int N=200;
char a[N],b[N];

int main(){
  int i;
  while(~scanf("%s",a)){
    int len=strlen(a),n;
    bool flag=0;
    for(i=0;i<len;++i){
      if(a[i]=='.')flag=1;
      if(a[i]=='e')break;
    }
    n=len;
    len=i;
    ++i;
    int B=a[i]-'0';
    //cout<<"B="<<B<<endl;
    //cout<<"i="<<a[i]<<endl;
    for(++i;i<n;++i){
      B*=10;
      B+=a[i]-'0';
    }
    while(flag && len){
      if(a[len-1]=='0')len--;
      else break;
    }
    //cout<<"B="<<B<<endl;
    flag=0;
    int j=0;
    //cout<<"len="<<len<<endl;
    for(i=0;i<len;++i){
      if(a[i]=='.'){
        flag=1;
        ++i;
      }
      if(i>=len)break;
      if(!B && flag)b[j++]='.';
      //printf("%c",a[i]);
      b[j++]=a[i];
      if(flag)B--;
      //cout<<"B="<<B<<endl;
    }
    while(B>0)b[j++]='0',B--;
    b[j]='\0';
    flag=0;
    for(i=0;i<j;++i){
      if(!flag && b[i+1]!='.' && b[i]=='0')continue;
      if(b[i]!='0')flag=1;
      printf("%c",b[i]);
    }
    puts("");
  }
}
