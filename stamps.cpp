/*
  ID: wangyu.1
  LANG: C++11
  TASK: stamps
*/
#define TASKNAME "stamps"

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

int K,N;
int stamps[50+5];
int dp0[10000*10+5];
int &dp(int i)
{
    return dp0[i%100000];
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d",&K,&N);
    for(int i=0;i<N;i++)
	scanf("%d",&stamps[i]);

    dp(0)=0;
    for(int i=1;;i++)
    {
	dp(i)=999999;
	for(int j=0;j<N;j++)
	{
	    int value=stamps[j];
	    if(i-value>=0)
	    {
		dp(i)=min(dp(i),dp(i-value)+1);
	    }
	}
	if(dp(i)>K)
	{
	    printf("%d\n",i-1);
	    break;
	}
    }



    

    
    return 0;
}

