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

const int N=2e5+5;
const int M=3e5;
const int mod=1e9+7;

void solve()
{
    int ans=LLONG_MAX;
    multiset<int> need,extra;

    int n,m;
    cin >> n >> m ;

    int have[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>have[i];
    }

    int want[m+1];
    for(int i=1;i<=m;i++)
    {
        cin>>want[i];
        for(int j=1;j<=want[i];j++)
        {
            need.insert(i);
        }
    }

    for(int l=1,r=1;r<=n;r++)
    {
        if(need.find(have[r]) != need.end())
        {
            need.erase(need.find(have[r]));
        }
        else
        {
            extra.insert(have[r]);
        }

        if(!need.empty()) continue;

        while(extra.find(have[l]) != extra.end())
        {
            extra.erase(extra.find(have[l]));
            l++;
        }

        ans=min(ans,(int)extra.size());

        if(ans==0)
        {
            cout<<"0";
            return;
        }
    }

    (ans==LLONG_MAX) ? cout<<"-1" : cout<<ans ;
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

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    cerr << "\ntime: " << 1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
    #endif

    return 0;
}