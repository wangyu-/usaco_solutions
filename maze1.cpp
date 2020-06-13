/*
  ID: wangyu.1
  LANG: C++11
  TASK: maze1
*/
#define TASKNAME "maze1"

//#include <bits/stdc++.h>

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

char mp[210][210]={0};
int dist[210][210];

int C,R;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct pos_t
{
    int r,c;
};
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    memset(dist,-1,sizeof(dist));
    scanf("%d %d",&C,&R);
    getchar();
    for(int i=0;i<R*2+1;i++)
    {
	scanf("%[^\n]%*c",mp[i]);
	//printf("<%s>",mp[i]);
	//printf("<%d>",i);
    }
    for(int i=0;i<R*2+1;i++)
	for(int j=0;j<C*2+1;j++)
	{
	    if(i==0||i==R*2||j==0||j==C*2)
	    {
		if(mp[i][j]==' ')
		{
		    mp[i][j]='#';
		    for(int k=0;k<4;k++)
		    {
			int new_i=i+dir[k][0];
			int new_j=j+dir[k][1];
			if(new_i<0||new_i>R*2||new_j<0||new_j>C*2) continue;
			if(new_i%2==1&&new_j%2==1)
			{
			    dist[new_i][new_j]=1;
			}
		    }
		}
	    }
	}
    vector<pos_t> vec;
    for(int i=0;i<R*2+1;i++)
	for(int j=0;j<C*2+1;j++)
	{
	    if(dist[i][j]!=-1)
	    {
		pos_t tmp;
		tmp.r=i;
		tmp.c=j;
		vec.push_back(tmp);
		//printf("<%d,%d>",i,j);
	    }
	}
    for(int i=0;i<vec.size();i++)
    {
	pos_t p=vec[i];
	int d=dist[p.r][p.c];
	for(int j=0;j<4;j++)
	{
	    int new_r,new_c;
	    new_r=p.r+dir[j][0];
	    new_c=p.c+dir[j][1];
	    if(mp[new_r][new_c]==' ')
	    {
		int rr=p.r+dir[j][0]*2;
		int cc=p.c+dir[j][1]*2;
		if(dist[rr][cc]==-1)
		{
		    dist[rr][cc]=d+1;
		    pos_t new_p;
		    new_p.r=rr;new_p.c=cc;
		    vec.push_back(new_p);
		}
	    }
	}
    }

    int max_d=0;
    for(int i=0;i<R*2+1;i++)
	for(int j=0;j<C*2+1;j++)
	{
	    if(dist[i][j]!=-1)
	    {
		//printf("<%d>",dist[i][j]);
		max_d=max(dist[i][j],max_d);
	    }
	}
    printf("%d\n",max_d);

    
    return 0;
}

