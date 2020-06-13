/*
  ID: wangyu.1
  LANG: C++11
  TASK: zerosum
*/
#define TASKNAME "zerosum"

//#include <bits/stdc++.h>

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
char ops[]=" +-";
void verify(char *s,int n)
{
    char s2[30];
    for(int i=0;i<n;i++)
    {
	s2[i*2]='1'+i;
	if(i!=n-1)
	    s2[i*2+1]=s[i];
    }
    s2[n+n-1]=0;
    char s3[30];
    int j=0;
    for(int i=0;s2[i];i++)
    {
	if(s2[i]!=' ')
	    s3[j++]=s2[i];
    }
    s3[j]=0;
    //printf("%s\n",s3);
    int sum;
    sscanf(s3,"%d",&sum);
    for(int i=0;s3[i];i++)
    {
	int flag;
	if(s3[i]=='+'||s3[i]=='-')
	{
	    if(s3[i]=='+') flag=1;
	    else flag=-1;
	    int t;
	    sscanf(s3+i+1,"%d",&t);
	    sum+=flag*t;
	}
	
    }
    if(sum==0)
	printf("%s\n",s2);


}
void rec(char *s,int idx,int l)
{
    if(idx==l)
    {
	s[idx]=0;
	verify(s,l+1);
	return;
    }
    for(int i=0;i<3;i++)
    { 
	s[idx]=ops[i];
	rec(s,idx+1,l);
    }
}

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    char s[20];
    scanf("%d",&n);
    rec(s,0,n-1);
    

    return 0;
}

