/*
  ID: wangyu.1
  LANG: C++11
  TASK: rockers 
*/
#define TASKNAME "rockers"

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

int n,t,m;
int song[20+10];

int cal(int l,int r)
{
    int len=r-l;
    //if(len==0) return 0;
    int *a=song+l-1;
    int dp[20+10][20+10]={0};
    int best=0;
    for(int i=1;i<=len;i++)
    {
	for(int j=1;j<=t;j++)
	{
	    int r2=0;
	    if(j-a[i]>=0) r2=dp[i-1][j-a[i]]+1;
		
	    dp[i][j]=max(dp[i-1][j],r2);
	    best=max(best,dp[i][j]);
	}
    }
    return best;
}
int fit[20+10][20+10];
int dp[20+10][20+10]={0};
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d %d",&n,&t,&m);
    for(int i=1;i<=n;i++)
	scanf("%d",&song[i]);
    for(int i=1;i<=n;i++)
    {
	for(int j=i;j<=n+1;j++)
	{
	    fit[i][j]=cal(i,j);
	    if(test)printf("<i:%d j:%d fit=%d>",i,j,fit[i][j]);
	}
	if(test)printf("\n");
    }
    int best=0;
    for(int i=1;i<=m;i++)
    {
	for(int j=0;j<=n;j++)  //end of use
	{
	    for(int k=0;k<=j;k++) //enum pre sol
	    {
		dp[i][j]=max(dp[i][j],dp[i-1][k]+fit[k+1][j+1]);
		best=max(best,dp[i][j]);
	    }
	}
    }
    printf("%d\n",best);

    
    
    return 0;
}

