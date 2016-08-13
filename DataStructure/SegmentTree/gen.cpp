/*************************************************************************
     File Name: gen.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月16日 星期四 21时48分34秒
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <ctime>
 
 
int gen_num(int maxn){
  return rand()%maxn + 1;
}
 
void test_case(){
  int n, k;
  n = gen_num(8);
  k = gen_num(n);
  printf("%d\n%d\n", n, k);
  int i, j;
  int l=1,r=0;
  for(i = 0; i < k; ++i){
    do{
      l=gen_num(n);
      r=gen_num(n);
    }while(l>r);
    printf("%d %d %d\n", l, r, gen_num(3) );
  }
  puts("");
  puts("");
 
}
int main(){
  freopen("in.txt","w",stdout);
  srand(time(NULL));

  int T = 100;

  while (T--) test_case();
}
