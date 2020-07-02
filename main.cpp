/*
  ID: wangyu.1
  LANG: C++11
  TASK: ride
*/
#define TASKNAME "ride"

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

int cal(char *s)
{
    int res=1;
    for(int i=0;s[i];i++)
    {
	res*=s[i]-'A'+1;
	res%=47;
    }
    return res;

}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    char s1[10],s2[10];
    scanf("%s",s1);
    scanf("%s",s2);
    int r1=cal(s1),r2=cal(s2);
    if(r1==r2)
    {
	printf("GO\n");
    }
    else
    {
	printf("STAY\n");
    }
    return 0;
}

