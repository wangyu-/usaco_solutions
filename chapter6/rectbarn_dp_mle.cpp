/*
  ID: wangyu.1
  LANG: C++11
  TASK: rectbarn
*/
#define TASKNAME "rectbarn"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;
#ifdef TEST
int test=1;
#else
int test=0;
#endif
char mp[3005][3005];
int h[3005][3005];
int l[3005][3005];
int r[3005][3005];
int l2[3005][3005];
int r2[3005][3005];
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int R,C,P;
    scanf("%d %d %d",&R,&C,&P);
    for(int i=1;i<=R;i++)
	    for(int j=1;j<=C;j++)
		    mp[i][j]=0;
    for(int i=0;i<P;i++)
    {
	    int r,c;
	    scanf("%d %d",&r,&c);
	    mp[r][c]=1;
    }
    for(int j=1;j<=C;j++)
    {
	    h[0][j]=0;
	    l2[0][j]=99999;
	    r2[0][j]=99999;
    }
    int best=0;
    for(int i=1;i<=R;i++)
    {
	    for(int j=1;j<=C;j++)
	    {
		    if(mp[i][j]) h[i][j]=0;
		    else h[i][j]=h[i-1][j]+1;
	    }
	    int left_rock=0;
	    for(int j=1;j<=C;j++)
	    {
		    if(mp[i][j]) left_rock=j,l[i][j]=0;
		    else l[i][j]=j-left_rock;
		    if(h[i][j]==0) l2[i][j]=0;
		    else if(h[i][j]==1) l2[i][j]=l[i][j];
		    else l2[i][j]=min(l[i][j],l2[i-1][j]);
	    }
	    int right_rock=C+1;
	    for(int j=C;j>=1;j--)
	    {
		    if(mp[i][j]) right_rock=j,r[i][j]=0;
		    else r[i][j]=right_rock-j;
		    if(h[i][j]==0) r2[i][j]=0;
		    else if(h[i][j]==1) r2[i][j]=r[i][j];
		    else r2[i][j]=min(r[i][j],r2[i-1][j]);
	    }
	    for(int j=0;j<=C;j++)
	    	best=max(best,h[i][j]*(l2[i][j]+r2[i][j]-1));
    }
    printf("%d\n",best);
    return 0;
}
