/*
    YES PAIN YES GAIN
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define mset multiset
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e5+5;
const int mod=1e9+7;

double ans=0.0;
vi graph[N];
bool vis[N];

void dfs(int u,int p,double prob,double len)
{
    vis[u]=true;

    if(u!=1 && graph[u].size()==1) ans+=(len*prob);

    double m;
    (u==1) ? m=graph[u].size() : m=graph[u].size()-1 ;

    for(int v : graph[u])
    {
        if(v==p) continue;
        if(!vis[v])
        {
            dfs(v,u,prob/m,len+1);
        }
    }
}

void solve()
{
    int n;
    cin>>n;

    if(n==1)
    {
        long double res=1.0;
        printf("%.15lf",res);
        return;
    }

    for(int i=0,u,v;i<n-1;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1,1,1.0,0);

    printf("%.15lf",ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}