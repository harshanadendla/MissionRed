//qstn lo asked is...a bridge...which when removed...makes the tree into 2 dif cmpnts in which
//one of them contains all the reds and the other contains all the blues...so...each subtree dfs chesi...check if it
//contains only all reds or only all blues...if so...ans++
//while dfsing a subtree...first add the color of the node itself to the subtree..coz it needs to report to its parent
//ippudu....once u have finidhes dfsing in one branch of a subT of a node...now add up all the brought in reds and blues to the 
//subtree and continue for the next branch...why adding... ? as i said before..each node is responsible for reporting to its
//parent

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

const int N=1e5;
const int M=3e5+5;
const int mod=1e9+7;

int n;
int ans;
int reds,blues;
int col[M];
vi graph[M];
int subT[M][3];

void dfs(int u,int p)
{
    subT[u][col[u]]++;

    for(int v : graph[u])
    {
        if(v==p) continue;

        dfs(v,u);

        if( (subT[v][1]==reds&&subT[v][2]==0) || (subT[v][1]==0&&subT[v][2]==blues) ) ans++;

        for(int c=0;c<3;c++)
        {
            subT[u][c]+=subT[v][c];
        }
    }
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>col[i];
        reds+=(col[i]==1);
        blues+=(col[i]==2);
    }

    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1,1);

    cout<<ans<<"\n";
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