#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;
#define NMAX 100000

struct Info{
    int from;
    int to;
};

int n,m,q;
int parent[NMAX+1];
long long cnt[NMAX+1];

int getParent(int a) {
    if (parent[a] == a){
        return a;
    }else{
        return parent[a] = getParent(parent[a]);
    } 
}

void punion(int a, int b){
    int aRoot = getParent(a);
    int bRoot = getParent(b);

    if(aRoot !=bRoot) {
        parent[aRoot] = bRoot;
        cnt[bRoot] += cnt[aRoot];       
    }
}

int main()
{
    scanf(" %d %d %d",&n,&m,&q);

    int x,y,z;
    stack<int> del;
    Info adj[NMAX+1];
    bool flag[NMAX+1];

    //union 배열 초기화
    for(int i=0;i<=n;i++){
        parent[i]=i;
        cnt[i]=1;
        flag[i] = false;
    }

    for(int i=1;i<=m;i++){
        scanf(" %d %d",&x,&y);
       adj[i].from = x;
       adj[i].to = y;
    }

    for(int i=1;i<=q;i++){
        scanf(" %d",&z);
        flag[z] = true;
        del.push(z);
    }

    for (int i = 1; i <= m; i++) {
        if (flag[i] == false) {
            punion(adj[i].from, adj[i].to);
        }
    }

    long long ans = 0;
    while(!del.empty()){
        int add = del.top();
        del.pop();

        if (getParent(adj[add].from) != getParent(adj[add].to)) {
            ans += (cnt[getParent(adj[add].from)] * cnt[getParent(adj[add].to)]);
        }

        punion(adj[add].from, adj[add].to);
    }
    printf("%lld\n", ans);
}