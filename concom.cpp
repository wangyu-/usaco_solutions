/*
  ID: wangyu.1
  LANG: C++11
  TASK: concom 
*/
#define TASKNAME "concom"

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

int owns[100+5][100+5];
int ctrl[100+5][100+5];
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    int m=100;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	int x,y,p;
	scanf("%d %d %d",&x,&y,&p);
	owns[x][y]=p;
    }
    for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	{
	    if(i==j) ctrl[i][j]=1;
	    if(owns[i][j]>50) ctrl[i][j]=1;
	}
    while(1)
    {
	int change=0;
	for(int i=1;i<=m;i++)
	{
	    for(int j=1;j<=m;j++)
	    {
		if(ctrl[i][j]) continue;
		int sum=0;
		for(int k=1;k<=m;k++)
		{
		    if(ctrl[i][k] &&ctrl[k][j])
		    {
			sum+=51;
		    }
		    else if(ctrl[i][k])
		    {
			sum+=owns[k][j];
		    }
		}
		if(sum>=51)
		{
		    ctrl[i][j]=1;
		    change=1;
		}
	    }
	}
	if(!change)break;
    }
    for(int i=1;i<=m;i++)
    {
	for(int j=1;j<=m;j++)
	{
	    if(j==i) continue;
	    if(ctrl[i][j])
		printf("%d %d\n",i,j);
	}
    }
    return 0;
}

