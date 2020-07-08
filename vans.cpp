/*
  ID: wangyu.1
  LANG: C++11
  TASK: vans
*/
#define TASKNAME "vans"

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

int inf=1000*1000*1000;
const int len=100;
struct bn_t
{
    int d[len]={0};
    void add(bn_t& y)
    {
	int *e=y.d;
	int c=0;
	for(int i=len-1;i>=0;i--)
	{
	    d[i]+=e[i]+c;
	    c=d[i]/inf;
	    d[i]%=inf;
	}
    }
    void operator +=(bn_t &y)
    {
	add(y);
    }
    void prt()
    {
	int i;
	for(i=0;i<len-1;i++)
	{
	    if(d[i])break;
	}
	int cnt=0;
	for(;i<len;i++)
	{
	    if(cnt++==0)
		printf("%d",d[i]);
	    else
		printf("%09d",d[i]);
	}
	//printf("\n");
	   
    }
    void set(int a)
    {
	d[len-1]=a;
    }
};

bn_t dp[1000+5][6];//={0};  // 0:100 1:010  2:001  3:101 disjoint    4:101 connect  5:111


int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           

    dp[2][3].set(1);
    dp[2][5].set(1);
    scanf("%d",&n);

    for(int i=3;i<=n;i++)
    {
	auto pre=dp[i-1];
	auto now=dp[i];
	//now[0]+=pre[3];
	now[0]+=pre[4];
	now[0]+=pre[5];

	now[1]+=pre[5];

	//now[2]+=pre[3];
	now[2]+=pre[4];
	now[2]+=pre[5];

	now[3]+=pre[3];
	now[3]+=pre[0];
	now[3]+=pre[2];

	now[4]+=pre[4];
	now[4]+=pre[5];

	now[5]+=pre[0];
	now[5]+=pre[1];
	now[5]+=pre[2];
	now[5]+=pre[3];
	/*if(test)
	{
	    printf("<case:%d>",i);
	    for(int j=0;j<6;j++)
		printf("<%lld>",now[j]);
	    printf("\n");
	    }*/
	
    }
    bn_t sum;
    sum+=dp[n][4];
    sum+=dp[n][4];
    sum+=dp[n][5];
    sum+=dp[n][5];
    //if(n>4) printf("!");
    //printf("%lld\n",dp[n][4]*2+dp[n][5]*2);
    sum.prt();
    printf("\n");


    return 0;
}

