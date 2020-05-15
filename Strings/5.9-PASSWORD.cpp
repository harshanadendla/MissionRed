//no..not there still...not thinking like a red coder
//baddakam kooda kadu....negligance

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

void kmpPre(vi &lps,string str) {
	int idx=0,i=1,n=str.size();
	while (i<n) {
		if (str[idx]==str[i]) {
			lps[i]=idx;
			i++;
			idx++;
		} else {
			if (idx>0) {
				idx=lps[idx-1]+1;
			} else {
				i++;
			}
		}
	}
	return;
}

void solve() {
	string str;
	cin>>str;
	int n=str.size();
	vi lps(n,-1);
	kmpPre(lps,str);
	int x=lps.back();
	if (x==-1) {
		cout<<"Just a legend"<<endl;
		return;
	}
	for (int i=1;i<n-1;i++) {
		if (lps[i]==x) {
			cout<<str.substr(0,x+1);
			return;
		}
	}
	if (lps[x]==-1) {
		cout<<"Just a legend"<<endl;
		return;
	} else {
		for (int i=0;i<=lps[x];i++) {
			cout<<str[i];
		}
		return;
	}
	cout<<"Just a legend"<<endl;
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
