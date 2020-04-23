//simple ga alochinchu

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
    int n;
    cin>>n;

    vector<bool> vis(n+1,false);

    int a[n+1];
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        vis[a[i]]=true;
    }

    vi idxs,sry;
    for (int i=1;i<=n;i++) {
        if (!a[i]) {
            idxs.pb(i);
        }
        if (!vis[i]) {
            sry.pb(i);
        }
    }

    while(!idxs.empty()) {
        int p=idxs.size();

        if (p==2) {
            if (idxs[0]==sry[0] || idxs[1]==sry[1]) {
                swap(sry[0],sry[1]);
            }
            a[idxs[1]]=sry[1];
            a[idxs[0]]=sry[0];
            break;
        }

        if (idxs[p-1]==sry[p-1]) {
            swap(sry[p-1],sry[0]);
        }
        a[idxs[p-1]]=sry[p-1];
        idxs.pop_back();
        sry.pop_back();
    }

    for (int i=1;i<=n;i++) {
        cout<<a[i]<<" ";
    }
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
    while(t--) solve();
    return 0;
}