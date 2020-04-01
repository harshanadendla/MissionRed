//gud...inkonchem teliviga munde alochinchli...what works for optimal answer ani...and implementation bane idea ochindi

/*
	YES PAIN YES GAIN
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define un_map unordered_map
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
#define idx indexes[max_ele]

const int N=2e5+5;
const int M=3e5;
const int mod=1e9+7;

vi indexes[N];

void solve()
{
	vector<pair<int,pii>> ops;
	int n,steps=0,maxval=LLONG_MIN;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		indexes[a[i]].pb(i);
		maxval=max(maxval,a[i]);
	}
	
	int max_ele=a[0];
	for(int i=0;i<=maxval;i++)
	{
		if(indexes[i].size()>indexes[max_ele].size()) max_ele=i;
	}

	int id=idx[0];
	for(int i=id+1;i<n;i++)
	{
		if(a[i]==a[i-1]) continue;
		(a[i]<a[i-1]) ? ops.pb(mp(1,mp(i+1,i))) : ops.pb(mp(2,mp(i+1,i))) ;
		a[i]=max_ele;
	}

	for(int i=id-1;i>=0;i--)
	{
		if(a[i]==a[i+1]) continue;
		(a[i]<a[i+1]) ? ops.pb(mp(1,mp(i+1,i+2))) : ops.pb(mp(2,mp(i+1,i+2))) ;
		a[i]=max_ele;
	}

	cout<<n-idx.size()<<"\n";
	for(auto it : ops)
	{
		cout<<it.f<<" "<<it.s.f<<" "<<it.s.s<<"\n";
	}
}

int32_t main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t=1;
	//cin>>t;

	while(t--)
	{
		solve();
	}

	return 0;
}