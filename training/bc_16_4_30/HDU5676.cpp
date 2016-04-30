/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  4/30 19:07:20 2016
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
const int N=100;
char s[N],ans[N];
int pos4,cnt4,cnt7;

bool solve(int x){
  int i,pos7=-1;
  pos4=-1;
  for(i=x;i>=0;--i)
    if(ans[i]=='4'){
      pos4=i;
      break;
    }
  if(pos4!=-1 && cnt7){
    ans[pos4]='7',cnt4++,cnt7--;
    return 1;
  }else if(pos4!=-1){
    for(i=x;i>=0;--i)
      if(ans[i]=='7'){
        pos7=i;
        break;
      }
    for(;i>=0;--i)
      if(ans[i]=='4'){
        pos4=i;
        break;
      }
    if(pos4!=-1 && pos7!=-1 && pos4<pos7){
      swap(ans[pos4],ans[pos7]);
      return 1;
    }
  }
  return 0;
}

int main(){
  int t,len,i;
  scanf("%d",&t);
  while(t--){
    Mem0(ans);
    scanf("%s",s);
    //cout<<"s="<<s<<endl;
    len=strlen(s);
    if(len%2){
      len++;
      for(i=0;i<len/2;++i)printf("4");
      for(i=0;i<len/2;++i)printf("7");
      puts("");
      continue;
    }
    //cout<<"len="<<len<<endl;
    cnt4=len/2,cnt7=len/2;
    //cout<<"cnt4="<<cnt4<<endl;
    //cout<<"cnt7="<<cnt7<<endl;
    int f=-1;
    for(i=0;i<len;++i)
      if(s[i]<'4'){
        if(cnt4)ans[i]='4',cnt4--;
        else ans[i]='7',cnt7--;
        break;
      }else if(s[i]=='4'){
        if(cnt4)ans[i]='4',cnt4--;
        else{
          ans[i]='7';cnt7--;break;
        }
      }else if(s[i]<'7'){
        if(cnt7)ans[i]='7',cnt7--;
        else f=solve(--i);
        break;
      }else if(s[i]=='7'){
        if(cnt7)ans[i]='7',cnt7--;
        else{
          //cout<<"i="<<i<<endl;
          f=solve(--i);
          break;
        }
      }else{
        //cout<<"i="<<i<<endl;
        f=solve(--i);
        break;
      }
    if(!f){
      len+=2;
      for(i=0;i<len/2;++i)printf("4");
      for(i=0;i<len/2;++i)printf("7");
      puts("");
      continue;
    }
    for(i++;i<len;++i)
      if(cnt4)ans[i]='4',cnt4--;
      else ans[i]='7';
    ans[len]='\0';
    if(f==1)sort(ans+pos4+1,ans+len);
    printf("%s\n",ans);
  }
}
