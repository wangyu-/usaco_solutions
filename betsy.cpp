/*
  ID: wangyu.1
  LANG: C++11
  TASK: betsy
*/
#define TASKNAME "betsy"

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
char mp[7][7]={0};
char dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int ans=0;

void dfs2(int x,int y)
{
	if(mp[x][y]) return ;
	mp[x][y]=-1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx<0||xx>=N) continue;
		if(yy<0||yy>=N) continue;
		if(mp[xx][yy]) continue;
		dfs2(xx,yy);
	}
}
int is_connect()
{
	int x=-1,y=-1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(mp[i][j]==0) 
			{
				x=i;y=j;
				break;
			}
		}
	}
	//if(x==-1) return 1; 	
	dfs2(x,y);
	int ok=1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(mp[i][j]==0) 
			{
				ok=0;
			}
			if(mp[i][j]==-1)
				mp[i][j]=0;
		}
	}
	return ok;

}
int adj_space(int x,int y)
{
	int cnt=0;
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx<0||xx>=N) continue;
		if(yy<0||yy>=N) continue;
		if(mp[xx][yy]) continue;
		cnt++;
	}
	return cnt;
}
/*
int verify2(int x,int y)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(x==i&&y==j) continue;
			if(i==N-1&&j==0)continue;
			if(mp[i][j]) continue;

			if(adj_space(i,j)<2) 
			{
				//printf("<%d %d>\n",i,j);
				return 0;
			}
		}
	return 1;
}*/
void verify3(int x,int y,char not_ok[])
{
	for(int idx=0;idx<4;idx++)
	{
		int i=dir[idx][0];
		int j=dir[idx][1];
		if(x+i==N-1&&y+j==0)continue;
		if(x+i<0||x+i>=N) continue;
		if(y+j<0||y+j>=N) continue;
		if(mp[x+i][y+j]) continue;

		if(adj_space(x+i,y+j)<2) 
		{
			not_ok[idx]=1;
		}
	}
	//return 1;
}
int search_cnt=0;
void dfs(int x,int y,int depth)
{
	search_cnt++;
	//printf("<dfs %d %d %d>\n",x,y,depth);
	if(x==N-1&&y==0)
	{
		if(depth==N*N-1) 
		{
			ans++;
		}
		return;
	}

	//if(is_connect()==0) return ;
	//mp[x][y]=0;
	//
	int cnt=0;
	char not_ok[4]={0};
	verify3(x,y,not_ok);
	for(int i=0;i<4;i++)
	{
		if(not_ok[i]) cnt++;
	}
	if(cnt>=2) return ;

	for(int i=0;i<4;i++)
	{
		if(cnt==1&&not_ok[i]==0) continue;
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx<0||xx>=N) continue;
		if(yy<0||yy>=N) continue;
		if(mp[xx][yy]) continue;
		mp[xx][yy]=1;
		//if(not_ok[i]==0) continue;
		//if(verify3(x,y)==0) {mp[xx][yy]--;continue;}

		dfs(xx,yy,depth+1);
		mp[xx][yy]=0;
	}
}

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    scanf("%d",&N);
    mp[0][0]=1;
    dfs(0,0,0);
    printf("%d\n",ans);
    if(test) printf("<%d>\n",search_cnt);


    return 0;
}

