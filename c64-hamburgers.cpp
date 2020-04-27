//nice binSarch application

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
//#define pb push_back
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
    string str;
    int n[3],p[3],money;

    cin>>str;
    for (int i=0;i<3;i++) {
        cin>>n[i];
    }
    for (int i=0;i<3;i++) {
        cin>>p[i];
    }
    cin>>money;

    vi need(3,0);
    for (char c : str) {
        if (c=='B') {
            need[0]++;
        } else if (c=='S') {
            need[1]++;
        } else {
            need[2]++;
        }
    }

    int ans=LLONG_MIN;
    int l=0,r=1e13;
    while(l<=r) {
        int m=l+(r-l)/2;

        int res=0;
        for (int i=0;i<3;i++) {
            res+=max(0ll,p[i]*(m*need[i]-n[i]));
        }

        if (res<=money) {
            ans=max(ans,m);
            l=m+1;
        } else {
            r=m-1;
        }
    }

    cout<<ans;
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