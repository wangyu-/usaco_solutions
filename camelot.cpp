/*
  ID: wangyu.1
  LANG: C++11
  TASK: camelot
*/
#define TASKNAME "camelot"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif

int R,C;
struct pos_t
{
    int r,c;
    int step=0;
    int ok()
	{
	    if(r<1||r>R) return 0;
	    if(c<1||c>C) return 0;
	    return 1;
	}
}king;
vector<pos_t> ns;
int km[8][2]={{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
int nm[8][2]={{1,2},{2,1},{-1,2},{2,-1},{-2,1},{1,-2},{-1,-2},{-2,-1}};
const int inf=1000*1000*1000;
int dist[35][35][35][35];
int dk[35][35];
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif 

    scanf("%d %d",&R,&C);
    for(int cnt=0;;cnt++)
    {
	char tmp[10];int r,c;
	if(scanf("%s %d",tmp,&r)!=2) break;
	c=tmp[0]-'A'+1;
	pos_t pos;
	pos.r=r;
	pos.c=c;
	if(cnt==0) king=pos;
	else
	ns.push_back(pos);
    };
    if(test)printf("<%d>",(int)ns.size());
    for(int i=1;i<=R;i++)
	for(int j=1;j<=C;j++)
	{
	    int (& d)[35][35]=dist[i][j];
	    for(int u=1;u<=R;u++)
		for(int v=1;v<=C;v++)
		{
		    d[u][v]=inf;
		}
	    queue<pos_t> q;
	    pos_t init;
	    init.r=i;
	    init.c=j;
	    d[i][j]=0;
	    q.push(init);
	    if(test)printf("<%d,%d>",i,j);
	    while(!q.empty())
	    {
		pos_t &e=q.front();
		q.pop();
		//if(e.step>=d[e.r][e.c])
		//   continue;
		for(int w=0;w<8;w++)
		{
		    pos_t x=e;
		    x.step++;
		    x.r+=nm[w][0];
		    x.c+=nm[w][1];
		    if(x.ok()==0) continue;
		    if(x.step>=d[x.r][x.c]) continue;
		    d[x.r][x.c]=x.step;
		    q.push(x);
		} 
	    }
	}
    for(int i=1;i<=R;i++)
	for(int j=1;j<=C;j++)
	{
	    dk[i][j]=inf;
	}
    
    queue<pos_t> q;
    pos_t &init=king;
    dk[init.r][init.c]=0;
    q.push(init);
    while(!q.empty())
    {
	pos_t &e=q.front();
	q.pop();
	//if(e.step>=d[e.r][e.c])
	//   continue;
	for(int w=0;w<8;w++)
	{
	    pos_t x=e;
	    x.step++;
	    x.r+=km[w][0];
	    x.c+=km[w][1];
	    if(x.ok()==0) continue;
	    if(x.step>=dk[x.r][x.c]) continue;
	    dk[x.r][x.c]=x.step;
	    q.push(x);
	} 
    }
    int nsum[35][35];
    int ub=inf;
    for(int i=1;i<=R;i++)
	for(int j=1;j<=C;j++)
	{
	    int sum=0;
	    for(int u=0;u<(int)ns.size();u++)
	    {
		pos_t &p=ns[u];
		sum+=dist[p.r][p.c][i][j];
		if(sum>inf) sum=inf;
	    }
	    nsum[i][j]=sum;
	    ub=min(ub,sum+dk[i][j]);

	     if(test)printf("<dk %d %d %d>",i,j,dk[i][j]);
	}
    if(test)printf("<%d>\n",ub);
    for(int i=1;i<=R;i++)
	for(int j=1;j<=C;j++)
	{
	    if(nsum[i][j]>ub) continue;
	    for(int u=1;u<=R;u++)
		for(int v=1;v<=C;v++)
		{
		    for(int w=0;w<(int)ns.size();w++)
		    {
			pos_t &p=ns[w];
			int delta=dk[u][v]+dist[p.r][p.c][u][v]+dist[u][v][i][j]- dist[p.r][p.c][i][j];
			ub=min(ub,nsum[i][j]+delta);
		    }
		}
	}
    printf("%d\n",ub);

    


       


    
    return 0;
}

