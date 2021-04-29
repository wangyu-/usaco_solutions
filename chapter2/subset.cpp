/*
  ID: wangyu.1
  LANG: C++11
  TASK: subset
*/
#define TASKNAME "subset"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;
#ifdef TEST
int test=1;
#else
int test=0;
#endif
long long dp[40][400]={0};
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    cin>>n;
    int sum=n*(n+1)/2;
    if(sum%2!=0) {cout<<0<<endl;return 0;}
    int cap=sum/2;
    if(test)printf("cap=%d\n",cap);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
	    for(int j=0;j<=cap;j++)
	    {
		    dp[i][j]=dp[i-1][j];
		    if(j>=i) dp[i][j]+=dp[i-1][j-i];
		    if(test)printf("<%d,%d>=%lld",i,j,dp[i][j]);
	    }
	    if(test) printf("\n");
    }
    cout<<dp[n][cap]/2<<endl;
    return 0;
}
