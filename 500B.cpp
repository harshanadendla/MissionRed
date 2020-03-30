#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

int n,m,q,a,b,cc=0;
vector<bool> vis(400400,false);
vector<int> graph[400400];

void dfs(int u)
{
    vis[u]=true;
    for(int v : graph[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>n>>m>>q;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        graph[a].pb(n+b);
        graph[n+b].pb(a);
    }
    
    for(int i=1;i<=n+m;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cc++;
        }
    }
    cout<<cc-1;
    return 0;
}