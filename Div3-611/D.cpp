//approach...i dont know i am close...what i thought is...until ppl size reaches size of m
//keep traversing in all array elements with i...i form 1 to SO-ON
//idi gave tle
//editorial...did bfs...oka qu petti....checked for existance in a map dist(<int,int>)
//smtng like level order traversal chesaru.....deeni name is multi-score bfs ta \__/

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
    int n,m;
    cin>>n>>m;

    map<int,int> dist;
    queue<int> q;

    for (int i=0,a;i<n;i++) {
        cin>>a;
        dist[a]=0;
        q.push(a);
    }

    int cost=0;
    vi res;

    while(!q.empty()) {
        if (res.size() == m) {
            break;
        }

        int x=q.front();
        q.pop();

        if (dist[x]) {
            cost+=dist[x];
            res.pb(x);
        }

        if (!dist.count(x-1)) {
            dist[x-1]=dist[x]+1;
            q.push(x-1);
        }
        if (!dist.count(x+1)) {
            dist[x+1]=dist[x]+1;
            q.push(x+1);
        }
    }

    cout<<cost<<"\n";
    for (int i : res) {
        cout<<i<<" ";
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

    while(t--) {
        solve();
    }

    return 0;
}
