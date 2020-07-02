/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "tracing"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct edge_t
{
	int t;
	int a,b;
};
bool cmp(const edge_t& x, const edge_t &y)
{
	return x.t<y.t;
}
int verify(char *s,vector<edge_t> &e,int n,int K)
{
	int dbg=0;
#ifdef TEST
	if(n==0 &&K==1)
		dbg=1;
#endif
	int i,j;
	int sick_sum=0;
	int sick[100+5];
	int left_K[100+5];
	
	memset(sick,0,sizeof(sick));
	memset(left_K,-1,sizeof(left_K));

	for(i=0;s[i]!=0;i++)
	{
		if(s[i]=='1') 
		{
			sick[i]=1;
			sick_sum++;
		}
	}
	if(sick[n]==0)
		return -1;

	left_K[n]=K;
	int cnt=1;
	for(i=0;i<e.size();i++)
	{
		int a=e[i].a;int b=e[i].b;
		if(left_K[a]!=-1 &&left_K[b]!=-1)
		{
			//nop
		}
		else if(left_K[a]==-1&&left_K[b]==-1)
		{
			//nop
		}
		else
		{
			if(dbg)printf("<possible infect %d,%d>",a,b);
			int x,y;
			if(left_K[a]!=-1) {x=a;y=b;}
			else {x=b;y=a;}
			if(left_K[x]>0)
			{
				if(sick[y]==0) return -1;
				left_K[y]=K+1;
				cnt++;		
			}
		}

		if(left_K[a]>0) left_K[a]--;
		if(left_K[b]>0) left_K[b]--;
		
	}
	if(cnt==sick_sum) return 1;
	if(dbg) printf("<not match %d %d>",cnt,sick_sum);
	return -1;
}
int XXX=255;
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	int i,j;
	char s[100+5];
	int N,T;
	scanf("%d %d",&N,&T);
	scanf("%s",s);
	s[N]=0;
	vector<edge_t> e;
	for(int i=0;i<T;i++)
	{
		int t,a,b;
		edge_t tmp;
		scanf("%d %d %d",&t,&a,&b);
		tmp.t=t;tmp.a=a-1;tmp.b=b-1;
		e.push_back(tmp);
	}
	sort(e.begin(),e.end(),cmp);
	int cow_cnt=0;
	int g_min=1000;
	int g_max=-1;
	for(int i=0;i<N;i++)
	{
		int min_K=1000;
		int max_K=-1;	
		for(int K=0;K<=XXX;K++)
		{
			if(verify(s,e,i,K)==1)
			{
#ifdef TEST
				if(K<5)
					printf("<verify okay %d %d>",i,K);
#endif
				if(K<min_K) min_K=K;
				if(K<g_min) g_min=K;
				if(K>max_K) max_K=K;
				if(K>g_max) g_max=K;
				
			}
		}
		if(min_K!=1000)
		{
			cow_cnt++;
		}		
	}
	printf("%d %d ",cow_cnt,g_min);
	if(g_max==XXX)
	{
		printf("Infinity\n");
	}
	else
	{
		printf("%d\n",g_max);
	}
	
	return 0;
}

