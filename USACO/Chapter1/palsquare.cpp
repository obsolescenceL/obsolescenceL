/*************************************************************************
     File Name: palsquare.cpp
     ID: obsoles1
     PROG: palsquare
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月22日 10:16:26
 ************************************************************************/
#include<fstream>  
using namespace std;  
const char code[]="0123456789ABCDEFGHIJ";
int m1,m2,b,c,s[100],ss[100];
  
int Transform(int n,int nn){
  m1=m2=0;
  while(nn) c=nn%b,nn/=b,ss[m1++]=c;
  while(n) c=n%b,n/=b,s[m2++]=c;
}

bool check(){
  bool flag=1;
  for(int i=0;i<m1/2;i++)
    if(ss[i]!=ss[m1-1-i])flag=0;
  return flag;
}

int main(){  
  ofstream fout("palsquare.out");
  ifstream fin("palsquare.in");
  int i,j;
  while(fin>>b){
    for(i=1;i<=300;i++){
      Transform(i,i*i);
      if(check()){
        for(j=m2-1;j>=0;j--) fout<<code[s[j]];
        fout<<' ';
        for(j=0;j<m1;j++) fout<<code[ss[j]];
        fout<<endl;
      }
    }
  }
