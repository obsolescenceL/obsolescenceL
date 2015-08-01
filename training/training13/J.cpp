/*************************************************************************
     File Name: J.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月31日 星期五 14时08分44秒
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
struct node{
  string name1,name2;
  int price,cnt;
  bool operator < (const node& rhs) const {
    return cnt>rhs.cnt || (cnt==rhs.cnt && price<rhs.price);
  }
}fri[10];
map<string,int> cnt;

int main(){
  ios::sync_with_stdio(0);
  while(cin>>fri[1].name1>>fri[1].name2>>fri[1].price){
    cnt.clear();
    cnt[fri[1].name2]++;
    for(int i=2;i<=6;++i){
      cin>>fri[i].name1>>fri[i].name2>>fri[i].price;
      cnt[fri[i].name2]++;
    }
    for(int i=1;i<=6;++i)
      fri[i].cnt=cnt[fri[i].name2];
    sort(fri+1,fri+1+6);
    cout<<fri[1].name2<<endl;
  }
}
