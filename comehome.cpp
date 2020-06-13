/*
  ID: wangyu.1
  LANG: C++11
  TASK: comehome
*/
#define TASKNAME "comehome"

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

int mat[60][60];
int inf=10000*10000;
int ctoi(char a)
{
    if(a>='A'&&a<='Z')
    {
	return a-'A';
    }
    if(a>='a'&&a<='z')
    {
	return a-'a'+26;
    }
    assert(0==1);
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    for(int i=0;i<52;i++)
	for(int j=0;j<52;j++)
	{
	    mat[i][j]=inf;
	    if(i==j)
		mat[i][j]=0;
	}
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	char a[10],b[10];int len;
	scanf("%s %s %d",a,b,&len);
	if(test) printf("<%s %s %d>",a,b,len);
	int x=ctoi(a[0]);
	int y=ctoi(b[0]);
	mat[x][y]=min(mat[x][y],len);
	mat[y][x]=min(mat[y][x],len);
    }
    for(int k=0;k<52;k++)
	for(int i=0;i<52;i++)
	    for(int j=0;j<52;j++)
	    {
		int d=mat[i][k]+mat[k][j];
		if(d<mat[i][j])
		    mat[i][j]=d;
	    }
    int min_d=inf;
    int p;
    for(int i=0;i<25;i++)
    {
	if(mat[i][25]<min_d)
	{
	    min_d=mat[i][25];
	    p=i;
	}
    }
    printf("%c %d\n",p+'A',min_d);
    

    
    return 0;
}

