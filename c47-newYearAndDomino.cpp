//kotta method of dp...gud

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
const int N=1e5;
const int mod=1e9+7;

void solve()
{
    int n,m,q,ans=0;
    cin>>n>>m;

    vector<vector<char>> a(n+1,vector<char>(m+1));

    int h[n+1][m+1],v[n+1][m+1];

    mem(h,0);
    mem(v,0);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            h[i][j]=h[i-1][j]+h[i][j-1]-h[i-1][j-1];
            v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
            if(a[i][j]=='.' && a[i][j-1]=='.') h[i][j]++;
            if(a[i][j]=='.' && a[i-1][j]=='.') v[i][j]++;
        }
    }

    cin>>q;
    for(int i=1,r1,c1,r2,c2;i<=q;i++)
    {
        ans=0;
        cin>>r1>>c1>>r2>>c2;
        ans+=h[r2][c2]-h[r2][c1]-h[r1-1][c2]+h[r1-1][c1];
        ans+=v[r2][c2]-v[r1][c2]-v[r2][c1-1]+v[r1][c1-1];
        cout<<ans<<"\n";
    }
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