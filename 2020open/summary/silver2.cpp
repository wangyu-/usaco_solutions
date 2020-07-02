/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "cereal"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int cow_pre[100*1000+5][2];
int used[100*1000+5];
int kick=0;
#ifdef TEST
int test=1;
#else
int test=0;
#endif

int take(int now,int c)   //now= cow number ;   c= the creal to take
{
	if(test)printf("[take %d,%d]",now,c);
	if(used[c]==0) 
	{
		used[c]=now;
		return 0;
	}
	else if(used[c]<now) 
	{
		kick++;
		return 0;
	}
	else 
	{
		int pre=used[c];
		if(c==cow_pre[pre][0])
		{
			used[c]=now;
			take(pre,cow_pre[pre][1]);
		}
		else if(c==cow_pre[pre][1])
		{
			kick++;
		}
		used[c]=now;
		return 0;
	}
}
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	memset(used,0,sizeof(used));
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		cow_pre[i][0]=a;
		cow_pre[i][1]=b;
	}
	vector<int> res;
	for(int i=n;i>=1;i--)
	{
		int c=cow_pre[i][0];
		if(test)printf("-------------%d--------------\n",i);
		take(i,c);
		//assert(i-kick>=0);
		res.push_back(n-i+1-kick);
		if(test)printf("<i=%d,kick=%d>\n",i,kick);
	}
	reverse(res.begin(),res.end());
	for(int i=0;i<res.size();i++)
	{
		//if(i!=0) printf(" ");
		printf("%d\n",res[i]);
	}
	//printf("\n");
	return 0;
}

