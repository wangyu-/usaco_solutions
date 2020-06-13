/*
  ID: wangyu.1
  LANG: C++11
  TASK: lamps 
*/
#define TASKNAME "lamps"

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
const int LAMPS=100;
char lamps[LAMPS+5];
int n,c;
map<string,int> mp;
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    memset(lamps,-1,sizeof(lamps));
    scanf("%d",&n);
    scanf("%d",&c);
    while(1)
    {
	int t;
	scanf("%d",&t);
	if(t==-1)break;
	lamps[t]='1';
    }
    while(1)
    {
	int t;
	scanf("%d",&t);
	if(t==-1)break;
	lamps[t]='0';
    }
    for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	    for(int k=0;k<2;k++)
		for(int l=0;l<2;l++)
		{
		    char s[LAMPS+5];
		    s[n+1]=0;
		    int ok=1;
		    for(int x=1;x<=n;x++)
		    {
			int s1=i;
			int s2=(int)(x%2==1)*j;
			int s3=(int)(x%2==0)*k;
			int s4=((int)(x%3==1))*l;
			s[x]='0' + (1+s1+s2+s3+s4)%2;
			if(lamps[x]!=-1&& lamps[x]!=s[x])
			{
			    ok=0;
			    //    break;
			}
		    }
		    if(test)printf("%d%d%d%d<%s>\n",i,j,k,l,s+1);
		    
		    if(!ok) continue;
		    int cnt=i+j+k+l;
		    if(cnt<=c&&(c-cnt)%2==0)
		    {
			mp[s+1]=1;
		    }
		}
    if(mp.size()==0)
    {
	printf("IMPOSSIBLE\n");
	return 0;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
	printf("%s\n",it->first.c_str());
    }
    return 0;
}

