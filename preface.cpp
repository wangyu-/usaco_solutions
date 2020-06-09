/*
  ID: wangyu.1
  LANG: C++11
  TASK: preface 
*/
#define TASKNAME "preface"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#ifdef TEST
int test=1;
#else
int test=0;
#endif
string di(int a,char ten,char five,char one)
{
    string t="";
    if(a<=3) return string(a,one);
    else if(a==5) return t+five;
    else if(a==4) return t+one+five;
    else if(a==9) return t+one+ten;
    else
    {
	return t+five+string(a-5,one);
    }
}
string rom(int a)
{
    int u,v,w,x;
    u=a/1000;
    v=a%1000/100;
    w=a%100/10;
    x=a%10;
    return di(u,'Q','Q','M')+ di(v,'M','D','C')+di(w,'C','L','X')+di(x,'X','V','I');
}
int h[256+10]={0};
void prt(char a)
{
    if(h[a]) printf("%c %d\n",a,h[a]);
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
	string r=rom(i);
        for(int j=0;j<=r.length();j++)
	{
	    h[r[j]]++;
	}
    }
    string l="IVXLCDM";
    for(int i=0;i<l.length();i++)
    {
	prt(l[i]);
    }

    return 0;
}

