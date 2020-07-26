/*
  ID: wangyu.1
  LANG: C++11
  TASK: wormhole
*/
#define TASKNAME "wormhole"

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
struct pnt_t
{
	int x,y;
	int right=-1;
	int pair;
	int visited1;
	int visited2;
};
int n;
vector<pnt_t> pnts;
bool get_bit(int a,int idx)
{
	return (a>>idx)&0x1;
}
vector<int> first;
vector<int> second0;
int used[6+5]={0};
int per[6+5];
vector<vector<int> > match;
void swap(int &a,int &b)
{
	int t=a;
	a=b;b=t;
}
void dfs(int depth)
{
	if(depth==n/2)
	{
		for(int i=0;i<n/2;i++)
		{
			if(first[i]>second0[per[i]]) return ;
		}
		match.emplace_back();
		vector<int> &m=match.back();
		for(int i=0;i<n/2;i++)
		{
			m.push_back(first[i]);
			m.push_back(second0[per[i]]);
		}
		return ;
	}

	for(int i=0;i<n/2;i++)
	{
		if(used[i]) continue;
		used[i]=1;
		per[depth]=i;
		dfs(depth+1);
		used[i]=0;
	}
}
int exist_loop(vector<int> &m)
{
	//printf("------------\n");
	for(int i=0;i<m.size();i+=2)
	{
		pnts[m[i]].pair=m[i+1];
		pnts[m[i+1]].pair=m[i];
	}
	for(int i=0;i<n;i++)
	{
		//printf("<%d>",i);
		for(int j=0;j<n;j++)
		{
			pnts[j].visited1=0;
			pnts[j].visited2=0;
		}
		int p=i;
		pnts[p].visited1=1;
		for(;;)
		{
			p=pnts[p].pair;
			if(pnts[p].visited2) return 1;
			pnts[p].visited2=1;
			if(pnts[p].right==-1) break;
			p=pnts[p].right;
			if(pnts[p].visited1) return 1;
			pnts[p].visited1=1;
		}
	}
	return 0;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	    pnts.emplace_back();
	    int x,y;
	    scanf("%d %d",&x,&y);
	    pnts.back().x=x;
	    pnts.back().y=y;
    }
    for(int i=0;i<n;i++)
    {
	    int last_best_x=1000*1000*1000+1;
	    for(int j=0;j<n;j++)
	    {
		    if(pnts[j].y!=pnts[i].y) continue;
		    if(pnts[j].x<=pnts[i].x) continue;
		    if(pnts[j].x<last_best_x)
		    {
			    pnts[i].right=j;
			    last_best_x=pnts[j].x;
		    }
	    }
	    //printf("<%d>",pnts[i].right);
    }
    //printf("\n");
    for(int i=0;i<(1<<n);i++)
    {
	    int one_cnt=0;
	    for(int j=0;j<n;j++)
	    {
		    if(get_bit(i,j))
			    one_cnt++;
	    }
	    if(one_cnt!=n/2) continue;
	    first.clear();
	    second0.clear();
	    for(int j=0;j<n;j++)
	    {
		    if(get_bit(i,j))
		    {
			    first.push_back(j);
		    }
		    else second0.push_back(j);
	    }
	    dfs(0);
    }
    /*
    for(int i=0;i<match.size();i++)
    {
	    for(int j=0;j<match[i].size();j+=2)
	    {
		    if(match[i][j]>match[i][j+1])
		    {
			    swap(match[i][j],match[i][j+1]);
		    }
	    }
    }*/
    //sort(match.begin(),match.end());
    //auto it=unique(match.begin(),match.end());
    //match.erase(it,match.end());
    if(test)
    {
	    printf("<%d>\n",(int)match.size());
	    for(int i=0;i<match.size();i++)
	    {
		    for(int j=0;j<match[i].size();j++)
		    {
			    printf("<%d>",match[i][j]);
		    }
		    printf("\n");
	    }
    }
    int ans=0;
    for(int i=0;i<match.size();i++)
    {
	    if(exist_loop(match[i])) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
