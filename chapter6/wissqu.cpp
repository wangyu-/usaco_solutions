/*
  ID: wangyu.1
  LANG: C++11
  TASK: wissqu
*/
#define TASKNAME "wissqu"

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

char pst[4][4+1];
char used[4][4]={0};
int cnt=0;
char ll[128]={0};
char ans[16+5];
char x[16+5];
char y[16+5];
void dfs(int depth,char h)
{
	//printf("<%d>",depth);
	if(depth==16) 
	{
		cnt++;
		if(cnt==1)		
			for(int i=0;i<16;i++)
			{
				printf("%c %d %d\n",ans[i],x[i]+1,y[i]+1);
			}
		/*
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				printf("<%c %d>",pst[i][j],used[i][j]);
			}
			printf("\n");
		}
		for(int i=0;i<5;i++)
		{
			printf("<%d>",ll['A'+i]);
		}
		printf("\n");*/
		return ;
	}
	char avial[4][4];
	memset(avial,1,sizeof(avial));
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(used[i][j]) avial[i][j]=0;
			if(pst[i][j]==h)
			{
				for(int u=-1;u<=1;u++)
				{
					if(u+i<0) continue;
					if(u+i>=4) continue;
					for(int v=-1;v<=1;v++)
					{
						if(v+j<0) continue;
						if(v+j>=4) continue;
						avial[u+i][j+v]=0;
					}
				}
			}
		}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(avial[i][j]==1)
			{
				char backup=pst[i][j];
				pst[i][j]=h;
				used[i][j]=1;
				ans[depth]=h;
				x[depth]=i;
				y[depth]=j;
				for(int k=0;k<5;k++)
				{
					if(ll['A'+k]>0)
					{
						ll['A'+k]--;
						dfs(depth+1,'A'+k);
						ll['A'+k]++;
					}
				}
				used[i][j]=0;
				pst[i][j]=backup;
			}
		} 
	}
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    for(int i=0;i<4;i++)
    {
	    scanf("%s",pst[i]);
    }
    ll['A']=3;
    ll['B']=3;
    ll['C']=3;
    ll['D']=4;
    ll['E']=3;
    dfs(0,'D');
    printf("%d\n",cnt);



    return 0;
}

