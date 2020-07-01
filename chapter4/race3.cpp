/*
  ID: wangyu.1
  LANG: C++11
  TASK: race3
*/
#define TASKNAME "race3"

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
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif

int max_n;
char mat[50+5][50+5]={0};
char mat_bak[50+5][50+5];

void backup()
{
    memcpy(mat_bak,mat,sizeof(mat));
}
void restore()
{
    memcpy(mat,mat_bak,sizeof(mat));
}
void del_node(int x)
{
    for(int i=0;i<=max_n;i++)
    {
	mat[x][i]=mat[i][x]=0;
    }
}
//set<int> visited;
char v1[50+5];
char v2[50+5];
void cv(char * visited)
{
    memset(visited,0,sizeof(char)*(50+5));
}
void dfs(int x,int inv,char * visited)
{
    if(visited[x])
	return ;
    visited[x]=1;
    for(int i=0;i<=max_n;i++)
    {
	if(!inv)
	{
	    if(mat[x][i]) dfs(i,inv,visited);
	} 
	else
	{
	    if(mat[i][x]) dfs(i,inv,visited);
	}
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int idx=0;
    for(;;idx++)
    {
	if(test) printf("<%d>",idx);
	while(1)
	{
	    int t;
	    scanf("%d",&t);
	    if(test) printf("[%d]",t);
	    if(t==-1) goto end;
	    max_n=idx;
	    if(t==-2) break;
	    mat[idx][t]=1;
	}
	if(test)printf("\t");
    }
end:
    if(test)printf("<max_n=%d>\n",max_n);
    backup();
    vector<int> uv;
    for(int i=1;i<max_n;i++)
    {
	del_node(i);
	cv(v1);
	dfs(0,0,v1);
	if(!v1[max_n])
	    uv.push_back(i);
	restore();
    }
    printf("%d",(int)uv.size());
    vector<int> sp;
    for(int i=0;i<(int)uv.size();i++)
    {
	printf(" %d",uv[i]);
	int x=uv[i];	
	//if(mat[x][x]) continue;
	cv(v1);
	v1[x]=1;
	cv(v2);
	dfs(0,0,v1);
	dfs(x,0,v2);
	int ok=1;
	//if(test)printf("now i=%d\n",x);
	for(int j=0;j<=max_n;j++)
	{
	    if(j==x) continue;
	    if(v1[j]==0&&v2[j]==0) {ok=0; if(0)printf("<<<%d>>>",j);}
	    if(v1[j]==1&&v2[j]==1) {ok=0; if(0)printf("{{{%d}}}",j);}
	    
	}
	if(ok) sp.push_back(x);
    }
    printf("\n");

    printf("%d",(int)sp.size());
    for(int i=0;i<(int)sp.size();i++)
    {
	printf(" %d",sp[i]);
    }
    printf("\n");
    

    return 0;
}

