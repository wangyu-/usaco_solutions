/*
  ID: wangyu.1
  LANG: C++11
  TASK: checker
*/
#define TASKNAME "checker"

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
char bd[13+2][13+2]={0};
int cnt=0;
int ans[13+2];
void dfs(int depth)
{
	if(depth==N)
	{
		if(cnt<3)
		{
			for(int i=0;i<N;i++)
			{
				if(i) printf(" ");
				printf("%d",ans[i]+1);
			}
			printf("\n");
		}
		cnt++;
		return ;
	}
	for(int col=0;col<N;col++)
	{
		if(bd[depth][col]) continue;

		for(int row=depth+1;row<N;row++)
		{
			bd[row][col]++;
		}
		for(int j=1;;j++)
		{
			if(col-j<0||depth+j>=N) break;
			bd[depth+j][col-j]++;
		}
		for(int j=1;;j++)
		{
			if(col+j>=N||depth+j>=N) break;
			bd[depth+j][col+j]++;
		}
		ans[depth]=col;
		dfs(depth+1);

		for(int row=depth+1;row<N;row++)
		{
			bd[row][col]--;
		}
		for(int j=1;;j++)
		{
			if(col-j<0||depth+j>=N) break;
			bd[depth+j][col-j]--;
		}
		for(int j=1;;j++)
		{
			if(col+j>=N||depth+j>=N) break;
			bd[depth+j][col+j]--;
		}
	}
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    scanf("%d",&N);
    dfs(0);
    printf("%d\n",cnt);

    


    return 0;
}

