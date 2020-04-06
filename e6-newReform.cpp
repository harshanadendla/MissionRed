//sigguledu...red laga not thinking.....dfs lo we r providing edges...
//traverse itself meant we r rpoviding an edge to the visiting node....so point antha...
//except first node....every other edge is getting feeded...so just check if we can come back to the node
//from which we have started dfs....when is that psbl....? when there is a cycle in the graph
//when there is a cycle....if u start from any one of the nodes involved in the cycle...u will 
//definitely come back to the node from which u have started dfs...
//so if cycle unte...every node can be feeded....else the first node remains unsaatisfied
//so...check for cycle in every connected component and update ans accordingly...howle

/*
    YES PAIN YES GAIN
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T> using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
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

const int N=1e5+5;
const int M=3e5;
const int mod=1e9+7;

bool flag;
vi graph[N];
char color[N];

void dfs(int u,int p)
{
    color[u]='g';

    for(int v : graph[u])
    {
        char c=color[v];
        if(c=='b' || v==p) continue;
        if(c=='g') flag=true;
        if(c=='w') dfs(v,u);
    }

    color[u]='b';
}

void solve()
{
    mem(color,'w');
    int n,m,a,b,ans=0;

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    for(int i=1;i<=n;i++)
    {
        flag=false;
        if(color[i]=='w') 
        {
            dfs(i,i);
            ans+=(flag) ? 0 : 1 ;
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