/*
    YES PAIN YES GAIN
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

//int pow[N]
const int N=2e5+5;
const int mod=1e9+7;

bool flag;
int ans=0;
vi graph[N],degree(N,0);
vector<bool> vis(N,false);

void dfs(int u)
{
    if(degree[u]!=2) flag=false;
    vis[u]=true;

    for(int v : graph[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

void solve()
{
    int n,m,a,b;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
        degree[a]++;
        degree[b]++;
    }

    for(int i=1;i<=n;i++)
    {
        flag=true;
        if(!vis[i]) 
        {
            dfs(i);
            if(flag) ans++;
        }
    }

    cout<<ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    clock_t t1,t2;
    t1=clock();

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    t2=clock();
    cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
    #endif

    return 0;
}