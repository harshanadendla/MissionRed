//wah..wah....intha easy idea raledu.....got ac with my own idea..but ashishgup _/\_
//chinna idea...just imagine as if u are taking out 1 k at a time as common..ante how u write in math
//if at all that particular power of k is added/used in the A....now you would see a 1 inside the bracket
//anthekada...wah _/\_

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
const int M=2e5;
const int mod=1e9+7;

void solve()
{
    int n,k;
    cin>>n>>k;
    map<int,int> m;
    for(int i=0,a;i<n;i++)
    {
        cin>>a;
        int idx=0;
        while(a>0)
        {
            m[idx++]+=a%k;
            a/=k;
        }
    }
    for(auto i : m)
    {
        if(i.s > 1)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
    cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}