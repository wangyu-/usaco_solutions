/*
ID: wangyu.1
LANG: C++11
TASK: combo
*/
#define TASKNAME "combo"

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
int n;
int dist(int a,int b)
{
	if(a>b)
	{
		int t=a;
		a=b;
		b=t;
	}
	int d1=b-a;
	int d2=a+n-b;
	return min(d1,d2);
	
}
int ok(int a,int b)
{
	return dist(a,b)<=2;
}
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif	
	scanf("%d",&n);
	int a[10],b[10];
	scanf("%d %d %d",a+0,a+1,a+2);
	scanf("%d %d %d",b+0,b+1,b+2);
	int cnt=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	{	
		if(ok(i,a[0])&&ok(j,a[1])&&ok(k,a[2]))
		{
			cnt++;
		}
		else if(ok(i,b[0])&&ok(j,b[1])&&ok(k,b[2]))
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
