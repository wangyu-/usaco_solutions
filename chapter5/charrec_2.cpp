/*
  ID: wangyu.1
  LANG: C++11
  TASK: charrec
*/
#define TASKNAME "charrec"

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

const int inf=1000*1000;

char cl[]=" abcdefghijklmnopqrstuvwxyz";

char font[27][20][20+5];

int n;
char in[1200+5][20+5];

char diff[27][20][1200];

int cal1(int idx,int start)
{
    int cnt=0;
    for(int i=0;i<20;i++)
    {
	cnt+=diff[idx][i][start+i];
	//if(cnt>120) return cnt;
    }
    return cnt;
}
int cal_miss(int idx,int start)
{
    int best=9999;
    for(int miss=0;miss<20;miss++)
    {
	int cnt=0;
	for(int i=0;i<19;i++)
	{
	    int ii=i;
	    if(i>=miss) ii++;
	    cnt+=diff[idx][ii][start+i];
	    //if(idx==1&&start==0) printf("<%d %d>\n",ii,i);
	}
	//if(idx==1&&start==0) printf("<%c %d>\n",cl[idx],cnt);
	best=min(best,cnt);
    }
    return best;
}
int cal_dup(int idx,int start)
{
    int best=9999;
    for(int dup=0;dup<20;dup++)
    {
	int cnt=0;
	for(int i=0;i<21;i++)
	{
	    int ii=i;
	    if(dup==i) continue;
	    if(dup<i) ii--;
	    cnt+=diff[idx][ii][start+i];
	    //if(idx==1&&start==0) printf("<%d %d>\n",ii,i);
	}
	best=min(best,cnt);
    }
    return best;
}
int cal_loop(int start,int len,int &score)
{
    int best=9999;
    int idx=-1;
    for(int i=0;i<27;i++)
    {
	int r;
	if(len==19)r=cal_miss(i,start);
	else if(len==20) r=cal1(i,start);
	else r=cal_dup(i,start);
	//else assert(0==1);
	if(r<best)
	{
	    best=r;
	    idx=i;
	    score=best;
	}
    }
    return idx;
}
int get_min(int a,int b,int c)
{
    return min(a,min(b,c));
}
struct rec_t
{
    int len=0;
    int score=0;
    char c='#';
};
rec_t rs[1200+5][3];
int mat[1200+5][1200+5];
int pre[1200+5];
int dij(int s,int t)
{
    int d[1200+5];
    int used[1200+5]={0};
    for(int i=0;i<=n;i++)
    {
	d[i]=inf;
    }
    d[s]=0;
    while(1)
    {
	int best=inf;
	int p=-1;
	for(int i=0;i<=n;i++)
	{
	    if(used[i]==1) continue;
	    if(d[i]<best)
	    {
		best=d[i];
		p=i;
	    }
	}
	if(p==-1) break;
	used[p]=1;
	for(int i=0;i<=n;i++)
	{
	    if(used[i])  continue;
	    if(mat[p][i]+d[p]<d[i])
	    {
		d[i]=mat[p][i]+d[p];
		pre[i]=p;
	    }
	}
    }
    return d[t];
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    auto fp=fopen("font.in","r");
    int tmp;
    fscanf(fp,"%d",&tmp);
    assert(tmp==540); for(int i=0;i<540;i++)
    {
	fscanf(fp,"%s",font[i/20][i%20]);
    }
    for(int i=1;i<=1;i++)
	for(int j=0;j<20;j++)
	{
	    //if(test)printf("%s\n",font[i][j]);
	}
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {	
	scanf("%s",in[i]);
    }
    for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	{
	    mat[i][j]=inf;
	}
    for(int i=0;i<540;i++)
    {
	for(int j=0;j<n;j++)
	{
	    char &c=diff[i/20][i%20][j];
	    for(int k=0;k<20;k++)
	    {
		if(font[i/20][i%20][k]!=in[j][k])
		    c++;
	    }
	}
    }
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<3;j++)
	{
	    if(i+19+j<=n)
	    {
		int score=9999;
		int r=cal_loop(i,19+j,score);
		rs[i][j].len=19;
		rs[i][j].score=score;
		rs[i][j].c=cl[r];
		mat[i][i+19+j]=score;
		if(score>120)
		    rs[i][j].c='?';
	    }
	}
    }
    if(test)
	for(int i=0;i+19<=n;i++)
	{
	    for(int j=0;j<3;j++)
	    {
		rec_t &r=rs[i][j];
		printf("<%d %d %c>",i,r.score,r.c);
	    }
	    printf("\n");
	}
    int r=dij(0,n);
    //printf("dis=%d\n",r);
    int x=n;
    string res;
    for(;x!=0;x=pre[x])
    {
	//printf("<%d %d>",x,pre[x]);
	res.push_back(rs[pre[x]][x-pre[x]-19].c);
    }

    reverse(res.begin(),res.end());
    printf("%s\n",res.c_str());

    
   
    return 0;
}

