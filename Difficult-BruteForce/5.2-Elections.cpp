//vammo...1 day tinnadi..clearly difs div2 and div1

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
#define dbg(x) cout<<#x<<" "<<x<<"\n"
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=3e3+5;
const int mod=1e9+7;

vi bribes[N];

void solve() {
    int n,m;
    cin>>n>>m;

    for (int i=0,p,c;i<n;i++) {
        cin>>p>>c;
        bribes[p-1].pb(c);
    }

    for (int i=0;i<m;i++) {
        sort(all(bribes[i]));
    }

    int ans=LLONG_MAX;
    for (int votes=1;votes<=n;votes++) {
        int cur=0;
        int need=votes-(bribes[0].size());
        vi v;
        for (int i=1;i<m;i++) {
            int idx=max(0ll,(int)bribes[i].size()-(votes-1));
            for (int j=0;j<idx;j++) {
                cur+=bribes[i][j];
                need--;
            }
            for (int j=idx;j<bribes[i].size();j++) {
                v.pb(bribes[i][j]);
            }
        }
        if (need > 0) {
            sort(all(v));
            for (int j=0;j<need;j++) {
                cur+=v[j];
            }
        }
        ans=min(ans,cur);
    }

    cout<<ans<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}
