/*************************************************************************
    > File Name: HDU1023.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月15日 14:45:46
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=200;
int n;
struct bign{
  int len,s[MAXN];

  bign(){
    memset(s,0,sizeof s);
    len=1;
  }
  
  bign(int num){
    *this=num;
  }

  bign(const char* num){
    *this=num;
  }

  bign operator = (int num){
    char s[MAXN];
    sprintf(s,"%d",num);
    *this=s;
    return *this;
  }

  bign operator = (const char* num){
    len=strlen(num);
    for(int i=0;i<len;i++)s[i]=num[len-i-1]-'0';
    return *this;
  }

  string str()const{
    string res="";
    for(int i=0;i<len;i++)res=(char)(s[i]+'0')+res;
    return res;
  }

  bign operator + (const bign& b)const{
    bign c;
    c.len=0;
    for(int i=0,g=0;g||i<max(len,b.len);i++){
      int x=g;
      if(i<len)x+=s[i];
      if(i<b.len)x+=b.s[i];
      c.s[c.len++]=x%10;
      g=x/10;
    }
    return c;
  }

  void clean(){
    while(len>1 && !s[len-1])len--;
  }

  bign operator * (const bign& b){
    bign c;
    c.len=len+b.len;
    for(int i=0;i<len;i++)
      for(int j=0;j<b.len;j++)
        c.s[i+j]+=s[i]*b.s[j];
    for(int i=0;i<c.len-1;i++){
      c.s[i+1]+=c.s[i]/10;
      c.s[i]%=10;
    }
    c.clean();
    return c;
  }

  bign operator += (const bign& b){
    *this=*this+b;
    return *this;
  }
};

istream& operator >> (istream& in,bign& x){
  string s;
  in>>s;
  x=s.c_str();
  return in;
}

ostream& operator << (ostream& out,const bign& x){
  out<<x.str();
  return out;
}

bign h[110];
void Catalan(){
  h[0]=1;h[1]=1;
  for(int i=2;i<101;i++)
    for(int j=0;j<i;j++)
      h[i]+=h[j]*h[i-j-1];
}

int main(){
  Catalan();
  while(cin>>n){
    cout<<h[n]<<endl;
  }
}
