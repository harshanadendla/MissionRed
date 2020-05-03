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
//#define s second
#define unmap unordered_map
#define mset multiset
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define dbg(x) cout<<"x "<<x<<"\n"
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e5+5;
const int mod=1e9+7;

void solve() {
    string s,t;
    cin>>s;

    map<char,bool> vis;
    map<char,vi> idxs;
    for (int i=0;i<s.size();i++) {
        idxs[s[i]].pb(i);
    }

    int ans=1,prev=-1;
    cin>>t;
    for (int i=0;i<t.size();i++) {
        if (idxs[t[i]].empty()) {
            cout<<"-1\n";
            return;
        }

        auto it=upper_bound(all(idxs[t[i]]),prev);

        if (it == idxs[t[i]].end()) {
            ans++;
            it=idxs[t[i]].begin();
        }

        prev=*it;
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
    cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}