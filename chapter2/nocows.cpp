/*
  ID: wangyu.1
  LANG: C++11
  TASK: nocows
*/
#define TASKNAME "nocows"

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
int dp[105][205]={0};
int sum[105][205]={0};
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    //srand(time(0));
    int n,k;
    scanf("%d %d",&n,&k);
    dp[1][1]=1;
    sum[1][1]=1;
    for(int i=2;i<=k;i++)
	for(int j=0;j<=n;j++)
	{
	    for(int u=0;u<=j-1;u++)
	    {
	        int a=dp[i-1][u]*dp[i-1][j-1-u];
		a%=9901;
		int b=dp[i-1][u]*sum[i-2][j-1-u];
		b%=9901;
		b*=2;
		b%=9901;
		dp[i][j]+=a+b;
		dp[i][j]%=9901;
	    }
	    sum[i][j]=sum[i-1][j]+dp[i][j];
	    sum[i][j]%=9901;
	}
    //if(k>=8&&k!=47) printf("xxx");
    printf("%d\n",dp[k][n]);

    return 0;
}

