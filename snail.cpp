/*
  ID: wangyu.1
  LANG: C++11
  TASK: snail 
*/
#define TASKNAME "snail"

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
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif
char mp[120+5][120+5]={0};
int n,b;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int len=0;
int depth=1;
int max_d=0;
void prt()
{
    printf("----------\n");
    for(int i=0;i<n;i++)
	printf("%s\n",mp[i]);
}
void dfs(int r,int c,int d,int turn=0)
{
    //if(r<0||c<0||r>=n||c>=n) return;
    //if(mp[r][c]!='.') return;
    //depth++;
    //mp[r][c]='x';
    int nr=r+dir[d][0];
    int nc=c+dir[d][1];
    if(mp[nr][nc]=='x') return;
    if(nr<0||nc<0||nr>=n||nc>=n||mp[nr][nc]=='#')
    {
	if(turn==1) return;
	int dd[2];
	dd[0]=(d+1)%4;
	dd[1]=(d-1+4)%4;
	for(int i=0;i<2;i++)
	{ 
	    //int nr=r+dir[dd[i]][0];
	    //int nc=c+dir[dd[i]][1];
	    dfs(r,c,dd[i],1);
	}
    }
    else if(mp[nr][nc]=='.')
    {
	mp[nr][nc]='x';
	depth++;
	//if(depth==32)
	//  prt();
	max_d=max(max_d,depth);
	dfs(nr,nc,d);
	depth--;
	mp[nr][nc]='.';
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d",&n,&b);
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
	    mp[i][j]='.';
	}
    for(int i=0;i<b;i++)
    {
	char s[10];
	scanf("%s",s);
	int c=s[0]-'A';
	int r;
	sscanf(s+1,"%d",&r);	
	r--;
	mp[r][c]='#';
    }

    mp[0][0]='x';
    dfs(0,0,0);
    dfs(0,0,1);
    printf("%d\n",max_d);
	
    

    return 0;
}

