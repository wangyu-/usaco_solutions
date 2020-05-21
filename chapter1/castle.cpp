/*
  ID: wangyu.1
  LANG: C++11
  TASK: castle
*/
#define TASKNAME "castle"

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
int fl[60][60];
int size[50*50+100]={0};
int id[60][60];
int cnt=0;
int m,n;
int dfs(int i,int j)
{
    if(id[i][j]!=-1)
    {
	return 0;
    }
    id[i][j]=cnt;
    size[cnt]++;
    int t=fl[i][j];
    if((t&1)==0) dfs(i,j-1);
    if((t&2)==0) dfs(i-1,j);
    if((t&4)==0) dfs(i,j+1);
    if((t&8)==0) dfs(i+1,j);
    return 1;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<m;j++)
	{
	    scanf("%d",&fl[i][j]);
	}
    }
    memset(id,-1,sizeof(id)); 
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<m;j++)
	{
	    int r=dfs(i,j);
	    cnt+=r;
	}
    }
    printf("%d\n",cnt);
    int max_size=-1;
    for(int i=0;i<cnt;i++)
    {
	if(test) printf("<%d>",size[i]);
	max_size=max(max_size,size[i]);
    }
    printf("%d\n",max_size);
    int best=0;
    int pi,pj;
    char dir;
    for(int j=0;j<m;j++)
	for(int i=n-1;i>=0;i--)
	{
	    if(i!=0)
	    {
		if(id[i-1][j]!=id[i][j])
		{
		    int current=size[id[i-1][j]]+size[id[i][j]]; 
		    if(current>best)
		    {
			pi=i;pj=j;
			dir='N';
			best=current;
		    }

		}
	    }
	    if(j!=m-1)
	    {
		if(id[i][j+1]!=id[i][j])
		{
		    int current=size[id[i][j+1]]+size[id[i][j]]; 
		    if(current>best)
		    {
			pi=i;pj=j;
			dir='E';
			best=current;
		    }
		}
	    }
	    
	}
    printf("%d\n",best);
    printf("%d %d %c\n",pi+1,pj+1,dir);

    return 0;
}
