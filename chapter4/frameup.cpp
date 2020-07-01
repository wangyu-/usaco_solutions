/*
  ID: wangyu.1
  LANG: C++11
  TASK: frameup
*/
#define TASKNAME "frameup"

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
set<char> st;
char mp[30+5][30+5];
struct frame_t
{
    int l=9999,r=-1;
    int u=9999,d=-1;
}f[26+5];
char mat[30+5][30+5]={0};
int used[26]={0};
int used_cnt=0;
int res[26];
vector<string> fr;
int dfs(int a)
{
    if(st.find(a+'A')==st.end()) return 0;
    if(used[a]) return 0;
    int ok=1;
    for(int i=0;i<26;i++)
    {
	if(mat[a][i]) ok=0;
    }
    if(ok==0) return 0;
    used[a]=1;
    res[used_cnt]=a;
    used_cnt++;
    if(used_cnt==(int)st.size())
    {
	string tmp;
	for(int i=used_cnt-1;i>=0;i--)
	{
	    //printf("%c",res[i]+'A');
	    tmp+=res[i]+'A';
	}
	fr.push_back(tmp);
	//printf("\n");
	//printf("<found>");
	goto end;
    }
    char save[26];
    for(int i=0;i<26;i++)
    {	
	save[i]=mat[i][a];
	mat[i][a]=0;
    }
    for(int i=0;i<26;i++)
    {
	dfs(i);
    }
    for(int i=0;i<26;i++)
    {
	mat[i][a]=save[i];
    }
end:
    used[a]=0;
    used_cnt--;
    return 0;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int R,C;
    scanf("%d %d",&R,&C);
    for(int i=0;i<R;i++)
    {
	scanf("%s",mp[i]);
    }
    for(int i=0;i<R;i++)
    {
	for(int j=0;j<C;j++)
	{
	    char c=mp[i][j];
	    if(c=='.') continue;
	    st.insert(c);
	    frame_t &fm=f[c-'A'];
	    fm.l=min(fm.l,j);
	    fm.r=max(fm.r,j);
	    fm.u=min(fm.u,i);
	    fm.d=max(fm.d,i);
	}
    }
    for(auto e:st)
    {
	frame_t fm=f[e-'A'];
	for(int i=fm.l;i<=fm.r;i++)
	{
	    mat[e-'A'][mp[fm.u][i]-'A']=1;
	    mat[e-'A'][mp[fm.d][i]-'A']=1;
	}
	for(int i=fm.u;i<=fm.d;i++)
	{
	    mat[e-'A'][mp[i][fm.l]-'A']=1;
	    mat[e-'A'][mp[i][fm.r]-'A']=1;
	}
	mat[e-'A'][e-'A']=0;
    }
    for(int i=0;i<26;i++)
    {
	dfs(i);
	}
    sort(fr.begin(),fr.end());
    for(int i=0;i<(int)fr.size();i++)
    {
	printf("%s\n",fr[i].c_str());
    }
    return 0;
}

