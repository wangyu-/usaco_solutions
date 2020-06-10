/*
  ID: wangyu.1
  LANG: C++11
  TASK: runround
*/
#define TASKNAME "runround"

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
int ok(int a)
{
    char s[30];
    sprintf(s,"%d",a);
    int len=strlen(s);
    int h[15]={0};
    int d[30];
    for(int i=0;i<len;i++)
    {
	h[s[i]-'0']++;
	d[i]=s[i]-'0';
	if(d[i]==0) return -1;
	if(h[s[i]-'0']>=2) return -1;
    }
    int used[15]={0};
    int pos=0;
    for(int i=0;i<len;i++)
    {
	pos=(pos+d[pos])%len;	
	if(used[pos]) return -1;
	used[pos]=1;
    }
    //if(used[pos]) return -1;
    return 1;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    scanf("%d",&n);
    while(n++)
    {
	if(ok(n)==1)
	{
	    printf("%d\n",n);
	    return 0;
	} 
    }
    return 0;
}

