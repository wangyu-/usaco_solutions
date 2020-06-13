/*
  ID: wangyu.1
  LANG: C++11
  TASK: ttwo
*/
#define TASKNAME "ttwo"

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

struct pos_t
{
    int r;
    int c;
    int d=0;
};
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char mp[15][15];
pos_t p_f,p_c;
void move(pos_t &p)
{
    int nr=p.r+dir[p.d][0];
    int nc=p.c+dir[p.d][1];
    if(nr>=10||nr<0||nc>=10||nc<0)
    {
	p.d+=1;
	p.d%=4;
	return ;
    }
    if(mp[nr][nc]!='.')
    {
	p.d+=1;
	p.d%=4;
	return ;
    }
    p.r=nr;p.c=nc;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    for(int i=0;i<10;i++)
    {
	scanf("%s",mp[i]);
    }
    for(int i=0;i<10;i++)
    {
	for(int j=0;j<10;j++)
	{
	    if(mp[i][j]=='F')
	    {
		p_f.r=i;
		p_f.c=j;
		mp[i][j]='.';
	    }

	    if(mp[i][j]=='C')
	    {
		p_c.r=i;
		p_c.c=j;
		mp[i][j]='.';
	    }
	}
    }
    int cnt=0;
    while(cnt++<1000000)
    {
	move(p_f);
	move(p_c);
	if(p_f.c==p_c.c&&p_f.r==p_c.r)
	{
	    printf("%d\n",cnt);
	    return 0;
	}
    }
    printf("0\n");
    

    return 0;
}

