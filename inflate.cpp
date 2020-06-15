/*
  ID: wangyu.1
  LANG: C++11
  TASK: inflate
*/
#define TASKNAME "inflate"

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

int mat[105][105];
int m,n;

int v[10000+5];
int s[10000+5];
int dp[10000+5];
const int inf=10000*10000;

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif

    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++)
    {
	scanf("%d %d",&v[i],&s[i]);
    }    
    dp[0]=0;
    int best=0;
    for(int i=1;i<=m;i++)
    {
	dp[i]=0;
	for(int j=0;j<n;j++)
	{
	    if(s[j]<=i)
	    {
		int a=dp[i-s[j]]+v[j];
		dp[i]=max(dp[i],a);
	    }
	}
	best=max(best,dp[i]);
    }
    printf("%d\n",best);
    
    return 0;
}

