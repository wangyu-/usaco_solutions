/*
  ID: wangyu.1
  LANG: C++11
  TASK: calfflac
*/
#define TASKNAME "calfflac"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <deque>
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
const int test=0;
#else
const int test=0;
#endif
int R,C,P;
string in;

string in2;
int p[20000+5];
char to_lower(char a)
{
    if(a>='a'&&a<='z') return a;
    if(a>='A'&&a<='Z') return a-'A'+'a';
    return 0;
}
int dp[20000+5]={0};
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    char s[100];
    while(1)
    {
	if(scanf("%[^\n]",s)==-1) break; // can't use !=1 here, since sometimes we got 0
	scanf("%*c");
	in+=s;
	in+='\n';
    }
    //printf("%s\n",in.c_str());
    for(int i=0;i<in.length();i++)
    {
	char c=to_lower(in[i]);
	if(c!=0)
	{
	    in2+=c;
	    p[(int)in2.size()-1]=i;
	}
    }
    //printf("%s\n",in2.c_str());
    dp[0]=1;
    for(int i=1;i<in2.size();i++)
    {
	int left=i-dp[i-1]-1;
	dp[i]=1;
	if(in2[i]==in2[i-1])
	    dp[i]=2;
	if(left>=0&&in2[left]==in2[i])
	{
	    dp[i]=dp[i-1]+2;
	}
	//printf("<%d %d>",i,dp[i]);
    }
    int best=0;
    int pos;
    for(int i=0;i<in2.size();i++)
    {
	if(dp[i]>best)
	{
	    best=dp[i];
	    pos=i;
	}
    }
    int from=pos-best+1;int to=pos;
    //printf("<%d %d>",from,to);
    //printf("<%d %d>",p[from],p[to]);
    deque<char> q;
    for(int i=p[from];i<=p[to];i++)
    {
	//printf("%c",in[i]);
	q.push_back(in[i]);
    }
    while(1)
    {
	if(to_lower(q.front()==0))
	{
	    q.pop_front();
	}
	else
	{
	    break;
	}
    }
    while(1)
    {
	if(to_lower(q.back()==0))
	{
	    q.pop_back();
	}
	else
	{
	    break;
	}
    }
    printf("%d\n",best);
    for(auto c:q)
    {
	printf("%c",c);
    }
    printf("\n");


    return 0;
}

