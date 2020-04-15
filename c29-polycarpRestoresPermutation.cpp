//malli anthe....idea ochindi..but not thinking like a red coder....edges and invalid conditions and operations
//pattinchukovatla

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
    int a;
    int sum=0,sumHere=0;

    int n;
    cin>>n;

    int dif[n-1];
    for(int i=0;i<n-1;i++)
    {
        cin>>dif[i];
        sumHere+=dif[i];
        sum+=sumHere;
    }

    int sumN=(n*(n+1))/2;

    if((sumN-sum)%n)
    {
        cout<<"-1";
        return;
    }

    a=(sumN-sum)/n;

    map<int,int> check;
    vi ans;
    ans.pb(a);
    for(int i=0;i<n-1;i++)
    {
        a+=dif[i];
        if(a>n)
        {
            cout<<"-1";
            return;
        }
        check[a]++;
        if(check[a]>1)
        {
            cout<<"-1";
            return;
        }
        ans.pb(a);
    }

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