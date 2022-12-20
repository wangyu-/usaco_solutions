#include <set>
#include <vector>
#include <set>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define pii pair<int, int>
#define pll pair<long, long>
#define mkp make_pair
int test = 0;

set<int> nb0[200000+5];
set<int> nb[200000+5];
int parent[200000+5];

int ssize(set<int> &s)
{
    return s.size();
}
int find(int i)
{
  return parent[i]==-1 ? i : parent[i]=find(parent[i]);
}
void link(int i, int j)
{
  parent[find(i)] = find(j);
}

void append(vector<int> &vec, vector<int> &other)
{
    for(auto a: other)
        vec.push_back(a);
}

int n,m;
void prt()
{
    for(int i=1;i<=n;i++) {
        printf("node %d, parent= %d ",i ,find(i));
        if(i==find(i)) printf("self!");
        printf("\n");
        if(find(i)!=i) continue; 
        for(auto node: nb[i]) {
            printf("<%d>", node);
        }
        printf("\n");
    }

}
int main() {

    memset(parent,-1,sizeof(parent));
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        nb0[a].insert(b);
        nb0[b].insert(a);

        nb[a].insert(b);
        nb[b].insert(a);
    }

    if(test)prt();

    long long cnt=0;
    for(int i=1;i<=n;i++) {

        
        //all nb become complete graph .. <del>just count all of them</del>
        
        //for all complete graph, that includes i 
        // merge into a large complete graph
        // (include the newly formed afew lines above)

        set<int> all_parents; 
        int idx=-1;
        int larges_size=-1;
        for(auto node: nb[i]) {
            if(node > i) break;
            int p= find(node);
            //if(p== node) {
            if(ssize(nb[p]) > larges_size) {
                larges_size= ssize(nb[p]);
                idx=p;
            }
            all_parents.insert(p); //lots of dumps, dedup
            //}
        }
        all_parents.insert(find(i));  // itself's
        if(test)printf("[idx=%d]",idx);
        if(idx!=-1) {
            for(auto p: all_parents) {
                if(p==idx) continue;
                if(test)printf("[%d]\n",p);
                link(p,idx);
                //parent[p]=idx;
                for(auto node: nb[p]){
                    if(node > i) {
                        nb[idx].insert( node);
                    }
                }
                nb[p].clear();
            }
            assert(nb[idx].find(i)!=nb[idx].end());
            long long exclude_cnt=0;
            for(auto & n : nb0[i]) {
                if(n>i  &&  nb[idx].find(n)!=nb[idx].end() ) {
                    exclude_cnt++;
                }
            }
            while( !nb[idx].empty()  &&  * nb[idx].begin() < i) {
                nb[idx].erase(nb[idx].begin());
            }
            cnt+= nb[idx].size() -1;
            /*
            for(auto it= ++nb[idx].find(i) ;it!=nb[idx].end();it++ )
            {
                int node=*it;
                cnt++;
                if(test)printf("<new edge %d,%d!!!!>\n", i,node);
                //}
            }*/
            cnt-=exclude_cnt;
        }
        if(test){
            printf("----after %d----\n",i);
            prt();
        }
    }
    
    printf("%lld\n",cnt);
    return 0;
}
