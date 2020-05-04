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
const int N=1e5+5;
const int mod=1e9+7;

vector<string> st;

void displayStack() {
    for (string str : st) {
        cout<<"/"<<str;
    }
    cout<<"/\n";
}

void solve() {
    string cmd,op;
    cin>>cmd;
    if (cmd=="pwd") {
        displayStack();
    } else {
        cin>>op;
        int i=0;
        if (op[0]=='/') {
            st.clear();
        }
        while (i<op.size()) {
            if (op[i]=='/') {
                i++;
            } else if (op[i]=='.'){
                st.pop_back();
                i+=2;
            } else {
                int j=i;
                while (j<op.size() && (op[j]>='a' && op[j]<='z')) {
                    j++;
                }
                st.pb(op.substr(i,j-i));
                i=j;
            }
        }
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
    cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}