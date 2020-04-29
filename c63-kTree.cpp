//close...chala close....just what is unique kanipettala...dp[prev][n] anukunna....but that is wrong
//learnt a lesson...dp state unique aa kada choodali....ikkada dp state is dp[n][isTaken]

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
#define dbg(x) cout<<"x "<<x<<"\n"
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=105;
const int mod=1e9+7;

int k,d,dp[N][N];

int Madd(int a,int b) {
	return ((a%mod)+(b%mod))%mod;
}

int go(int n,bool flag) {
	if (n==0) {
		return flag;
	}

	if (dp[n][flag] != -1) {
		return dp[n][flag];
	}

	int res=0;
	for (int i=1;i<=k;i++) {
		if (n-i>=0) {
			res=Madd(res,go(n-i,(i>=d)||flag));
		}
	}

	return dp[n][flag]=res;
}

void solve() {
	mem(dp,-1);

	int n;
	cin>>n>>k>>d;

	cout<<go(n,false)<<'\n';
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