//gud....but testing cheyyatla..before submission..that is what u have seem yesterday in endagorian's video

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

string lhs;
bool vis[30];
set<int> graph[30];

void dfs(int u) {
    lhs+=('a'+u);
    vis[u]=false;

    for (int v : graph[u]) {
        if (vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    string str;
    cin>>str;

    if (str.size()==1) {
        cout<<"YES\n"<<str;
        for (char c='a';c<='z';c++) {
            if (c != str[0]) {
                cout<<c;
            }
        }
        cout<<"\n";
        return;
    }

    mem(vis,0);
    for (int i=0;i<30;i++) {
        graph[i].clear();
    }

    set<int> psw;
    for (int i=0;i<str.size()-1;i++) {
        int l=str[i]-'a',r=str[i+1]-'a';

        graph[l].insert(r);
        graph[r].insert(l);

        if (graph[l].size()>2 || graph[r].size()>2) {
            cout<<"NO\n";
            return;
        }

        vis[l]=true;
        vis[r]=true;

        psw.insert(l);
        psw.insert(r);
    }

    string rhs="";
    for (int i=0;i<26;i++) {
        if (!vis[i]) {
            rhs+=('a'+i);
        }
    }

    int idx=-1;
    for (int i : psw) {
        if (graph[i].size()==1) {
            idx=i;
            break;
        }
    }

    if (idx==-1) {
        cout<<"NO\n";
        return;
    }

    lhs="";
    dfs(idx);

    cout<<"YES\n"<<lhs+rhs<<"\n";
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
    while(t--) solve();
    return 0;
}