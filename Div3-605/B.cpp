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
    string str;
    cin>>str;

    int l=0,r=0,u=0,d=0;
    for (char c : str) {
        if(c=='R') r++;
        if(c=='L') l++;
        if(c=='U') u++;
        if(c=='D') d++;
    }

    if(min(u,d)==0 && min(l,r)) {
        cout<<"2\nLR\n";
        return;
    } else if(min(l,r)==0 && min(u,d)) {
        cout<<"2\nUD\n";
        return;
    }

    cout<<2*min(l,r)+2*min(u,d)<<"\n";

    for(int i=0;i<min(l,r);i++) {
        cout<<"L";
    }

    for(int i=0;i<min(u,d);i++) {
        cout<<"U";
    }

    for(int i=0;i<min(l,r);i++) {
        cout<<"R";
    }

    for(int i=0;i<min(u,d);i++) {
        cout<<"D";
    }

    cout<<"\n";
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
