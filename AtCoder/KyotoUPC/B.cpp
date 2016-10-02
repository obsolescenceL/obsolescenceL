/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 10/ 2 13:48:09 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<algorithm>
#include<set>
#include<string>

using namespace std;
const int N=1e4+10;
set<string> my_set;
string ss[N];
int cnt[30];

int main() {
  int n,nn,k,i,j;
  string s;
  cin>>n>>k;
  for (i=j=0; i<n; ++i) {
    cin>>s;
    if (!my_set.count(s)) {
      my_set.insert(s);
      ss[j++]=s;
    }
  }
  n=j;
  for (i=0; i<n; ++i)
    cnt[ss[i][0]-'A']++;
  //cout<<"n="<<n<<endl;
  sort(cnt,cnt+26,greater<int>());
  int low=0,high=n/k,mid,ans;
  while (low<=high) {
    mid=(low+high)>>1;
    //cout<<"----mid="<<mid<<endl;
    int tmp=0,pre=0;
    for (i=0; i<26 && tmp<k; ++i) {
      if (cnt[i]+pre>=mid)
        tmp++,pre=MIN(mid,cnt[i])+pre-mid;
      else pre+=cnt[i];
      //cout<<"tmp="<<tmp<<endl;
    }
    if (tmp>=k) low=mid+1,ans=mid;
    else high=mid-1;
  }
  cout<<ans<<endl;
}
