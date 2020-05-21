/*
ID: wangyu.1
LANG: C++11
TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int get_len(char * s,int p,int n,int inc)
{
	int cnt=0;
	char c_current='w';
	for(int i=p;i<p+n&&i>p-n;i+=inc)
	{
		int idx=(i+n)%n;
		//printf("<%d,%d>",idx,cnt);
		if(s[idx]=='t') return cnt;
		if(s[idx]==c_current||s[idx]=='w') {cnt++;s[idx]='t';}
		else if(c_current=='w') {c_current=s[idx];cnt++;s[idx]='t';}
		else return cnt;
	}
	return cnt;
}
int main() 
{
#ifndef TEST
	freopen ("beads.in", "r",stdin);
	freopen ("beads.out", "w",stdout);
#endif

	int n;
	scanf("%d",&n);
	char ori[1000];
	char buf[1000];
	scanf("%s",ori);
	assert(n==strlen(ori));
	int max=-1;
	for(int i=0;i<n;i++)
	{
		strcpy(buf,ori);
		int cnt1=get_len(buf,i,n,1);
		//printf("cnt1=%d\n",cnt1);
		int cnt2=get_len(buf,(n+i-1)%n,n,-1);
		//printf("cnt2=%d\n",cnt2);
		if(cnt1+cnt2>max) max=cnt1+cnt2;
		//printf("<%d,%d>\n",cnt1,cnt2);
		//printf("=======\n");
	}
	printf("%d\n",max);
	return 0;
}

