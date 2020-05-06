//not thinking like a redCoder

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
const int N=2e5+5;
const int mod=1e9+7;

string s1=".",s2=".";
int a[N],mark[N],n,m;

bool check(int mid) {
    for (int i=1;i<=n;i++) {
        mark[i]=1;
    }
    for (int i=1;i<=mid;i++) {
        mark[a[i]]=0;
    }
    int ptr=1;
    for (int i=1;i<=n;i++) {
        if (mark[i]) {
            if (s1[i] == s2[ptr]) {
                ptr++;
            }
        }
    }
    return ptr>m;
}

void solve() {
    string t1,t2;
    cin>>t1>>t2;
    s1+=t1;
    s2+=t2;
    n=s1.size();
    m=s2.size();
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }

    int l=0,r=n;
    while (l<r) {
        int mid=(l+r+1)/2;
        if (check(mid)) {
            l=mid;
        } else {
            r=mid-1;
        }
    }

    cout<<l<<'\n';
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
