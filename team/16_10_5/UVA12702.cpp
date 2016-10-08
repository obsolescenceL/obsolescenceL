/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三 10/ 5 14:18:55 2016
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
#include<cstring>
#include<algorithm>
using namespace std;
const int N=110;
int mp1[N][N],mp2[N][N],mp3[N][N];
int n,m,r,c;

void solve(int x,int y,int center_r,int center_c) {
  //cout<<"x="<<x<<" y="<<y<<" center_r="<<center_r<<" center_c="<<center_c<<endl;
  x-=center_r;
  y-=center_c;
  for (int i=0; i<r; ++i)
    for (int j=0; j<c; ++j) {
      mp3[i+x][j+y]|=mp2[i][j];
    }
}

int main() {
  int t,i,j;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    cout<<"Case "<<nc<<":\n";
    cin>>n>>m;
    for (i=0; i<n; ++i)
      for (j=0; j<m; ++j) {
        cin>>mp1[i][j];
        mp3[i][j]=mp1[i][j];
      }
    cin>>r>>c;
    for (i=0; i<r; ++i)
      for (j=0; j<c; ++j)
        cin>>mp2[i][j];
    int center_r=r/2,center_c=c/2;
    for (i=center_r; i<n-r+center_r+1; ++i)
      for (j=center_c; j<m-c+center_c+1; ++j)
        if (mp1[i][j])
          solve(i,j,center_r,center_c);
    for (i=0; i<n; ++i)
      for (j=0; j<m; ++j)
        cout<<mp3[i][j]<<" \n"[j==m-1];
  }
}
