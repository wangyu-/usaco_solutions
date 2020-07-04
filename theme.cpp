/*
  ID: wangyu.1
  LANG: C++11
  TASK: theme
*/
#define TASKNAME "theme"

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
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif

int ns[5000+5];
int sum0[5000+5];
int *sum=sum0+1;
int n;

const int mod=10007;

vector<int> h[mod];

int cal_sum(int a,int len)
{
    int res=0;
    /*
    for(int i=1;i<len;i++)
    {
	res+=ns[a+i]-ns[a];
    }
    return res;*/
	
    return sum[a+len-1]-sum[a-1]-ns[a]*len;
}
int eq(int a,int b,int len)
{
    //if(cal_sum(a,len)!=cal_sum(b,len)) return 0;
    int i,j;
    int delta=ns[b]-ns[a];
    for(i=1;i<len;i++)
    {
	if(ns[a+i]!=ns[b+i]-delta) return 0;
    }
    return 1;
}

int verify(int len)
{
    for(int i=0;i<mod;i++)
    {
	h[i].clear();
    }
    for(int i=0;i+len<=n;i++)
    {
	int r=cal_sum(i,len); //printf("<%d %d>",i,r);
	h[(r+5005*88)%mod].push_back(i);
    }
    //printf("-----\n");
    for(int i=0;i<mod;i++)
    {
	for(int j=0;j<h[i].size();j++)
	    for(int k=j+1;k<h[i].size();k++)
	    {
		int x=h[i][j];
		int y=h[i][k];
		//printf("%d %d\n",x,y);
		//if(h[i][j]+len<h[i][k]) continue;
		if(x+len>y)continue;
		if(eq(x,y,len)) return 1;
	    }
    }
    /*
    for(int i=0;i+len<=n;i++)
    {
	for(int j=i+len;j+len<=n;j++)
	{
	    //printf("<%d %d %d>",i,j,len);
	    if(eq(i,j,len)) return 1;
	}
	}*/
    return 0;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d",&n);
    sum[-1]=0;
    for(int i=0;i<n;i++)
    {
	scanf("%d",&ns[i]);
	sum[i]=ns[i]+sum[i-1];
    }
    int l=5;
    int h=n/2;
    while(l+1<h)
    {
	//printf("<%d,%d>",l,h);
	int mid=(l+h)/2;
	if(verify(mid))
	{
	    l=mid;
	}
	else
	{
	    h=mid-1;
	}
    }
    if(verify(5)==0)
    {
	printf("0\n");
	return 0;
    }
    if(verify(h)) printf("%d\n",h);
    else  printf("%d\n",l);
    

    return 0;
}

