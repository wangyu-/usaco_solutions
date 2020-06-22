/*
  ID: wangyu.1
  LANG: C++11
  TASK: heritage
*/
#define TASKNAME "heritage"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
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

char in[30];
char pre[30];

struct node_t
{
    node_t *left=0,*right=0;
    char c;
}*root;
    
void dfs(node_t * &node, int l,int r,int a,int b)
{
    if(l==r) {node=0;return;}
    node=new node_t;
    char &c=node->c;
    c=pre[l];
    if(l==r-1)
    {
	return ;
    }
    int i;
    for(i=a;i<b;i++)
    {
	if(in[i]==c) break;
    }
    dfs(node->left,l+1,l+1+i-a,a,i);  
    dfs(node->right,l+1+i-a,r,i+1,b);  
}
void dfs2(node_t * &node)
{
    if(node==0) return ;
    dfs2(node->left);
    dfs2(node->right);
    printf("%c",node->c);
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif

    scanf("%s",in);
    scanf("%s",pre);
    int len=strlen(in);
    dfs(root,0,len,0,len);
    dfs2(root);
    printf("\n");


    

    
    return 0;
}

