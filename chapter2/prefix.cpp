/*
  ID: wangyu.1
  LANG: C++11
  TASK: prefix
*/
#define TASKNAME "prefix"

//#include <bits/stdc++.h>

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
char lst[205][15];
char llen[205];
char s[200*1000+10];
char s0[100];
int dp[200*1000+10]={0};
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif

    int cnt=0;
    while(1)
    {
	scanf("%s",lst[cnt]);
	llen[cnt]=strlen(lst[cnt]);
	if(lst[cnt][0]=='.') break;
	cnt++;
    }
    string ss;
    while(1)
    {
	if(test)printf("<!>\n");
	if(scanf("%s",s0)!=1) break;
	//if(test)printf("<%s>",s0);
	//if(strlen(s0)==0)break;
	ss+=s0;
    }
    s[0]=0;
    strcpy(s,ss.c_str());
    int len=strlen(s);
    dp[0]=1;
    for(int i=1;i<=len;i++)
    {
	for(int j=0;j<cnt;j++)
	{
	    if(llen[j]>i) continue;
	    if(dp[i-llen[j]]==1)
	    {
		if(memcmp(s+i-llen[j],lst[j],llen[j])==0)
		{
		    dp[i]=1;
		}
	    }
	}
    }
    if(test)
    for(int i=0;i<=len;i++)
    {
	printf("<%d>",dp[i]);
    }
    for(int i=len;i>=0;i--)
    {
	if(dp[i])
	{
	    printf("%d\n",i);
	    break;
	}
    }
    return 0;
}

