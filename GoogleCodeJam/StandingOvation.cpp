/*************************************************************************
     File Name: StandingOvation.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月11日 星期六 23时06分14秒
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
using namespace std;
string s;

int main(){
  int t,i,n;
  ios::sync_with_stdio(0);
  cin>>t;
  for(int nc=1;nc<=t;++nc){
    cin>>n>>s;
    //cout<<s<<endl<<endl;
    int cnt=0,sum=0;
    for(i=0;s[i];++i){
      //cout<<"sum="<<sum<<" i="<<i<<endl;
      if(sum<i) cnt+=i-sum,sum+=i-sum;
      //cout<<"cnt++ ="<<cnt<<endl;
      if(sum>=i)sum+=s[i]-'0';
      //cout<<cnt<<' '<<sum<<endl;
    }
    cout<<"Case #"<<nc<<": "<<cnt<<'\n';
  }
}
