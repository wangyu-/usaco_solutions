/*
  ID: wangyu.1
  LANG: C++11
  TASK: twofive
*/
#define TASKNAME "twofive"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <math.h>
#include <typeinfo>
#include <iostream>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif

int n;

const int size=4;
long long dp[size+1][size+1][size+1][size+1];
long long &dd(int a[])
{
    return dp[a[0]][a[1]][a[2]][a[3]];
}
int rst[size*size]={0};
int rst_inv[size*size+1][2];
void prt(int a[])
{
    for(int i=0;i<size;i++)
	printf("<%d>",a[i]);
    printf("\n");
}
long long dfs(int a[])
{
    if(a[0]<a[1]||a[1]<a[2]||a[2]<a[3])
    {
	return -2;
    }
    if(dd(a)!=-1) return dd(a);
    dd(a)=0;
    int area=0;
    for(int i=0;i<size;i++)
    {
	area+=a[i];
    }
    int r=rst_inv[area][0];
    int c=rst_inv[area][1];
    //printf("<%d,%d>",r,c);
    int has_rst=0;
    if(r!=-1) has_rst=1;
    if(has_rst)
    {
	//prt(a);
	//printf("<%d %d>",r,c);
    }
    for(int i=0;i<size;i++)
    {
	if(has_rst)
	{ 
	    if(i!=c) continue;
	    if(a[i]!=r) continue;
	}
	if(a[i]==0) continue;
	a[i]-=1;
	long long r=dfs(a);
	a[i]+=1;
	if(r!=-2)
	{
	    dd(a)+=r;
	}
    }
    return dd(a);
    
}
long long cal()
{
    int a[]={4,4,4,4};
    memset(dp,-1,sizeof(dp));
    dp[0][0][0][0]=1;
    memset(rst_inv,-1,sizeof(rst_inv));
    memset(rst,0,sizeof(rst));
    for(int i=0;;i++)
    {
	int t;
	scanf("%d",&t);
	if(t==0) break;
	rst[i]=t;
    }
    for(int i=0;i<size*size;i++)
    {
	if(rst[i])
	{
	    //printf("!!!\n");
	    rst_inv[rst[i]][0]=i/size+1;
	    rst_inv[rst[i]][1]=i%size;
	}
    }
    long long r=dfs(a);

    return r;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    while(1)
    {
    printf("<%lld>\n",cal());
    }

    return 0;
}

