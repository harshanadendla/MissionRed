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

const int N=1005;
const int M=3e5;
const int mod=1e9+7;

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int n,m,drew;
string str[N];
vpii stars;
unmap<pii,int,hash_pair> ans;
set<pii> minStars;
vector<vector<bool>> vis(N,vector<bool>(N,false));

void mark(int i,int j,int k)
{
    int check=0;

    if(i-k>=0 && str[i-k][j]=='*') check++;
    if(i+k<n && str[i+k][j]=='*') check++;
    if(j+k<m && str[i][j+k]=='*') check++;
    if(j-k>=0 && str[i][j-k]=='*') check++;

    if(check<4)
    {
        return;
    }
    else
    {
        vis[i][j]=true;
        vis[i-k][j]=true;
        vis[i+k][j]=true;
        vis[i][j+k]=true;
        vis[i][j-k]=true;

        minStars.insert(mp(i,j));
        ans[mp(i,j)]=k;
        mark(i,j,k+1);
    }
}

void solve()
{

    cin>> n >> m ;

    for(int i=0;i<n;i++)
    {
        cin>> str[i] ;
    }

    if(str[0][0]=='*' || str[0][0]=='*' || str[0][0]=='*' || str[0][0]=='*')
    {
        cout<<"-1";
        return;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='*') stars.pb(mp(i,j));
        }
    }

    for(pii p : stars)
    {
        mark(p.f,p.s,1);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]) 
            {
                drew++;
            }
        }
    }

    if(drew != stars.size())
    {
        cout<<"-1";
        return;
    }

    cout<<minStars.size()<<"\n";
    for(auto it : minStars)
    {
        cout<<it.f+1<<" "<<it.s+1<<" "<<ans[it]<<"\n";
    }
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