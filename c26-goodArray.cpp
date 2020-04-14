//ummma...ac in 1 go...lonchem oka 5-6 min alochinchu...ull definitely get the logic
//beleive me

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
const int M=2e5;
const int mod=1e9+7;

void solve()
{
    vi ans;
    map<int,int> vis;

    int n;
    cin>>n;

    int a[n],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        vis[a[i]]++;
    }

    for(int i=0,temp;i<n;i++)
    {
        temp=sum-a[i];
        if(temp%2==0 && vis.count(temp/2))
        {
            if(temp/2 != a[i])
            {
                ans.pb(i+1);
            }
            else if(temp/2 == a[i] && vis[a[i]]>1)
            {
                ans.pb(i+1);
            }
        }
    }

    cout<<ans.size()<<"\n";
    for(int i : ans) cout<<i<<" ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    cout << "\n\ntime: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms";
    #endif

    return 0;
}