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
#define int long long
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

void solve() {
    int n,a,b;
    string str;
    cin>>n>>a>>b>>str;

    vvi dp(n+1,vi(2,1e15));
    dp[0][0]=b;

    for (int i=0;i<n;i++) {
        if (str[i]=='1') {
            dp[i+1][1]=dp[i][1]+a+2*b;
        } else {
            dp[i+1][0]=min(dp[i][0]+a,dp[i][1]+2*a)+b;
            dp[i+1][1]=min(dp[i][0]+2*a,dp[i][1]+a)+2*b;
        }
    }

    cout<<dp[n][0]<<"\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}