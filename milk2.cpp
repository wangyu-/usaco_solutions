/*
ID: wangyu.1
LANG: C++11
TASK: milk2
*/
#define TASKNAME "milk2"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int buf[1000*1000+10];
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif

	int n;
	scanf("%d",&n);
	memset(buf,0,sizeof(buf));
	int max=0;
	int min=1000*1000+1;
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a<min) min=a;
		if(b>max) max=b;
		for(int j=a;j<b;j++)
		{
			buf[j]++;
		}
	}
	int max_cnt=0;
	int cnt=0;
	int max_cnt2=0;
	int cnt2=0;
	for(int i=min;i<max;i++)
	{
		//printf("<%d>",buf[i]);
		if(buf[i]!=0) cnt++;
		else cnt=0;
		if(cnt>max_cnt) max_cnt=cnt;
		if(buf[i]==0) cnt2++;
		else cnt2=0;
		if(cnt2>max_cnt2) max_cnt2=cnt2;
	}
	printf("%d %d\n",max_cnt,max_cnt2);

	return 0;
}

