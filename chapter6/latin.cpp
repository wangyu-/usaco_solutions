/*
  ID: wangyu.1
  LANG: C++11
  TASK: latin
*/
#define TASKNAME "latin"

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
int N;
int col_used[7][7]={0};
int col_used_cnt[7]={0};
int row_used[7][7]={0};
long long ans=0;
int latin[7][7];
int search_cnt=0;
long long dfs(int row,int col)
{
	search_cnt++;
	if(col==N)
	{
		return dfs(row+1,0);
	}
	if(row==N-1)
	{
		//ans++;
		//if(ans%100000==0) if(test) printf("<%lld>\n",ans);
		if(0)
		{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				printf("%d ",latin[i][j]+1);
			}
			printf("\n");
		}
		printf("\n");
		}
		return 1;
	}

	if(col==0)
	{
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			if(row_used[row][i]==1) continue;
			if(col_used[col][i]==1) continue;
			col_used[col][i]=1;
			col_used_cnt[col]++;
			row_used[row][i]=1;
			latin[row][col]=i;
			sum+=dfs(row,col+1);
			col_used[col][i]=0;
			col_used_cnt[col]--;
			row_used[row][i]=0;
			break;
		}
		sum*=N-col_used_cnt[col];
		return sum;
	}
	if(col==1)
	{
		long long sum0=0;
		long long sum1=0;
		int cnt0=0;
		int cnt1=0;
		for(int i=0;i<N;i++)
		{
			if(row_used[row][i]==1) continue;
			if(col_used[col][i]==1) continue;
			col_used[col][i]=1;
			col_used_cnt[col]++;
			row_used[row][i]=1;
			
			if(col_used[col-1][i])
			{
				if(cnt0==0)
				{
					sum0+=dfs(row,col+1);
				}
				cnt0++;
			}
			else
			{
				if(cnt1==0)
				{
					sum1+=dfs(row,col+1);
				}
				cnt1++;
			}
			//latin[row][col]=i;
			//sum+=dfs(row,col+1);
			col_used[col][i]=0;
			col_used_cnt[col]--;
			row_used[row][i]=0;
			//break;
		}
		//return sum0+sum1;
		return sum0*cnt0+sum1*cnt1;
	}
	long long sum=0;
	for(int i=0;i<N;i++)
	{
		if(row_used[row][i]==1) continue;
		if(col_used[col][i]==1) continue;
		col_used[col][i]=1;
		col_used_cnt[col]++;
		row_used[row][i]=1;
		latin[row][col]=i;
		sum+=dfs(row,col+1);
		col_used[col][i]=0;
		col_used_cnt[col]--;
		row_used[row][i]=0;
	}
	return sum;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
	    latin[0][i]=i;
	    col_used[i][i]=1;
	    col_used_cnt[i]=1;
    }
    ans=dfs(1,0);
    printf("%lld\n",ans);
    if(test) printf("<%d>",search_cnt);

    return 0;
}

