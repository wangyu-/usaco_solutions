/*
  ID: wangyu.1
  LANG: C++11
  TASK: nuggets
*/
#define TASKNAME "nuggets"

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

const int mod=65536*16;
int dp[mod]={0};
int mask=0xfffff;
int n;
int num[10+10];
int ub=1000*1000;
int min_num=999;
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	scanf("%d",&num[i]);
	min_num=min(min_num,num[i]);
    }
    dp[0]=1;
    int largest=0;
    int cnt=0;
    for(int i=1;i<ub;i++)
    {
	dp[i&mask]=0;
	for(int j=0;j<n;j++)
	{
	    dp[i&mask]|=dp[(i+mod-num[j])&mask];
	    if(dp[i&mask]) break;
	}
	if(!dp[i&mask]) {largest=i;cnt=0;}
	else cnt++;
	if(cnt>min_num+5)
	{
	    printf("%d\n",largest);
	    return 0;
	}
    }
    printf("%d\n",0);

    
    
    return 0;
}

