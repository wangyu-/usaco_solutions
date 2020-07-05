/*
  ID: wangyu.1
  LANG: C++11
  TASK: schlnet
*/
#define TASKNAME "schlnet"

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
vector<int> nbs[100+5];
vector<int> inv[100+5];
int mat[100+5][100+5]={0};
int mat2[100+5][100+5]={0};
int parent[100+5]={0};
int find(int i)
{
  return parent[i]==0 ? i : parent[i]=find(parent[i]);
}

void link(int i, int j)
{
    if(find(i)==find(j)) return;
    //if (rand() % 2) swap(i,j);
  parent[find(j)] = find(i);
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
	for(;;)
	{
	    int t;
	    scanf("%d",&t);
	    if(t==0) break;
	    nbs[i].push_back(t);
	    inv[t].push_back(i);
	    mat[i][t]=1;
	}
    }
    for(int i=1;i<=n;i++)
	mat[i][i]=1;
    for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
		if(mat[i][k]&&mat[k][j])
		    mat[i][j]=1;
	    }
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
	    if(mat[i][j]&&mat[j][i])
	    {
		link(i,j);
	    }
	}
    vector<int> ns;
    for(int i=1;i<=n;i++)
    {
	if(find(i)!=i) continue;
	ns.push_back(i);
    }
    for(int i=0;i<ns.size();i++)
	for(int j=0;j<ns.size();j++)
	{
	    int ii=ns[i];
	    int jj=ns[j];
	}
    int ans1=0;
    int ans_tmp=0;
    for(int i=0;i<ns.size();i++)
    {
	int cnt=0;
	int cnt2=0;
	for(int j=0;j<ns.size();j++)
	{
	    int ii=ns[i];
	    int jj=ns[j];
	    if(mat[jj][ii]) cnt++;
	    if(mat[ii][jj]) cnt2++;
	}
	if(cnt==1) ans1++;	
	if(cnt2==1) ans_tmp++;	
    }
    int ans2=max(ans1,ans_tmp);
    if(ns.size()==1) ans2=0;
    printf("%d\n",ans1); 
    printf("%d\n",ans2); 
	 


   
    return 0;
}

