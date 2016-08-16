/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月22日 星期五 15时12分08秒
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
int ans[]={0,1,2,4,8,16,23,46,29,58,116,223,446,289,578,1156,1223,2446,2489,4789,5789,11578,12356,12247,24449},ans1[]={48889,77789,155578,111356,122227,244445};

int main(){
  int n;
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  while(~scanf("%d",&n)){
    if(n<25)printf("%d\n",ans[n]);
    else printf("%d\n",ans1[(n-25)%6]);
  }
}
