/*
  ID: wangyu.1
  LANG: C++11
  TASK: twofive
*/
#define TASKNAME "twofive"

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
#include <typeinfo>
#include <iostream>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif

int n;

const int size=4;
int a[size+1][size];
int *d=(int*)a;
int used[size*size+5]={0};

int cnt=0;

int rk[size*size+5]={0};
int choice[size*size];

struct trie_t
{
    int cnt=0;
    trie_t *c[size*size]={0};
    void insert(int *s)
    {
	if(*s==0) return ;
	cnt++;
	int idx=*s-1;
	if(c[idx]==0)
	{
	    c[idx]=new trie_t;
	}
	c[idx]->insert(s+1);
    }
    int query0(int *s)
    {
	if(*s==0 )
	{
	    printf("<<result=%d>>\n",cnt);
	    return cnt;
	}
	int idx=*s-1;
	if(c[idx]==0) {printf("<<result=-1>>\n");return -1;}
	return c[idx]->query0(s+1);
    }
    int query(int *s)
    {
//	printf("123123123");
	for(int i=0;s[i];i++)
	{
	    printf("<%d>",s[i]);
	}
	return query0(s);
    }
}root;
/*
int ok()
{
    for(int i=0;i<size;i++)
    {
	for(int j=1;j<size;j++)
	{
	    if(a[i][j]<=a[i][j-1]) return 0;
	    if(a[j][i]<=a[j-1][i]) return 0;
	}
    }
    return 1;
    }*/
int ok(int r,int c)
{
    if(r>0&&a[r-1][c]!=-1)
    {
	if(a[r-1][c]>=a[r][c]) return 0;
    }
    if(c>0&&a[r][c-1]!=-1)
    {
	if(a[r][c-1]>=a[r][c]) return 0;
    }
    if(r+1<size&&a[r+1][c]!=-1)
    {
	if(a[r+1][c]<=a[r][c]) return 0;
    }
    if(c+1<size&&a[r][c+1]!=-1)
    {
	if(a[r][c+1]<=a[r][c]) return 0;
    }
    return 1;
}

void dfs(int idx)
{
    //int idx=choice[idx0];
    if(idx==size*size)
    {
	
	if(0)
	{
	    printf("-----cnt=%d------\n",cnt);
	    for(int i=0;i<size;i++)
	    {
		for(int j=0;j<size;j++)
		{
		    printf("<%02d>",a[i][j]);
		}
		printf("\n");
	    }
	}
	d[idx]=0;
	root.insert(d);
	cnt++;
	if(cnt%10000==0) printf("%d\n",cnt);
	//if(root.cnt%1000==0) printf("%d\n",root.cnt);
	return;
    }
    for(int i=1;i<=size*size;i++)
    {
	int r=idx/size;
	int c=idx%size;
	if(used[i]) continue;
	if((size-r)*(size-c)>size*size-i+1) continue;
	if((r+1)*(c+1)>i) continue;
	used[i]=1;
	a[r][c]=i;
	if(ok(r,c))
	    dfs(idx+1);
	a[r][c]=-1;
	used[i]=0;
    }
}
int cmp1(int a,int b)
{
    return rk[a]<rk[b];
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    //d[size*size]=0;
    for(int idx=0;idx<size*size;idx++)
    {
	choice[idx]=idx;
	int r=idx/size;
	int c=idx%size;
	for(int i=1;i<=size*size;i++)
	{
	    if((size-r)*(size-c)>size*size-i+1) continue;
	    if((r+1)*(c+1)>i) continue;
	    rk[idx]++;
	}
    }
    sort(choice,choice+size*size,cmp1);
    for(int i=0;i<size*size;i++)
    {
	printf("<%d>",rk[i]);
    }
    printf("\n");
    for(int i=0;i<size*size;i++)
    {
	printf("<%d>",choice[i]);
    }
    printf("\n");
    memset(a,-1,sizeof(a));
    //a[0][0]=1;
    //used[1]=1;
    //a[size-1][size-1]=size*size;
    //used[size*size]=1;
    dfs(0);
    printf("%d\n",cnt);
    {
	int q[]={0};
	root.query(q);
    }
    {
	int q[]={1,0};
	root.query(q);
    }
    {
	int q[]={1,2,0};
	root.query(q);
    }
    {
	int q[]={1,3,0};
	root.query(q);
    }
    {
	int q[]={1,4,0};
	root.query(q);
    }
    {
	int q[]={1,5,0};
	root.query(q);
    }
    while(1)
    {
	int q[100]={0};
	int idx=0;
	while(1)
	{
	    scanf("%d",q+idx);
	    if(q[idx]==0)
	    {
		root.query(q);
		break;
	    }
	    idx++;
	}
    }

    return 0;
}

