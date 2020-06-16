/*
  ID: wangyu.1
  LANG: C++11
  TASK: contact 
*/
#define TASKNAME "contact"

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

int mask[20];
char s[200*1000+100];
int h[20][1024*4+100]={0};
void prt_bin(int num,int len)
{
    char res[len+5]={0};
    for(int i=0;i<len;i++)
    {
	res[len-1-i]='0'+num%2;
	num/=2;	
    }
    printf("%s",res);
}
string ss;
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    mask[0]=0;
    for(int i=1;i<=12;i++)
    {
	mask[i]=(mask[i-1]<<1)+1;
    }
    int a,b,n;
    scanf("%d %d %d",&a,&b,&n);
    while(1)
    {
	if(scanf("%s",s)!=1) break;
	ss+=s;
    }
    strcpy(s,ss.c_str());
    int len=strlen(s);
    for(int i=a;i<=b;i++)
    {
	if(len<i) continue;
	int v=0;
	for(int j=0;j<i;j++)
	{
	    v*=2;
	    v+=s[j]-'0';
	}
	h[i][v]++;
	for(int j=i;j<len;j++)
	{
	    v*=2;
	    v+=s[j]-'0';
	    v&=mask[i];
	    h[i][v]++;
	}
    }
    map<int,int> mp;
    for(int i=a;i<=b;i++)
    {
	for(int j=0;j<=mask[i];j++)
	{
	    int t=h[i][j];
	    if(t>0)
	    {
		if(mp.find(t)==mp.end())
		{
		    mp[t]=0;
		}
		mp[t]++;
	    }
	}
    }
    int cnt=0;
    for(auto it=mp.rbegin();it!=mp.rend() &&cnt<n;it++,cnt++)
    {
	int freq=it->first;
	int cnt2=0;
	printf("%d\n",freq);
	for(int i=a;i<=b;i++)
	{
	    for(int j=0;j<=mask[i];j++)
	    {
		int t=h[i][j];
		if(t==freq)
		{
		    if(cnt2&&cnt2%6==0) printf("\n");
		    if(cnt2%6!=0) printf(" ");
		    
		    prt_bin(j,i);
		    cnt2++;
		}
	    }
	}	
	printf("\n");
	//printf("<%d>",it->first);

    }
    //printf("\n");
    
    return 0;
}

