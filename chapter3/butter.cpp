/*
  ID: wangyu.1
  LANG: C++11
  TASK: butter
*/
#define TASKNAME "butter"

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

int n,p,c;
int cp[500+5];

int mat[800+5][800+5];
int inf=1000*1000*1000;

#define likely(x) __builtin_expect(!!(x), 1) //gcc内置函数, 帮助编译器分支优化
#define unlikely(x) __builtin_expect(!!(x), 0)

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d %d",&n,&p,&c);
    for(int i=1;i<=n;i++)
    {
	scanf("%d",&cp[i]);
    }
    for(int i=1;i<=p;i++)
    {
	for(int j=1;j<=p;j++)
	{
	    mat[i][j]=inf;
	    if(i==j) mat[i][j]=0;
	}
    
    }
    for(int i=0;i<c;i++)
    {
	int a,b,l;
	scanf("%d %d %d",&a,&b,&l);
	mat[a][b]=mat[b][a]=l;
    }
    for(int k=1;k<=p;k++)
    for(int i=1;i<=p;i++)
    {
	if(mat[i][k]==inf) continue;
	for(int j=1;j<=i;j++)
	{
	    int tmp=mat[i][k]+mat[k][j];
	    if(tmp<mat[i][j])
	    {
		mat[i][j]=tmp;
	    }
	    mat[j][i]=mat[i][j];
	}
    }

    int best=inf;
    for(int i=1;i<=p;i++)
    {
	//int s=cp[i];
	int sum=0;
	for(int j=1;j<=n;j++)
	{
	    int b=cp[j];
	    sum+=mat[i][b];
	}
	if(sum<best)
	    best=sum;
    }
    printf("%d\n",best);

    
    
    
    return 0;
}

