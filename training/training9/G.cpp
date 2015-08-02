/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月28日 星期二 12时26分51秒
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
#include<sstream>
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
string s,ss;
bool flag_black,flag_blue,flag_w,flag_g;

void check(string str){
  if(str.find("black")!=-1)flag_black=1;
  if(str.find("blue")!=-1)flag_blue=1;
  if(str.find("white")!=-1)flag_w=1;
  if(str.find("gold")!=-1)flag_g=1;
}

int main(){
  int i,n,cnt1,cnt2,cnt3;
  ios::sync_with_stdio(0);
  while(cin>>n){
    getline(cin,s);
    cnt1=cnt2=cnt3=0;
    for(i=0;i<n;++i){
      flag_black=flag_blue=flag_w=flag_g=0;
      getline(cin,s);
      //cout<<"s="<<s<<endl;
      istringstream stream(s);
      while(stream>>ss)
        check(ss);
      //cout<<"black="<<flag_black<<endl;
      if(flag_black && flag_blue)cnt1++;
      else if(flag_w && flag_g)cnt2++;
      else cnt3++;
    }
    double ans1=(double)cnt1/n;
    double ans2=(double)cnt2/n;
    double ans3=(double)cnt3/n;
    printf("%.10lf\n",ans1*100);
    printf("%.10lf\n",ans2*100);
    printf("%.10lf\n",ans3*100);
  }
}
