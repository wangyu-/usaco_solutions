/*
  ID: wangyu.1
  LANG: C++11
  TASK: game1
*/
#define TASKNAME "game1"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
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

struct sc_t
{
    int f=0,c=0;
    int d()
	{
	    return f-c;
	}
};

int a[105];

sc_t dp[105][105];

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	scanf("%d",a+i);
    for(int len=1;len<=n;len++)//len
    {	
	for(int st=0;st+len<=n;st++)
	{
	    sc_t c1,c2;
	    c1.f=a[st]+dp[st+1][len-1].c;
	    c1.c=dp[st+1][len-1].f;

	    c2.f=a[st+len-1]+dp[st][len-1].c;
	    c2.c=dp[st][len-1].f;
	    if(c1.d()>c2.d())
	    {
		dp[st][len]=c1;
	    }
	    else
	    {
		dp[st][len]=c2;
	    }
	}
    }

    printf("%d %d\n",dp[0][n].f,dp[0][n].c);
    
    return 0;
}

