//ap series psbl avvalante...only 2 differences....a[1]-a[0] and (a[1]-a[0])/2...gud observation

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

set<int> ans;

void go(int dif,int* a,int n) {
	int cnt=0,mid=1e13;
	for (int i=1;i<n;i++) {
		if (a[i]-a[i-1] == dif) {
			continue;
		}
		cnt++;
		if (a[i]-a[i-1]==2*dif) {
			mid=(a[i]+a[i-1]) >> 1;
		}
	}

	if (!cnt) {
		ans.insert(a[0]-dif);
		ans.insert(a[n-1]+dif);
	} else if (cnt==1 && mid!=1e13) {
		ans.insert(mid);
	}
}

void solve() {
	int n;
	cin>>n;

	int a[n];
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}

	sort(a,a+n);

	if (n==1) {
		cout<<"-1\n";
		return;
	}

	int dif=a[1]-a[0];

	if (n==2) {
		if (!dif) {
			cout<<"1\n"<<a[0]<<"\n";
		} else if (dif%2) {
			cout<<"2\n"<<a[0]-dif<<" "<<a[1]+dif<<"\n";
		} else {
			cout<<"3\n"<<a[0]-dif<<" "<<a[0]+dif/2<<" "<<a[1]+dif<<"\n";
		}
		return;
	}

	go(dif,a,n);
	go(dif/2,a,n);

	cout<<ans.size()<<'\n';
	for (int i : ans) {
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