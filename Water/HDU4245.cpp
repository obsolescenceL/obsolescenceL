/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月12日 星期二 15时55分16秒
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
string s1,s2;

int main(){
  ios::sync_with_stdio(0);
  int nc=0;
  while(cin>>s1>>s2){
    cout<<"Case "<<++nc<<": ";
    if(s1=="A#")cout<<"Bb "<<s2;
    else if(s1=="Bb")cout<<"A# "<<s2;
    else if(s1=="C#")cout<<"Db "<<s2;
    else if(s1=="Db")cout<<"C# "<<s2;
    else if(s1=="D#")cout<<"Eb "<<s2;
    else if(s1=="Eb")cout<<"D# "<<s2;
    else if(s1=="F#")cout<<"Gb "<<s2;
    else if(s1=="Gb")cout<<"F# "<<s2;
    else if(s1=="G#")cout<<"Ab "<<s2;
    else if(s1=="Ab")cout<<"G# "<<s2;
    else cout<<"UNIQUE";
    cout<<'\n';
  }
}
