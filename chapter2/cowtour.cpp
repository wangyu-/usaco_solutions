/*
  ID: wangyu.1
  LANG: C++11
  TASK: cowtour
*/
#define TASKNAME "cowtour"

//#include <bits/stdc++.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
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

struct pos_t
{
    int x,y;
};
char mat[150+5][150+5];
pos_t p[150+5];
double d[150+5][150+5];
double f[150+5];
const double inf=100*9999.0*9999.0;
double dis(int i,int j)
{
    double a=abs(p[i].x-p[j].x);
    double b=abs(p[i].y-p[j].y);
    return sqrt(a*a+b*b);    
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	scanf("%d %d",&p[i].x,&p[i].y);
    }
    for(int i=0;i<n;i++)
    {
	scanf("%s",mat[i]);
    }
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<n;j++)
	{
	    d[i][j]=inf;
	    if(mat[i][j]=='1')
	    {
		d[i][j]=dis(i,j);
	    }
	    if(i==j)
	    d[i][j]=0;
	}
    }
    for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	    {
		double new_d=d[i][k]+d[k][j];
		if(new_d<d[i][j])
		    d[i][j]=new_d;	
	    }

    double max_d=0;
    for(int i=0;i<n;i++)
    {
	f[i]=0;
	for(int j=0;j<n;j++)
	{
	    if(d[i][j]!=inf)
	    {
		max_d=max(max_d,d[i][j]);
		f[i]=max(f[i],d[i][j]);
	    }
	    if(test)
		printf("<%f>",d[i][j]);
	}
	if(test)
	printf("\n");
    }
    double min_d=inf;
    for(int i=0;i<n;i++)
    {
	int x=i;;
	for(int j=0;j<n;j++)
	{
	    int y=j;      
	    if(d[x][y]==inf)
	    {
		double d1=dis(x,y);
		if(test)printf("<%f %f %f>\n",d1,f[x],f[y]);
		double d2=d1+f[x]+f[y];
		min_d=min(min_d,d2);
	    }
	}
    }
    max_d=max(max_d,min_d);
    printf("%.6f\n",max_d);

    
    return 0;
}

