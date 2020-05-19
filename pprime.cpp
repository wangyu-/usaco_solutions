/*
  ID: wangyu.1
  LANG: C++11
  TASK: pprime 
*/
#define TASKNAME "pprime"

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
int is_prime(int a)
{
    for(int i=2;i*i<=a;i++)
    {
	if(a%i==0) return 0;
    }
    return 1;
}
int get_pal1(int a,int d)
{
    char out[20];
//    out[0]=0;
    //char buf[100];
    char s[20];
    sprintf(s,"%%0%dd",d);
    sprintf(out,s,a);
    int len=strlen(out);
    reverse(out,out+len);
    sprintf(out+len,s,a);
    int r;
    sscanf(out,"%d",&r);
    return r;
}
int get_pal2(int a,int d)
{
    char out[20];
    char s[20];
    sprintf(s,"%%0%dd",d);
    sprintf(out,s,a);
    int len=strlen(out);
    reverse(out,out+len);
    sprintf(out+len-1,s,a);
    int r;
    sscanf(out,"%d",&r);
    return r;
}
vector<int> vec;
void gen(int a,int len)
{
    for(int i=1;i<=a;i++)
    {
	if(i%10==0) continue;
	int r1=get_pal1(i,len);
	if(is_prime(r1)) vec.push_back(r1);
	int r2=get_pal2(i,len);
	if(is_prime(r2)) vec.push_back(r2);
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    char buf[100];
    //printf("%d %d\n",get_pal1(9,2),get_pal2(9,2));
    //int n;
    int a,b;
    scanf("%d %d",&a,&b);
    gen(9,1);
    gen(99,2);
    gen(999,3);
    gen(9999,4);
    //gen(99999,5);
    sort(vec.begin(),vec.end());
    for(int i:vec)
    {
	if(i>=a&&i<=b) printf("%d\n",i);
    }

    return 0;
}
