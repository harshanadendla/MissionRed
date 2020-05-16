//\_/...test cases check cheyyala...else easy prob ee

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

template<size_t>
struct debug{};

template <class T>
ostream& print_tuple(ostream& out, const T& t, debug<1> ) {
    return out << get<tuple_size<T>::value-1>(t);
}

template <class T, size_t idx>
ostream& print_tuple(ostream& out, const T& t, debug<idx> ) {
    out << get< tuple_size<T>::value-idx >(t) << " , ";
    return print_tuple(out, t, debug<idx-1>());
}

template <class... Args>
ostream& operator<<(ostream& out, const tuple<Args...>& t) {
    out << "\n[";
    print_tuple(out, t, debug<sizeof...(Args)>());
    return out << "]\n";
}

template<class T>
using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define endl '\n'
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
#define dbg(x) cerr<<x<<"\n"
#define bug(x) cout<<"hi"<<x<<endl

const int N=1e5+5;
const int mod=1e9+7;

int Madd(int a,int b) {
    return ((a%mod)+(b%mod)+mod)%mod;
}

int Mmull(int a,int b) {
    return ((a%mod)*(b%mod)+mod)%mod;
}

//#define test_cases

void solve() {
	int n,k,x,y=1;
	cin>>n>>k>>x;
	for (int i=0;i<k;i++) {
		y*=x;
	}
	int a[n];
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}
	vi pref(n,0),suf(n,0);
	for (int i=1;i<n;i++) {
		pref[i]=pref[i-1]|a[i-1];
	}
	for (int i=n-2;i>=0;i--) {
		suf[i]=suf[i+1]|a[i+1];
	}
	int ans=0;
	for (int i=0;i<n;i++) {
		ans=max(ans,pref[i]|(a[i]*y)|suf[i]);
	}
	cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif

    int t=1;
#ifdef test_cases
    cin>>t;
#endif

    while(t--) {
        solve();
    }

    return 0;
}