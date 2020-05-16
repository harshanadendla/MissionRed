//whenever strange func is given....think the max values it can contain
//think where it ends as per input
//get more string at n^2 bruteforce loops

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
const int INF=3e16;

int Madd(int a,int b) {
    return ((a%mod)+(b%mod)+mod)%mod;
}

int Mmull(int a,int b) {
    return ((a%mod)*(b%mod)+mod)%mod;
}

//#define test_cases

pii ori,aroma;
int ax,ay,bx,by,t;
vpii a;
int n;

int dist(pii p,pii q) {
	return abs(p.f-q.f)+abs(p.s-q.s);
}

void solve() {
	cin>>ori.f>>ori.s>>ax>>ay>>bx>>by>>aroma.f>>aroma.s>>t;
	int dx=ori.f,dy=ori.s;
	while (dx<=INF && dy<=INF) {
		a.pb(mp(dx,dy));
		n++;
		dx=ax*dx+bx;
		dy=ay*dy+by;
	}
	int ans=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (dist(aroma,a[i])+dist(a[i],a[j]) <= t) {
				ans=max(ans,abs(j-i)+1);
			}
		}
	}
	cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
#ifdef Harsha
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