/*
  ID: wangyu.1
  LANG: C++11
  TASK: kimbits
*/
#define TASKNAME "kimbits"

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

long long cache[40][40];
long long c(int n,int k)
{
    if(cache[n][k]!=-1) return cache[n][k];
    assert(n>=0);
    assert(k>=0);
    if(k>n) return 0;
    if(k==n||k==0) return 1;
    if(k==1) return n; 
    //if(k>n/2) return c(n,n-k);
    return cache[n][k]=c(n-1,k)+c(n-1,k-1); 
}
long long c_ng(int n,int k)
{
    long long res=0;
    for(int i=0;i<=k;i++)
    {
	res+=c(n,i);
	//printf("<%d,%d>[%d]",n,k,c(n,k));
    }
    return res;
}

#ifdef TEST
int test=1;
#else
int test=0;
#endif

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    //printf("%d\n",0xfff);
    memset(cache,-1,sizeof(cache));
    int n,l;long long idx;
    //printf("<<%d>>",c(0,0));
    //printf("<<%d>>",c_ng(0,1));
    scanf("%d %d %lld",&n,&l,&idx);
    long long left=idx;
    int n0=n;
    for(int i=0;i<n0;i++)
    {
        long long zero=c_ng(n-1,l);
	//printf("<%lld>",zero);
	if(left<=zero)
	{
	    printf("0");
	    n--;
	}
	else
	{
	    left-=zero;
	    l--;
	    n--;
	    printf("1");
	}
    }
    printf("\n");
    
    return 0;
}

