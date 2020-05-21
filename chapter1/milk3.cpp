/*
  ID: wangyu.1
  LANG: C++11
  TASK: milk3
*/
#define TASKNAME "milk3"

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
int hh[21][21][21]={0};
struct milk_t
{
	int a[3]={0};
};
int value[21*3]={0};
int c[3];
void dfs(milk_t m)
{
    int *a=m.a;
    if(hh[a[0]][a[1]][a[2]]==1) return;
    hh[a[0]][a[1]][a[2]]=1;
    if(a[0]==0)
	    value[a[2]]=1;
    for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	{
	    if(i==j) continue;
	    if(a[i]==0) continue;
	    if(a[j]==c[j]) continue;
	    milk_t n=m;
	    int *b=n.a;
	    b[j]=a[j]+a[i];
	    b[i]=0;
	    if(b[j]>c[j])
	    {
		b[i]=b[j]-c[j];
		b[j]=c[j];
	    }
	    dfs(n);
	}
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    milk_t m;
    scanf("%d %d %d",c,c+1,c+2);
    m.a[2]=c[2];
    dfs(m);
    int cnt=0;
    for(int i=0;i<21*3;i++)
    {
	if(value[i])
	{
	    if(cnt) printf(" ");
	    printf("%d",i);
	    cnt++;
	}
    }
    printf("\n");

    
    return 0;
}
