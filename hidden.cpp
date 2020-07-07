/*
  ID: wangyu.1
  LANG: C++11
  TASK: hidden
*/
#define TASKNAME "hidden"

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
char s[100000+5];
//int len[100000+5];

int rk[100000];
int rk2[100000];
int sa[100000];

int w;
int cmp1(int x,int y)
{
    if(rk[x]==rk[y]) return rk[(x+w)%n]<rk[(y+w)%n];
    else return rk[x]<rk[y];
}
int eq1(int x,int y)
{
    return rk[x]==rk[y]&&rk[(x+w)%n]==rk[(y+w)%n];
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    
    scanf("%d",&n);
    string s0;
    while(1)
    {
	char buf[80];
	if(scanf("%s",buf)!=1) break;
	s0+=buf;
    }
    s[0]=0;
    strcat(s,s0.c_str());
    //strcat(s,s0.c_str());
    for(int i=0;i<n;i++)
	rk[i]=s[i]-'a';
    for(w=1;w<n;w*=2)
    {
	for(int i=0;i<n;i++)
	    sa[i]=i;
	sort(sa,sa+n,cmp1);
	int idx=0;
	for(int i=0;i<n;i++)
	{
	    if(i==0||eq1(sa[i],sa[i-1]))
		rk2[sa[i]]=idx;
	    else
		rk2[sa[i]]=++idx;
	}
	memcpy(rk,rk2,sizeof(int)*n);
    }
    for(int i=0;i<n;i++)
    {
	if(rk[i]==0)
	{
	    printf("%d\n",i);
	    break;
	}
	//printf("<%d>",rk[i]);
    }
    //printf("\n");




    return 0;
}

