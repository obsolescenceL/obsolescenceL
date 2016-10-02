/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 10/ 2 12:25:36 2016
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
#include<cstring>
using namespace std;
int sum;

int solve(int i,int x) {
  int bit=7-i,xx=x,y=0,cnt=0,b[10],j;
  MEM0(b);
  for (; xx; xx>>=1) b[cnt++]=xx&1;
  int m=cnt;
  //cout<<"m="<<m<<" bit="<<bit<<endl;
  for (j=0; j<MIN(m,bit); ++j) y+=((!b[j])<<j);
  for (j=MIN(m,bit); j<bit; ++j) y+=((!b[j])<<j);
  //for (j=bit; j<m; ++j) y+=(b[j]<<j);
  //for (j=0; j<m; ++j) cout<<b[j]<<" \n"[j==m-1];
  //cout<<"y="<<y<<endl;
  //cout<<"cnt="<<cnt<<endl;
  sum+=(x^y);
  //cout<<"x^y="<<(x^y)<<endl;
  //cout<<"sum="<<sum<<endl;
  return y;
}

int main() {
  int t,n,x,i;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    cin>>n>>x;
    int xx=x;
    //cout<<"n="<<n<<" x="<<x<<endl;
    sum=0;
    //for (i=n-2; i>=0; --i) {
    if (n>2) x=solve(1,x);
    for (i=0; i<n-3; ++i) x=solve(1,x);
    if (n>1) x=solve(0,x);
    //}
    sum+=x;
    int sum1=sum;
    sum=0;
    x=xx;
    //cout<<"--------"<<endl;
    if (n>2) x=solve(0,x);
    for (i=0; i<n-3; ++i) x=solve(0,x);
    if (n>1) x=solve(0,x);
    //cout<<"x="<<x<<endl;
    sum+=x;
    //cout<<"sum="<<sum<<" sum1="<<sum1<<endl;
    sum=MAX(sum,sum1);
    cout<<sum<<endl;
  }
}
