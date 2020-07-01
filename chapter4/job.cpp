/*
  ID: wangyu.1
  LANG: C++11
  TASK: job
*/
#define TASKNAME "job"

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

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n,m1,m2;
    scanf("%d %d %d",&n,&m1,&m2);
    vector<int> a;
    vector<int> b;
    for(int i=0;i<m1;i++)
    {
	int t;
	scanf("%d",&t);
	for(int j=1;j<=n;j++)
	    a.push_back(t*j);
    }
    for(int i=0;i<m2;i++)
    {
	int t;
	scanf("%d",&t);
	for(int j=1;j<=n;j++)
	    b.push_back(t*j);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    a.resize(n);
    b.resize(n);
    reverse(b.begin(),b.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
	if(test) printf("<%d %d>",a[i],b[i]);
	ans=max(ans,a[i]+b[i]);
    }
    printf("%d %d\n",a[a.size()-1],ans);
    return 0;
}

