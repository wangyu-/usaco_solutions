/*
  ID: wangyu.1
  LANG: C++11
  TASK: fracdec
*/
#define TASKNAME "fracdec"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif
string res_full;
string res;
void prt()
{
    string &s=res_full;
    for(int i=0;i<s.size();i++)
    {
	if(i%76==0&&i) printf("\n");
	printf("%c",s[i]);	
    }
    printf("\n");
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n,d;
    scanf("%d %d",&n,&d);
    //printf("%d.",n/d);
    char tmp[100];
    sprintf(tmp,"%d.",n/d);
    res_full=tmp;
    n=n%d;
    if(n==0)
    {
	res_full+="0";
	prt();
	return 0;
	//printf("0\n");
	//return 0;
    }
    int cnt=100;
    map<int,int>mp;
    for(int i=0;;i++)
    {
	if(n==0)
	{
	    res_full+=res;
	    prt();
	    return 0;
	}
	if(mp.find(n)!=mp.end())
	{
	    //printf("loop\n");
	    for(int i=0;i<res.size();i++)
	    {
		if(i==mp[n])
		{
		    //printf("(");
		    res_full+="(";
		}
		//printf("%c",res[i]);
		res_full+=res[i];
	    }
	    res_full+=")";
	    prt();
	    return 0;
	}
	mp[n]=i;
	n*=10;
	res+='0'+n/d;
	
	//printf("%d",n/d);
	n=n%d;
    }
    

    
    return 0;
}

